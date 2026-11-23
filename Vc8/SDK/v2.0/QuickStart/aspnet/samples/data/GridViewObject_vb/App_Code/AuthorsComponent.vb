
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
Imports System.Data
Imports System.Collections.Generic

Public Class AuthorsComponent

    Public Sub New()

        ' TODO: Add constructor logic here
    End Sub

    Public Function GetAuthorsByState(ByVal state As String, ByVal sortExpression As String) As List(Of Author)

        Dim authors As New List(Of Author)

        Dim ds As DataSet = AuthorsDB.GetAuthorsByState(state)

        Dim row As DataRow
        For Each row In ds.Tables(0).Rows
            authors.Add(New Author(row("au_id"), row("au_fname"), row("au_lname"), row("state")))
        Next

        authors.Sort(New AuthorComparer(sortExpression))
        Return authors
    End Function

    Public Function UpdateAuthor(ByVal ID As String, ByVal LastName As String, ByVal Name As String, ByVal State As String) As Integer

        Return AuthorsDB.UpdateAuthor(ID, LastName, Name, State)
    End Function

    Public Function UpdateAuthor(ByVal a As Author) As Integer

        Return AuthorsDB.UpdateAuthor(a.ID, a.LastName, a.Name, a.State)
    End Function

    Public Function GetStates() As List(Of String)

        Dim states As New List(Of String)
        Dim ds As DataSet = AuthorsDB.GetStates()

        Dim row As DataRow
        For Each row In ds.Tables(0).Rows

            states.Add(row("state"))
        Next
        Return states
    End Function
End Class

Public Class AuthorComparer : Implements IComparer(Of Author)

    Private _sortColumn As String
    Private _reverse As Boolean

    Public Sub New(ByVal sortExpression As String)

        _reverse = sortExpression.ToLowerInvariant().EndsWith(" desc")
        If (_reverse) Then

            _sortColumn = sortExpression.Substring(0, sortExpression.Length - 5)
        Else

            _sortColumn = sortExpression
        End If
    End Sub

    Public Function IComparer_Compare(ByVal a As Author, ByVal b As Author) As Integer Implements IComparer(Of Author).Compare

        Dim retVal As Integer = 0
        Select Case _sortColumn

            Case "ID"
                retVal = String.Compare(a.ID, b.ID, StringComparison.InvariantCultureIgnoreCase)
            Case "Name"
                retVal = String.Compare(a.Name, b.Name, StringComparison.InvariantCultureIgnoreCase)
            Case "LastName"
                retVal = String.Compare(a.LastName, b.LastName, StringComparison.InvariantCultureIgnoreCase)
            Case "State"
                retVal = String.Compare(a.State, b.State, StringComparison.InvariantCultureIgnoreCase)
        End Select

        Dim _reverseInt As Integer = -1
        If (_reverse) Then
            _reverseInt = 1
        End If
        Return (retVal * _reverseInt)
    End Function

End Class
