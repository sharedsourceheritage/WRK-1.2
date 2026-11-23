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
using System.Collections.Generic;

public class AuthorsComponent
{
    public AuthorsComponent ()
    {
        // TODO: Add constructor logic here
    }

    public List<Author> GetAuthorsByState (String state, String sortExpression)
    {
        List<Author> authors = new List<Author> ();
        DataSet ds = AuthorsDB.GetAuthorsByState (state);

        foreach (DataRow row in ds.Tables[0].Rows)
        {
            authors.Add (new Author ((String)row["au_id"], (String)row["au_fname"], (String)row["au_lname"], (String)row["state"]));
        }

        authors.Sort(new AuthorComparer(sortExpression));
        return authors;
    }

    public int UpdateAuthor (string ID, string LastName, string Name, string State)
    {
        return AuthorsDB.UpdateAuthor (ID, LastName, Name, State);
    }

    public int UpdateAuthor(Author a)
    {
        return AuthorsDB.UpdateAuthor(a.ID, a.LastName, a.Name, a.State);
    }

    public List<String> GetStates()
    {
        List<String> states = new List<String>();
        DataSet ds = AuthorsDB.GetStates();

        foreach (DataRow row in ds.Tables[0].Rows)
        {
            states.Add((String)row["state"]);
        }
        return states;
    }
}

public class AuthorComparer : IComparer<Author>
{
    private string _sortColumn;
    private bool _reverse;

    public AuthorComparer(string sortExpression)
    {
        _reverse = sortExpression.ToLowerInvariant().EndsWith(" desc");
        if (_reverse)
        {
            _sortColumn = sortExpression.Substring(0, sortExpression.Length - 5);
        }
        else
        {
            _sortColumn = sortExpression;
        }
    }

    public int Compare(Author a, Author b)
    {
        int retVal = 0;
        switch (_sortColumn)
        {
            case "ID":
                retVal = String.Compare(a.ID, b.ID, StringComparison.InvariantCultureIgnoreCase);
                break;
            case "Name":
                retVal = String.Compare(a.Name, b.Name, StringComparison.InvariantCultureIgnoreCase);
                break;
            case "LastName":
                retVal = String.Compare(a.LastName, b.LastName, StringComparison.InvariantCultureIgnoreCase);
                break;
            case "State":
                retVal = String.Compare(a.State, b.State, StringComparison.InvariantCultureIgnoreCase);
                break;
        }
        return (retVal * (_reverse ? -1 : 1));
    }
}
