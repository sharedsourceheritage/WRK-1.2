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
using System.Web;
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
    private string _ContentText = "This Web Part displays text in this area.";

    //Properties
    [WebBrowsable]
    [Personalizable]
    public string ContentText
    {
      get { return _ContentText; }
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

  }
}