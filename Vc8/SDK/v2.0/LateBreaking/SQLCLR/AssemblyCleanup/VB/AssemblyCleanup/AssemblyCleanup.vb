'=====================================================================
' 
'  File:      AssemblyCleanup.vb for .NET CLR user assemblies cleanup sample
'  Summary:   defines a CLR user defined function CleanupUnusedAssemblies that drops 
'             all the invisible assemblies with no references.
'  Date:      July 08, 2005
' 
'---------------------------------------------------------------------
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) 2003 Microsoft Corporation.  All rights reserved.
' 
'  This source code is intended only as a supplement to Microsoft
'  Development Tools and/or on-line documentation.  See these other
'  materials for detailed information regarding Microsoft code samples.
' 
'  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
'  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'  PARTICULAR PURPOSE.
'======================================================================= 

<Assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1020:AvoidNamespacesWithFewTypes", Scope:="namespace", Target:="Microsoft.Samples.SqlServer")> 

Public NotInheritable Class AssemblyCleanup
    Private transaction As SqlTransaction

    Friend Class AssemblySet
        Private m_dictionary As Dictionary(Of Integer, Object)

        ''' <summary>
        ''' Initialize internal structures
        ''' </summary>
        ''' <returns></returns>
        Public Sub New()
            m_dictionary = New Dictionary(Of Integer, Object)
        End Sub

        ''' <summary>
        ''' Adds an assembly id into the current AssemblySet if it is not already part of it.
        ''' </summary>
        ''' <returns></returns>
        Public Sub Add(ByVal assemblyId As Integer)
            If Not m_dictionary.ContainsKey(assemblyId) Then
                m_dictionary.Add(assemblyId, Nothing)
            End If
        End Sub

        ''' <summary>
        ''' Number of assembly ids stored in this instance
        ''' </summary>
        ''' <returns></returns>
        Public ReadOnly Property Count() As Integer
            Get
                Return m_dictionary.Count
            End Get
        End Property

        ''' <summary>
        ''' Returns the comma-separated list of assembly ids contained in this instance
        ''' </summary>
        ''' <returns>string value that represents a comma-seperated list of assembly ids</returns>
        Public Function ToCommaSeperatedList() As String
            Dim sb As New StringBuilder()

            If m_dictionary.Count > 0 Then
                For Each kv As KeyValuePair(Of Integer, Object) In m_dictionary
                    If (True) Then
                        sb.Append(kv.Key)
                        sb.Append(",")
                    End If
                Next

                sb.Length -= 1 ' remove the trailing comma
            End If

            Return sb.ToString()

        End Function
    End Class

    ''' <summary>
    ''' Initializes an instance of AssemblyCleanup with a SqlTransaction
    ''' </summary>
    ''' <returns></returns>
    Private Sub New(ByVal trans As SqlTransaction)
        Me.transaction = trans
    End Sub

    ''' <summary>
    ''' Helper function that creates a SqlCommand object as part of the 
    ''' current transaction
    ''' </summary>
    ''' <returns></returns>
    Private Function CreateCommandInTransaction() As SqlCommand
        Dim cmd As SqlCommand = transaction.Connection.CreateCommand()

        cmd.Transaction = Me.transaction

        Return cmd
    End Function

    ''' <summary>
    ''' Helper function that constructs an AssemblySet instance using the 
    ''' first column of the resultset resulting from the query that was passed in.
    ''' </summary>
    ''' <param name="query"></param>
    ''' <returns></returns>
    Private Function GetAssemblySetFromQuery(ByVal query As String) As AssemblySet
        Dim cmd As SqlCommand = CreateCommandInTransaction()
        Dim [set] As New AssemblySet()

        cmd.CommandText = query
        Dim rd As SqlDataReader = cmd.ExecuteReader()
        Try
            While rd.Read()
                [set].Add(rd.GetInt32(0))
            End While
        Finally
            rd.Dispose()
        End Try

        Return [set]
    End Function

    ''' <summary>
    ''' Constructs a DROP ASSEMBLY T-SQL statement using the AssemblySet 
    ''' passed in as a parameter.
    ''' </summary>
    ''' <param name="set"></param>
    ''' <returns></returns>
    Private Sub DropAssemblies(ByVal unusedAssemblySet As AssemblySet)
        If unusedAssemblySet.Count > 0 Then
            Dim assemblyNamesToDrop As New StringBuilder()

            ' Gather the list of assembly names we will drop later
            Dim cmd As SqlCommand = CreateCommandInTransaction()


            cmd.CommandText = String.Format(CultureInfo.InvariantCulture, _
                "SELECT name FROM sys.assemblies WHERE assembly_id IN ({0});", _
                unusedAssemblySet.ToCommaSeperatedList())
            Dim rd As SqlDataReader = cmd.ExecuteReader()
            Try
                While rd.Read()
                    assemblyNamesToDrop.Append("[")
                    assemblyNamesToDrop.Append(rd.GetString(0))
                    assemblyNamesToDrop.Append("],")
                End While
            Finally
                rd.Dispose()
            End Try

            ' Remove trailing comma
            assemblyNamesToDrop.Length -= 1

            ' Drop all assemblies at the same time
            cmd.CommandText = String.Format(CultureInfo.InvariantCulture, _
                "DROP ASSEMBLY {0}", assemblyNamesToDrop.ToString())
            cmd.ExecuteNonQuery()
        End If
    End Sub

    ''' <summary>
    ''' Serves as the stored procedure entry point and drives the process of 
    ''' expanding the "assemblies in use" set, negating it, and dropping 
    ''' the results.
    ''' </summary>
    ''' <param name="visibleAssemblies">If set to true, will also drop unused 
    ''' visible assemblies. Otherwise, will only drop unused invisible assemblies.</param>
    ''' <returns></returns>
    <Microsoft.SqlServer.Server.SqlProcedure()> _
    Public Shared Sub CleanupUnusedAssemblies(ByVal visibleAssemblies As Boolean)

        Dim succeeded As Boolean = False
        Dim conn As SqlConnection
        Dim transaction As SqlTransaction
        Dim sqlStatement As String
        Dim assembliesToDrop As AssemblySet
        Dim assemblyCleanup As AssemblyCleanup

        conn = New SqlConnection("context connection=true")
        conn.Open()
        transaction = conn.BeginTransaction()

        Try
            ' Create a set of assemblies in use by looking at 
            ' the metadata of the current database
            sqlStatement = "DECLARE @UsedAssembly TABLE (AssemblyID int NOT NULL); " & _
                "DECLARE @RowCount int; " & _
                "INSERT INTO @UsedAssembly " & _
                "SELECT DISTINCT([assembly_id]) " & _
                "FROM sys.assembly_modules " & _
                "UNION " & _
                "SELECT [assembly_id] " & _
                "FROM sys.assembly_types; " & _
                "SET @RowCount = @@ROWCOUNT; " & _
                "WHILE @RowCount > 0 " & _
                "BEGIN " & _
                "INSERT INTO @UsedAssembly " & _
                "SELECT [referenced_assembly_id] " & _
                "FROM sys.assembly_references ar " & _
                "INNER JOIN @UsedAssembly ua " & _
                "ON ar.[assembly_id] = ua.AssemblyID " & _
                "WHERE NOT EXISTS (SELECT * FROM @UsedAssembly WHERE AssemblyID = [referenced_assembly_id]) " & _
                "SET @RowCount = @@ROWCOUNT; " & _
                "END;"

            If visibleAssemblies Then
                sqlStatement += "SELECT assembly_id " & _
                    "FROM sys.assemblies " & _
                    "WHERE assembly_id NOT IN (SELECT AssemblyID FROM @UsedAssembly);"
            Else
                sqlStatement += "SELECT assembly_id " & _
                    "FROM sys.assemblies " & _
                    "WHERE assembly_id NOT IN (SELECT AssemblyID FROM @UsedAssembly) " & _
                    "    AND is_visible = 0;"
            End If

            ' This marks the beginning of the transaction
            assemblyCleanup = New AssemblyCleanup(transaction)

            ' Assemblies that are currently in use
            assembliesToDrop _
                = assemblyCleanup.GetAssemblySetFromQuery(sqlStatement)

            assemblyCleanup.DropAssemblies(assembliesToDrop)

            ' Mark as succeeded
            succeeded = True
        Finally
            ' We must guarantee that we explicitly call either Commit() 
            ' or Rollback() before we return.
            If succeeded Then
                transaction.Commit()
            Else
                transaction.Rollback()
            End If
        End Try
    End Sub
End Class
