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
public class ContactsListOptimistic
{
	public ContactsListOptimistic()
	{
		//
		// TODO: Add constructor logic here
		//
	}

    public List<Contact> GetContacts()
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
        return list;
    }

    public Contact GetContact(int contactID)
    {
        String connStr = ConfigurationManager.ConnectionStrings["Contacts"].ConnectionString;
        SqlDataSource s = new SqlDataSource(connStr, "select ContactID, ContactName from Contacts where ContactID = @ContactID");
        s.SelectParameters.Add(new Parameter("contactID", TypeCode.Int32, contactID.ToString()));
        IEnumerable rows = s.Select(DataSourceSelectArguments.Empty);

        foreach (DataRowView row in rows)
        {
            String name = "";
            if (row["ContactName"] != DBNull.Value)
                name = (String)row["ContactName"];

            return new Contact((int)row["ContactID"], name);
        }
        return null;
    }

    public int UpdateContact(String contactName, int original_contactID, String original_contactName)
    {
        // Update the contact name
        SqlDataSource s = new SqlDataSource();
        s.ConnectionString = ConfigurationManager.ConnectionStrings["Contacts"].ConnectionString;
        s.UpdateCommand = "UpdateContact";
        s.UpdateCommandType = SqlDataSourceCommandType.StoredProcedure;

        s.UpdateParameters.Add(new Parameter("contactName", TypeCode.String, contactName));
        s.UpdateParameters.Add(new Parameter("original_contactID", TypeCode.Int32, original_contactID.ToString()));
        s.UpdateParameters.Add(new Parameter("original_contactName", TypeCode.String, original_contactName));
        s.UpdateParameters["contactName"].ConvertEmptyStringToNull = false;
        s.UpdateParameters["original_contactName"].ConvertEmptyStringToNull = false;

        int rowsAffected = s.Update();

        // Return the number of rows affected
        return rowsAffected;
    }

    public int DeleteContact(int original_contactID, String original_contactName)
    {
        // Delete the contact
        SqlDataSource s = new SqlDataSource();
        s.ConnectionString = ConfigurationManager.ConnectionStrings["Contacts"].ConnectionString;
        s.DeleteCommand = "DeleteContact";
        s.DeleteCommandType = SqlDataSourceCommandType.StoredProcedure;

        s.DeleteParameters.Add(new Parameter("original_contactID", TypeCode.Int32, original_contactID.ToString()));
        s.DeleteParameters.Add(new Parameter("original_contactName", TypeCode.String, original_contactName));

        int rowsAffected = s.Delete();

        // Return the number of rows affected
        return rowsAffected;
    }

    public int UpdateContact(Contact c, Contact original_c)
    {
        HttpContext.Current.Response.Write("UpdateContact(Contact c, Contact original_c)");
        return UpdateContact(c.ContactName, original_c.ContactID, original_c.ContactName);
    }

    public int DeleteContact(Contact original_c) 
    {
        HttpContext.Current.Response.Write("DeleteContact(Contact original_c)");
        return DeleteContact(original_c.ContactID, original_c.ContactName);
    }
}
