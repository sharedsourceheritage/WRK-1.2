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

/// <summary>
/// Summary description for SiteMapResolveEventHandler
/// </summary>
public class PathExpansionHandler
{
	public static SiteMapNode ExpandPath(Object sender, SiteMapResolveEventArgs e)
	{
        //Obtain a reference to the current node and its ancestors
        SiteMapNode nodeCopy = SiteMap.CurrentNode.Clone(true);

        //The temporary node is used for walking up the chain of nodes, fixing up Urls and
        //other properties along the way.
        SiteMapNode tempNode = nodeCopy;

        //Check if there is a newsgroup type in the query string
        string typeID = null;
		string typeIDUrlEncoded = null;
		if (!String.IsNullOrEmpty(e.Context.Request.QueryString["type"]))
        {
			typeID = e.Context.Server.HtmlEncode(e.Context.Request.QueryString["type"]);
			typeIDUrlEncoded = e.Context.Server.UrlEncode(e.Context.Request.QueryString["type"]);
        }

        //First perform Url fixups for the postings page
        //If there is a posting ID in the query string, then we know the current node
        //is the postings page.
		if (!String.IsNullOrEmpty(e.Context.Request.QueryString["postingID"]))
        {
			string postingID =
				e.Context.Server.HtmlEncode(e.Context.Request.QueryString["postingID"]);
			string postingIDUrlEncoded =
				e.Context.Server.UrlEncode(e.Context.Request.QueryString["postingID"]);

			string newUrl = tempNode.Url + "?type=" + typeIDUrlEncoded + "&postingID=" + postingIDUrlEncoded;
            string newTitle = tempNode.Title + ": " + postingID;

            tempNode.Url = newUrl;
            tempNode.Title = newTitle;

            //Walkup one level to the parent
            tempNode = tempNode.ParentNode;
        }

        //Next, perform fixups for the newsgroup page
        //By this point the nodeCopy variable is pointing at the newsgroup node
		if (!String.IsNullOrEmpty(e.Context.Request.QueryString["type"]))
        {
			string newUrl = tempNode.Url + "?type=" + typeIDUrlEncoded;
            string newTitle = tempNode.Title + ":  " + typeID;

            tempNode.Url = newUrl;
            tempNode.Title = newTitle;
        }

        //Lastly, return the current node
		return nodeCopy;
	}
}
