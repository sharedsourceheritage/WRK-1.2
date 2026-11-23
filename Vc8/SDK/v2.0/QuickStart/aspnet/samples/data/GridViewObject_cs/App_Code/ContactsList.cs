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
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// Summary description for ContactsList
/// </summary>
public class ContactsList
{
	public ContactsList()
	{
		//
		// TODO: Add constructor logic here
		//
	}

    public List<Contact> GetContacts(out int totalCount)
    {
        String connStr = ConfigurationManager.ConnectionStrings["Contacts"].ConnectionString;
        SqlDataSource s = new SqlDataSource(connStr, "select ContactID, ContactName from Contacts");
        IEnumerable rows = s.Select(DataSourceSelectArguments.Empty);

        List<Contact> list = new List<Contact>();
        foreach (DataRowView row in rows)
        {
            String name = "";
            if (row["ContactName"] != DBNull.Value)
                name = (String)row["ContactName"];

            list.Add(new Contact((int)row["ContactID"], name));
        }
        totalCount = list.Count;
        return list;
    }

    public int UpdateContact(String contactName, int contactID)
    {
        // Update the contact name
        SqlDataSource s = new SqlDataSource();
        s.ConnectionString = ConfigurationManager.ConnectionStrings["Contacts"].ConnectionString;
        s.UpdateCommand = "UpdateContactName";
        s.UpdateCommandType = SqlDataSourceCommandType.StoredProcedure;
        s.UpdateParameters.Add(new Parameter("ID", TypeCode.Int32, contactID.ToString()));
        s.UpdateParameters.Add(new Parameter("Name", TypeCode.String, contactName));
        s.UpdateParameters["Name"].ConvertEmptyStringToNull = false;
        int rowsAffected = s.Update();

        // Return the number of rows affected
        return rowsAffected;
    }
}


