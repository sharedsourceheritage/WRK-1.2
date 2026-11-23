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
using System.Collections.Generic;
using System.Web;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;

namespace Microsoft.Sample.WebParts
{
  public class TextDisplayWebPart : WebPart, IWordCount
  {
    // Constructor
    public TextDisplayWebPart()
    {
      this.AllowClose = false;
      this.Title = "Text Display Web Part";
    }

    // Fields - Private
    private string _ContentText = "This Web Part displays text in this area.";
    private int _MaxLength = -1;
    ITextCommunication _provider = null;


    //Properties
    [Personalizable(PersonalizationScope.Shared)]
    public int MaxTextDisplayLength
    {
      get { return _MaxLength; }
      set { _MaxLength = value; }
    }

    [WebBrowsable]
    [Personalizable]
    public string ContentText
    {
      get
      {
        if (MaxTextDisplayLength == -1 || MaxTextDisplayLength >= _ContentText.Length)
          return _ContentText;
        else if (MaxTextDisplayLength > 0)
          return _ContentText.Substring(0, MaxTextDisplayLength - 1);
        else
          return (String.Empty);
      }
      set { _ContentText = value; }
    }

    public override bool AllowMinimize
    {
      get { return false; }
      set { ;}
    }

    // Methods
    protected override void RenderContents(System.Web.UI.HtmlTextWriter writer)
    {
      string encodedString = HttpUtility.HtmlEncode(this.ContentText);
      writer.Write(encodedString);
    }

    public override WebPartVerbCollection Verbs
    {
      get
      {
        WebPartVerb saveVerb = new WebPartVerb("save", new WebPartEventHandler(SaveData));
        saveVerb.Text = "save";
        WebPartVerb[] newVerbs = new WebPartVerb[] { saveVerb };
        WebPartVerbCollection wp = new WebPartVerbCollection(base.Verbs, newVerbs);
        return wp;
      }
    }

    public void SaveData(object sender, WebPartEventArgs args)
    {
      this.Title = this.Title + " Saved ..";
    }

    public override EditorPartCollection CreateEditorParts()
    {
      List<EditorPart> customEditorPartCollection = new List<EditorPart>();
      customEditorPartCollection.Add(new Sample.WebParts.TextDisplayEditorPart());
      EditorPartCollection editorPartCollection = new EditorPartCollection(customEditorPartCollection);
      return editorPartCollection;
    }

    public override object WebBrowsableObject
    {
      get { return this; }
    }

    [ConnectionConsumer("Text Consumer")]
    public void GetInterfaceForConnection(ITextCommunication provider)
    {
      _provider = provider;
    }

    protected override void OnPreRender(EventArgs e)
    {
      if (_provider != null)
        this.ContentText = _provider.Text;
    }



    public int WordCount
    {
      get { return this.ContentText.Length; }
    }

    [ConnectionProvider("Word Count Provider", "WordCountProvider")]
    public IWordCount GetInterfaceForConnection()
    {
      return this;
    }



  }
}