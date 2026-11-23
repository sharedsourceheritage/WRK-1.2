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
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;

namespace Microsoft.Sample.WebParts
{
  public class TextDisplayWebPart : WebPart
  {
    // Constructor
    public TextDisplayWebPart()
    {
      this.AllowClose = false;
      this.Title = "Text Display Web Part";
    }

    // Fields - Private
    private string _ContentText = "This Web Part Display Text in this area";
    private int _MaxLength = -1;

    //Properties
    [WebBrowsable]
    [Personalizable]
    public string ContentText
    {
      get
      {
        if (_MaxLength == -1)
          return _ContentText;
        else if (_MaxLength > 0)
          return _ContentText.Substring(0, _MaxLength);
        else
          return (String.Empty);
      }
      set { _ContentText = value; }
    }

    [Personalizable(PersonalizationScope.Shared)]
    public int MaxTextDisplayLength
    {
      get { return _MaxLength; }
      set { _MaxLength = value; }
    }

    public override bool AllowClose
    {
      get { return false; }
      set { ;}
    }
    public override bool AllowMinimize
    {
      get { return false; }
      set { ;}
    }

    // Methods
    protected override void CreateChildControls()
    {
      Controls.Clear();
      Label DisplayContent = new Label();
      DisplayContent.Text = this.ContentText;
      this.Controls.Add(DisplayContent);
      ChildControlsCreated = true;
    }
    public override WebPartVerbCollection Verbs
    {
      get
      {
        EnsureChildControls();
        WebPartVerb saveVerb = new WebPartVerb("save", new WebPartEventHandler(SaveData));
        saveVerb.Text = "save";
        WebPartVerb[] newVerbs = new WebPartVerb[] { saveVerb };
        WebPartVerbCollection wp = new WebPartVerbCollection(base.Verbs, newVerbs);
        return wp;
      }
    }

    public void SaveData(object sender, WebPartEventArgs args)
    {
      EnsureChildControls();
      this.Title = this.Title + " Saved ..";
    }


    EditorPartCollection IWebEditable.CreateEditorParts()
    {
      if (this.WebPartManager.Personalization.Scope == PersonalizationScope.User && this.IsShared == true)
        return (new EditorPartCollection());
      else
      {
        // This editor Part will only display on ShareMode
        EditorPartCollection editorPartCollection = new EditorPartCollection();
        editorPartCollection.Add(new Sample.WebParts.TextDisplayEditorPart());
        return editorPartCollection;
      }
    }

    object IWebEditable.WebBrowsableObject
    {
      get { return this; }
    }

    [ConnectionConsumer("TextConsumer1", "Text Consumer")]
    public void GetItextProvider(Sample.WebParts.ITextCommunication myInterface)
    {
      if (myInterface != null)
        ContentText = myInterface.Text;
    }

  }
}