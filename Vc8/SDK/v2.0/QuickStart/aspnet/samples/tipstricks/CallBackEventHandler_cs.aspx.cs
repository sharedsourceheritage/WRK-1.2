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

public partial class CallBackEventHandler_cs : System.Web.UI.Page, ICallbackEventHandler
{
    private string _callbackResult;

    private void Page_Load(object source, EventArgs e)
    {
        String callBack = Page.ClientScript.GetCallbackEventReference(this, "arg", "ClientCallback", "context", "ClientCallbackError", false);
        String clientFunction = "function GetChildren(arg, context){ " + callBack + "; }";
        Page.ClientScript.RegisterClientScriptBlock(this.GetType(), "GetChildren", clientFunction, true);

        if (Page.IsPostBack && !Page.IsCallback)
        {
            Label1.Text = "You Selected: " + Request.Form["ParentDropDown"] + ": " + Request.Form["ChildDropDown"];
        }
    }

    public string GetCallbackResult()
    {        
        return _callbackResult;
    }

    public void RaiseCallbackEvent(string eventArgument)
    {
        switch (eventArgument)
        {
            case "Item 1":
                _callbackResult = "One|Two|Three";
                break;
            case "Item 2":
                _callbackResult = "Four|Five|Six";
                break;
            case "Item 3":
                _callbackResult = "Seven|Eight|Nine";
                break;
            default:
                _callbackResult = "";
                break;
        }
    }

}