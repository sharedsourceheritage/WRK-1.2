<%@ page LANGUAGE="C#" Debug="true" %>
<%@ import namespace="System.Data.SqlClient" %>
<%
/*=====================================================================

  File:      Photos.aspx for Online Catalog
  Summary:   Retrieves product photos from the Adventure Works databases.
  Date:	     June 9, 2003

---------------------------------------------------------------------

  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) 2003 Microsoft Corporation.  All rights reserved.

 This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

======================================================= */

Response.ContentType="image/gif";
string id = Request.QueryString["PID"];
System.Data.SqlClient.SqlConnection c = new System.Data.SqlClient.SqlConnection( "data source=localhost;database=AdventureWorks; integrated security=SSPI"); 
c.Open();
System.Data.SqlClient.SqlCommand cmd= new System.Data.SqlClient.SqlCommand("select LargePhoto from Production.ProductPhoto where ProductPhotoID = " + id ,c);
System.Data.SqlClient.SqlDataReader r = cmd.ExecuteReader();
if( r!= null && r.Read()) 
{
   int headercb = 0; 
   byte[] data;
   System.Data.SqlTypes.SqlBinary sb;
   
   sb  = r.GetSqlBinary(0);
   data = new byte[sb.Length - headercb];
   Array.Copy( sb.Value, headercb, data, 0, sb.Length - headercb);
   Response.BinaryWrite(data);
}
c.Close();
%>