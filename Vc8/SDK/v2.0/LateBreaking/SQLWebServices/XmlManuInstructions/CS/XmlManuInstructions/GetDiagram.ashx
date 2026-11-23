<%@ WebHandler Language="C#" Class="ImageGrabber" %>
using System;
using System.Web;
using System.IO;
using System.Data.SqlClient;
using System.Xml;
using System.Xml.Xsl;


/*=====================================================================

  File:      GetDiagram.ashx for Manufacturing Instructions XML Example
  Summary:   Retrieves SVG manufacturing illustrations from the Adventure Works databases.
  Date:	     April 27, 2004

---------------------------------------------------------------------

  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) Microsoft Corporation.  All rights reserved.

 This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

======================================================= */
public class ImageGrabber : IHttpHandler
{
	public void ProcessRequest(HttpContext context)
	{
		context.Response.Expires = -1;
		context.Response.ContentType = "image/svg+xml";

//   string pmid = Request.QueryString["ProductModelID"];
		string ilid = context.Request.QueryString["IllustrationID"];
		System.Data.SqlClient.SqlConnection c = new System.Data.SqlClient.SqlConnection("data source=localhost;database=AdventureWorks;integrated security=SSPI");
		c.Open();
		System.Data.SqlClient.SqlCommand cmd = new System.Data.SqlClient.SqlCommand("SELECT Diagram FROM Production.Illustration WHERE IllustrationID = '" + ilid + "'", c);

		System.Data.SqlClient.SqlDataReader r = cmd.ExecuteReader();

		if (r != null && r.Read())
		{
            System.Xml.XmlReader reader = XmlReader.Create(new StringReader((String)r.GetValue(0)));


			XslTransform xsl = new XslTransform();
			xsl.Load(context.Server.MapPath("svg.xsl"));

			XmlDocument doc = new XmlDocument();
			doc.Load(reader);
			XmlElement root = doc.DocumentElement;
			root.SetAttribute("viewbox", "0, 0, " + root.GetAttribute("width") + "," + root.GetAttribute("height"));
			root.SetAttribute("width", "200");
			root.SetAttribute("height", "150");

			xsl.Transform(doc, null, context.Response.OutputStream);

		}

		c.Close();
	}

	public bool IsReusable
	{
		get { return true; }
	}
}
