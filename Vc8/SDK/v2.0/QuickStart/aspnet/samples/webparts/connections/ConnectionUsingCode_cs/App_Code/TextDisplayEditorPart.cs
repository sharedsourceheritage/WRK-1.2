//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------
using System;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;

namespace Microsoft.Sample.WebParts
{
    public class TextDisplayEditorPart : EditorPart
    {
        public TextDisplayEditorPart()
        {
            this.Title = "Text Editor Part" ;
        }

        TextBox PartPropertyValue ;
        bool _displayErrorMessage = false;


        protected override void CreateChildControls()
        {
            Controls.Clear();
            PartPropertyValue = new TextBox();
            this.Controls.Add(PartPropertyValue);
        }

        public override void SyncChanges()
        {
            EnsureChildControls();
            TextDisplayWebPart tp = WebPartToEdit as TextDisplayWebPart;
            if (tp != null)
            {
                PartPropertyValue.Text = Convert.ToString(tp.MaxTextDisplayLength);
            }
        }

        protected override void RenderContents(HtmlTextWriter writer)
        {
            writer.AddAttribute(HtmlTextWriterAttribute.Border, "0");
            writer.AddAttribute(HtmlTextWriterAttribute.Cellspacing, "4");

            writer.RenderBeginTag(HtmlTextWriterTag.Table);
            writer.RenderBeginTag(HtmlTextWriterTag.Tr);
            writer.RenderBeginTag(HtmlTextWriterTag.Td);

            writer.Write("Text Length :");
            writer.WriteBreak();
            this.PartPropertyValue.RenderControl(writer);

            if (_displayErrorMessage)
            {
                writer.WriteBreak();
                Label errorMessage = new Label();
                errorMessage.Text = "Error converting type";
                errorMessage.ApplyStyle(this.Zone.ErrorStyle);
                errorMessage.RenderControl(writer);
            }

            writer.RenderEndTag();  // Td
            writer.RenderEndTag();  // Tr
            writer.RenderEndTag();  // Table
        }

        public override bool ApplyChanges()
        {
            EnsureChildControls();
            TextDisplayWebPart tp = WebPartToEdit as TextDisplayWebPart;
            if (tp != null && !String.IsNullOrEmpty(PartPropertyValue.Text))
            {
                try
                {
                    tp.MaxTextDisplayLength = Convert.ToInt32(PartPropertyValue.Text);
                }
                catch
                {
                    _displayErrorMessage = true;
                    return false;
                }
            }
            return true;
        }
    }
}