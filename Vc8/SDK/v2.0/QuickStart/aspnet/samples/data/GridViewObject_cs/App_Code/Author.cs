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

public class Author
{
    private String _id;

    public String ID
    {
        get
        {
            return _id;
        }

        set
        {
            _id = value;
        }
    } 

    private String _name;

    public String Name
    {
        get
        {
            return _name;
        }
        set
        {
            _name = value;
        }
    }

    private String _lastName;

    public String LastName
    {
        get
        {
            return _lastName;
        }
        set
        {
            _lastName = value;
        }
    }

    private String _state;

    public String State
    {
        get
        {
            return _state;
        }
        set
        {
            _state = value;
        }
    }

    public Author (String id, String name, String lastName, String state)
    {
        this.ID = id;
        this.Name = name;
        this.LastName = lastName;
        this.State = state;
    }

    public Author()
    {
        // default constructor
    }
}
