'-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET SDK Code Samples.
' 
'  Copyright (C) Microsoft Corporation.  All rights reserved.
' 
'This source code is intended only as a supplement to Microsoft
'Development Tools and/or on-line documentation.  See these other
'materials for detailed information regarding Microsoft code samples.
' 
'THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
'KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'PARTICULAR PURPOSE.
'-----------------------------------------------------------------------
Imports System
Imports System.Web


Public Class PathExpansionHandler

  Public Shared Function ExpandPath(ByVal sender As Object, ByVal e As SiteMapResolveEventArgs) As SiteMapNode

        'Obtain a reference to the current node and its ancestors
        Dim nodeCopy As SiteMapNode =  SiteMap.CurrentNode.Clone(True) 
 
        'The temporary node is used for walking up the chain of nodes, fixing up Urls and
        'other properties along the way.
        Dim tempNode As SiteMapNode =  nodeCopy 
 
        'Check if there is a newsgroup type in the query string
        Dim typeID As String =  Nothing 
	Dim typeIDUrlEncoded As String =  Nothing 
	If Not String.IsNullOrEmpty(e.Context.Request.QueryString("type")) Then
		typeID = e.Context.Server.HtmlEncode(e.Context.Request.QueryString("type"))
		typeIDUrlEncoded = e.Context.Server.UrlEncode(e.Context.Request.QueryString("type"))
	End If
 
        'First perform Url fixups for the postings page
        'If there is a posting ID in the query string, then we know the current node
        'is the postings page.
	If Not String.IsNullOrEmpty(e.Context.Request.QueryString("postingID")) Then
		Dim postingID as string = _
			e.Context.Server.HtmlEncode(e.Context.Request.QueryString("postingID"))
		Dim postingIDUrlEncoded as string = _
			e.Context.Server.UrlEncode(e.Context.Request.QueryString("postingID"))
 
		Dim NewUrl As String =  tempNode.Url + "?type=" + typeIDUrlEncoded + "&postingID=" + postingIDUrlEncoded 
        	Dim NewTitle As String =  tempNode.Title + ": " + postingID 
 
 	        tempNode.Url = NewUrl
        	tempNode.Title = NewTitle
 
 	        'Walkup one level to the parent
        	tempNode = tempNode.ParentNode
	End If
 
        'Next, perform fixups for the newsgroup page
        'By this point the nodeCopy variable is pointing at the newsgroup node
	If Not String.IsNullOrEmpty(e.Context.Request.QueryString("type")) Then
		Dim NewUrl As String =  tempNode.Url + "?type=" + typeIDUrlEncoded 
        	Dim NewTitle As String =  tempNode.Title + ":  " + typeID 
 
 		tempNode.Url = NewUrl
		tempNode.Title = NewTitle
	End If
 
        'Lastly, return the current node
	Return nodeCopy

  End Function
End Class
