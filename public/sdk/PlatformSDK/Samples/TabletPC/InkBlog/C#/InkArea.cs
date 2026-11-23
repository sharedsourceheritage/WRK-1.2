//-------------------------------------------------------------------------
//
//  This is part of the Microsoft Tablet PC Platform SDK
//  Copyright (C) 2004 Microsoft Corporation
//  All rights reserved.
//
//  This source code is only intended as a supplement to the
//  Microsoft Tablet PC Platform SDK Reference and related electronic 
//  documentation provided with the Software Development Kit.
//  See these sources for more detailed information. 
//
//  File: InkArea.cs
//  Simple control that accepts either ink or text input, depending
//  on the capabilities of the user's machine.
//
//  This control checks whether the client's machine is ink-enabled.
//  If so, it uses an InkCollector attached to a Panel for ink 
//  collection.  Otherwise, it defaults to using a textbox.
//
//  The features used are: InkCollector, handwriting recognition, and
//  ink serialization.
//
//--------------------------------------------------------------------------

using System;
using System.Diagnostics;
using System.IO;
using System.Windows.Forms;

// The Ink namespace, which contains the Tablet PC Platform API
using Microsoft.Ink;

namespace InkBlog
{

    /// <summary>
    /// The InkArea Sample Control class
    /// </summary>
    public class InkArea : UserControl
    {

        // Declare the control used for collecting blog input
        private Control inputArea = null;

        // Declare the InkCollector used for collecting blog
        // input when the client's machine is ink-enabled.
        private object inkCollector = null;

        #region Standard Template Code
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;
        #endregion

        public InkArea()
        {
            #region Standard Template Code
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();
            #endregion

            // Attempt to create an InkCollector and attach it to
            // a Panel control.  If successful, this client can 
            // support inking within a web page.  Otherwise, use a
            // Textbox for collecting blog input.
            try
            {
                inputArea = CreateInkCollectionSurface();
            }
            catch (FileNotFoundException)
            { 
                inputArea = new TextBox();
                ((TextBox)inputArea).Multiline = true;
            }

            inputArea.Size = this.Size;

            // Add the control used for collecting blog input
            this.Controls.Add(inputArea);

        }

        #region Standard Template Code
        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        protected override void Dispose( bool disposing )
        {
            if( disposing )
            {
                if(components != null)
                {
                    components.Dispose();
                }
            }
            base.Dispose( disposing );
        }
        #endregion

        #region Component Designer generated code
        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.SuspendLayout();
            this.Name = "InkArea";
            this.ResumeLayout(false);
        }
        #endregion
        
        /// <summary>
        /// Event hander from this control's Resize event
        /// Updates the child control to have the same size.
        /// </summary>
        /// <param name="e"></param>
        protected override void OnResize(EventArgs e)
        {
            if (null != inputArea)
            {
                inputArea.Size = this.Size;
            }
        }
        

        /// <summary>
        /// Indicates whether inking is supported on the client machine.
        /// </summary>
        /// <returns>Returns true if inking is supported and false otherwise.</returns>
        public bool InkEnabled
        {
            get
            {
                return inkCollector != null;
            }
        } 

        /// <summary>
        /// If inking is supported, returns the serialized ink data.
        /// Otherwise, returns an empty string.
        /// </summary>
        public string InkData 
        {
            get 
            {
                if (InkEnabled) 
                {
                    return SerializeInkData();
                }
                else
                {
                    return String.Empty;
                }
            }
        } 
       
        /// <summary>
        /// If inking is supported, returns the recognized ink.
        /// Otherwise, returns the contents of the text box.
        /// </summary>
        public string TextData
        {
            get
            {
                if (InkEnabled) 
                {
                    return RecognizeInkData();
                }
                else
                {
                    return ((TextBox)inputArea).Text;
                }
            }
        } 

        /// <summary>
        /// Disposes of the internal child control used for collecting ink.
        /// </summary>
        public void DisposeResources()
        {
            if (InkEnabled)
            {
                ((InkCollector)inkCollector).Dispose();
            }
        }
        

        #region Helper Methods (private)

        /// <summary>
        /// Attempts to create an InkCollector and attach it to a
        /// Panel control.  If unable to create the InkCollector, 
        /// an exception is thrown.
        /// </summary>
        /// <returns>Control to be used for this inking area</returns>
        protected Control CreateInkCollectionSurface()
        {
            try
            {
                Panel inkPanel = new Panel();
                inkPanel.BorderStyle = BorderStyle.Fixed3D;
                inkCollector = new InkCollector(inkPanel);
                ((InkCollector)inkCollector).Enabled = true;
                return inkPanel;
            }
            catch
            {
                throw;
            }
        }

        /// <summary>
        /// Serializes the ink data as GIF using a Base 64 string.
        /// </summary>
        /// <returns>Ink data as a GIF using a Base 64 string</returns>
        protected String SerializeInkData()
        {
            Debug.Assert(InkEnabled, null, "Client must be ink-enabled");

            // Obtain the ink associated with this control
            Ink ink = ((InkCollector)inkCollector).Ink;

            // Serialize the ink
            if (ink.Strokes.Count > 0) 
            {
                byte[] inkDataBytes = ink.Save(PersistenceFormat.Gif);
                return Convert.ToBase64String(inkDataBytes);
            }

            // Default to returning the empty string.
            return String.Empty;
        }

        /// <summary>
        /// Recognize ink data using the default recognizer.
        /// </summary>
        /// <returns>The string containing the top recognition result.</returns>
        protected String RecognizeInkData()
        {
            Debug.Assert(InkEnabled, null, "Client must be ink-enabled");

            // Obtain the ink associated with this control
            Ink ink = ((InkCollector)inkCollector).Ink;

            if (ink.Strokes.Count > 0) 
            {

                // Attempt to create a recognition context and use it to
                // retrieve the top alternate.
                try 
                {
                    RecognizerContext recognizerContext = new RecognizerContext();
                    RecognitionStatus recognitionStatus;
                    recognizerContext.Strokes = ink.Strokes;
                    RecognitionResult recognitionResult = recognizerContext.Recognize(out recognitionStatus);
                    if ( ( recognitionStatus == RecognitionStatus.NoError ) && 
                         ( null != recognitionResult) ) 
                    {
                        return recognitionResult.TopString;
                    }
                }
                catch (Exception)
                {
                    // An exception will occur if the client does not have
                    // any handwriting recognizers installed on their system.
                    // In this case, we default to returning an empty string. 
                }
            }

            return String.Empty;
        }

        #endregion 
    }
}
