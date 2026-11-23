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
using System.Configuration;

public class AuthorsDB
{
    public AuthorsDB() { }

    public static System.Data.DataSet GetAuthorsByState(string state)
    {
        string connectionString = ConfigurationManager.ConnectionStrings["Pubs"].ConnectionString;
        System.Data.IDbConnection dbConnection = new System.Data.SqlClient.SqlConnection(connectionString);
        string queryString = "SELECT au_id, au_fname, au_lname, state FROM [authors] WHERE ([authors].[state] = @state)";
        System.Data.IDbCommand dbCommand = new System.Data.SqlClient.SqlCommand();

        dbCommand.CommandText = queryString;
        dbCommand.Connection = dbConnection;

        System.Data.IDataParameter dbParam_state = new System.Data.SqlClient.SqlParameter();

        dbParam_state.ParameterName = "@state";
        dbParam_state.Value = state;
        dbParam_state.DbType = System.Data.DbType.StringFixedLength;
        dbCommand.Parameters.Add(dbParam_state);

        System.Data.IDbDataAdapter dataAdapter = new System.Data.SqlClient.SqlDataAdapter();

        dataAdapter.SelectCommand = dbCommand;

        System.Data.DataSet dataSet = new System.Data.DataSet();

        dataAdapter.Fill(dataSet);
        return dataSet;
    }

    public static System.Data.DataSet GetStates()
    {
        string connectionString = ConfigurationManager.ConnectionStrings["Pubs"].ConnectionString;
        System.Data.IDbConnection dbConnection = new System.Data.SqlClient.SqlConnection(connectionString);
        string queryString = "SELECT DISTINCT [authors].state FROM [authors]";
        System.Data.IDbCommand dbCommand = new System.Data.SqlClient.SqlCommand();

        dbCommand.CommandText = queryString;
        dbCommand.Connection = dbConnection;

        System.Data.IDbDataAdapter dataAdapter = new System.Data.SqlClient.SqlDataAdapter();

        dataAdapter.SelectCommand = dbCommand;

        System.Data.DataSet dataSet = new System.Data.DataSet();

        dataAdapter.Fill(dataSet);
        return dataSet;
    }

    public static int UpdateAuthor (string au_id, string au_lname, string au_fname, string state)
    {
        string connectionString = ConfigurationManager.ConnectionStrings["Pubs"].ConnectionString;
        System.Data.IDbConnection dbConnection = new System.Data.SqlClient.SqlConnection(connectionString);
        string queryString = "UPDATE [authors] SET [au_lname]=@au_lname, [au_fname]=@au_fname, [state]=@state WHERE ([authors].[au_id] = @au_id)";
        System.Data.IDbCommand dbCommand = new System.Data.SqlClient.SqlCommand();

        dbCommand.CommandText = queryString;
        dbCommand.Connection = dbConnection;

        System.Data.IDataParameter dbParam_au_id = new System.Data.SqlClient.SqlParameter();

        dbParam_au_id.ParameterName = "@au_id";
        dbParam_au_id.Value = au_id;
        dbParam_au_id.DbType = System.Data.DbType.String;
        dbCommand.Parameters.Add(dbParam_au_id);

        System.Data.IDataParameter dbParam_au_lname = new System.Data.SqlClient.SqlParameter();

        dbParam_au_lname.ParameterName = "@au_lname";
        dbParam_au_lname.Value = au_lname;
        dbParam_au_lname.DbType = System.Data.DbType.String;
        dbCommand.Parameters.Add(dbParam_au_lname);

        System.Data.IDataParameter dbParam_au_fname = new System.Data.SqlClient.SqlParameter();

        dbParam_au_fname.ParameterName = "@au_fname";
        dbParam_au_fname.Value = au_fname;
        dbParam_au_fname.DbType = System.Data.DbType.String;
        dbCommand.Parameters.Add(dbParam_au_fname);

        System.Data.IDataParameter dbParam_state = new System.Data.SqlClient.SqlParameter();

        dbParam_state.ParameterName = "@state";
        dbParam_state.Value = state;
        dbParam_state.DbType = System.Data.DbType.StringFixedLength;
        dbCommand.Parameters.Add(dbParam_state);

        int rowsAffected = 0;

        dbConnection.Open();
        try
        {
            rowsAffected = dbCommand.ExecuteNonQuery();
        }
        finally
        {
            dbConnection.Close();
        }
        return rowsAffected;
    }
}
