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

namespace Acme {

public class TypeRef : HyperLink {

    private String _typeName = "";
    private String _namespace = "";
    private String _class = "";

    // default to System.Web
    private String _assembly = "System.Web, Version=2.0.3600.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a";

    public String TypeName {
        get {
            return _typeName;
        }
        set {
            _typeName = value;

           int index = _typeName.LastIndexOf(".") + 1;
           _class = _typeName.Substring(index, _typeName.Length - index);
           _namespace = _typeName.Substring(0, index - 1);
        }
    }

    public String Assembly {
        get {
            return _assembly;
        }
        set {
            _assembly = value;
        }
    }

    public String GetUrl() {
        return String.Format("~/util/classbrowser.aspx?assembly={0}&namespace={1}&class={2}", Page.Server.UrlEncode(_assembly), Page.Server.UrlEncode(_namespace), Page.Server.UrlEncode(_class));
    }

    protected override void OnPreRender(EventArgs e) {
       this.NavigateUrl = GetUrl();
       Style.Add("color","black");
       Style.Add("text-decoration","none");
       base.OnPreRender(e);
    }

    public override void RenderEndTag(HtmlTextWriter writer) {

       Image img = new Image();
       img.ImageAlign = ImageAlign.Bottom;
       img.ImageUrl = "~/images/class.gif";
       Controls.Add(img);


       img.RenderControl(writer);
       base.RenderEndTag(writer);
    }

}

}
