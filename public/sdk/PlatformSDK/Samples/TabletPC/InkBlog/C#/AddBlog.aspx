<%@ Page language="c#" Codebehind="AddBlog.aspx.cs" Src="AddBlog.aspx.cs" AutoEventWireup="false" Inherits="InkBlog.AddBlog" %>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN" >

<!-- ----------------------------------------------------------------------- -->
<!--                                                                         -->
<!--  This is part of the Microsoft Tablet PC Platform SDK                   -->
<!--  Copyright (C) 2004 Microsoft Corporation                               -->
<!--  All rights reserved.                                                   -->
<!--                                                                         -->
<!--  This source code is only intended as a supplement to the               -->
<!--  Microsoft Tablet PC Platform SDK Reference and related electronic      --> 
<!--  documentation provided with the Software Development Kit.              -->
<!--  See these sources for more detailed information.                       -->
<!--                                                                         -->
<!--  File: AddBLog.aspx                                                     -->
<!--  ASP.NET page that enables the user to submit new blog data.            -->
<!--                                                                         -->
<!--  Displays user input areas for the blog title and body, as well as a    -->   
<!--  button to submit the data to the server.  The input area uses          -->
<!--  the InkArea Winforms control included with this sample;  this control  -->
<!--  enables inking if it is supported and text input otherwise.            -->
<!--                                                                         -->
<!-- ----------------------------------------------------------------------- -->

<HTML>
    <script language="jscript">

        // Helper function that extracts the blog data from the
        // form and posts the result to the server.
        function AddBlog() 
        {

            // Extract the blog's title data as ink and text
            form.BlogTitleText.value  = inkBlogTitle.TextData;
            
            // Extract the blog's body data as ink and text
            form.BlogBodyText.value = inkBlogBody.TextData;
            form.BlogBodyInkData.value = inkBlogBody.InkData;   

            form.submit();

        }

        // Helper function that releases resources held by the
        // ink controls
        function OnUnload()
        {        
            inkBlogTitle.DisposeResources();        
            inkBlogBody.DisposeResources();
        }

    </script>
    <HEAD>
        <title>AddBlog</title>
        <meta name="GENERATOR" Content="Microsoft Visual Studio 7.0">
        <meta name="CODE_LANGUAGE" Content="C#">
        <meta name="vs_defaultClientScript" content="JavaScript">
        <meta name="vs_targetSchema" content="http://schemas.microsoft.com/intellisense/ie5">
    </HEAD>
    <body onunload="OnUnload()" >
        <OBJECT id="inkBlogTitle" classid="InkBlogControls.dll#InkBlog.InkArea" width="400" height="48" VIEWASTEXT>
        </OBJECT>
        <br/>
        <OBJECT id="inkBlogBody" classid="InkBlogControls.dll#InkBlog.InkArea" width="400" height="296" VIEWASTEXT>
        </OBJECT>
        <br/>
        <button id="BUTTON1" type="button" onclick="AddBlog()">Add Blog</button>
        <form id="form" name="form" action="AddBlog.aspx" method="post">
            <input type="hidden" name="BlogTitleText" id="BlogTitleText"> 
            <input type="hidden" name="BlogBodyText" id="BlogBodyText">
            <input type="hidden" name="BlogBodyInkData" id="BlogBodyInkData">
        </form>
    </body>
</HTML>
