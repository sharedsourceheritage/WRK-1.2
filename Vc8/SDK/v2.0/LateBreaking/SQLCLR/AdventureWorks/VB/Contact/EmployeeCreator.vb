Imports System
Imports System.Data
Imports System.Data.Sql
Imports System.Data.SqlClient
Imports System.Data.SqlTypes
Imports System.Globalization
Imports Microsoft.SqlServer.Server

'=====================================================================
'
'  File:    EmployeeCreator.vb for Adventure Works Cycles SQLCLR Layer Sample
'  Summary: The class which implements the insertion of various rows in various tables to 
'           create contact information for employees of Adventure Works Cycles.
'  Date:    May 25, 2004
'
'---------------------------------------------------------------------
'
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.
'
' This source code is intended only as a supplement to Microsoft
' Development Tools and/or on-line documentation.  See these other
' materials for detailed information regarding Microsoft code samples.
'
' THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
' KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
' IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
'======================================================= 

''' <summary>
'''		Responsible for adding information about an employee by creating an address and then
'''		inserting a row in the HumanResources.Employee table.
''' </summary>
Public Class EmployeeCreator
    Inherits ContactCreator

    Public Overrides Sub Create()
        MyBase.Create()
        CreateAddress()
        Dim employeeID As Integer = -1
        Using conn As New SqlConnection("context connection=true")

            Dim command As SqlCommand = conn.CreateCommand()

            ResetCounters(3)
            Dim parameters As String = String.Format(CultureInfo.InvariantCulture, _
                "NationalIDNumber, ContactID, LoginID{0}, Title, BirthDate, MaritalStatus, Gender, HireDate, SalariedFlag, VacationHours, SickLeaveHours", _
                MaybeParameter("ManagerID"))
            Dim values As String = String.Format(CultureInfo.InvariantCulture, _
                "@NationalIDNumber, @ContactID, @LoginID{0}, @Title, @BirthDate, @MaritalStatus, @Gender, @HireDate, @SalariedFlag, @VacationHours, @SickLeaveHours", _
                MaybeValue("ManagerID"))

            command.CommandText = String.Format(CultureInfo.InvariantCulture, _
                "INSERT INTO HumanResources.Employee ({0}) VALUES ({1}); SELECT CAST(SCOPE_IDENTITY() as Int);", _
                parameters, values)
            MaybeAddCommandParameter("NationalIDNumber", command, SqlDbType.NVarChar, 15, True, String.Empty)
            MaybeAddCommandParameter("ContactID", command, SqlDbType.Int, True, String.Empty)
            MaybeAddCommandParameter("LoginID", command, SqlDbType.NVarChar, 256, True, String.Empty)
            MaybeAddCommandParameter("ManagerID", command, SqlDbType.Int, False, Nothing)
            MaybeAddCommandParameter("JobTitle", "Title", command, SqlDbType.NVarChar, 50, True, String.Empty)
            MaybeAddCommandParameter("BirthDate", command, SqlDbType.DateTime, True, String.Empty)
            MaybeAddCommandParameter("MaritalStatus", command, SqlDbType.NChar, 1, True, String.Empty)
            MaybeAddCommandParameter("Gender", command, SqlDbType.NChar, 1, True, String.Empty)
            MaybeAddCommandParameter("HireDate", command, SqlDbType.DateTime, True, String.Empty)
            MaybeAddCommandParameter("SalariedFlag", command, SqlDbType.Bit, True, "1")
            MaybeAddCommandParameter("VacationHours", command, SqlDbType.SmallInt, True, "0")
            MaybeAddCommandParameter("SickLeaveHours", command, SqlDbType.SmallInt, True, "0")
            conn.Open()

            employeeID = CInt(command.ExecuteScalar())
        End Using

        CreateEmployeeAdddress(employeeID, Integer.Parse(contactDictionary("AddressID"), _
            System.Globalization.CultureInfo.InvariantCulture))
        CreateEmployeeDepartmentHistory(employeeID, Integer.Parse( _
            contactDictionary("DepartmentID"), _
            System.Globalization.CultureInfo.InvariantCulture), _
            Integer.Parse(contactDictionary("ShiftID"), _
            System.Globalization.CultureInfo.InvariantCulture))
    End Sub

    Public Sub CreateAddress()
        Using conn As New SqlConnection("context connection=true")
            Dim command As SqlCommand = conn.CreateCommand()

            ResetCounters(4)

            Dim parameters As String = String.Format(CultureInfo.InvariantCulture, _
                "AddressLine1{0}, City, StateProvinceID, PostalCode", _
                MaybeParameter("AddressLine2"))
            Dim values As String = String.Format(CultureInfo.InvariantCulture, _
                "@AddressLine1{0}, @City, @StateProvinceID, @PostalCode", _
                MaybeValue("AddressLine2"))

            command.CommandText = String.Format(CultureInfo.InvariantCulture, _
                "INSERT INTO Person.Address ({0}) VALUES ({1}); SELECT CAST(SCOPE_IDENTITY() as Int);", _
                parameters, values)
            MaybeAddCommandParameter("AddressLine1", command, SqlDbType.NVarChar, 60, True, String.Empty)
            MaybeAddCommandParameter("AddressLine2", command, SqlDbType.NVarChar, 60, False, Nothing)
            MaybeAddCommandParameter("City", command, SqlDbType.NVarChar, 30, True, String.Empty)
            MaybeAddCommandParameter("StateProvinceID", command, SqlDbType.Int, True, String.Empty)
            MaybeAddCommandParameter("PostalCode", command, SqlDbType.NVarChar, 15, True, String.Empty)
            conn.Open()

            contactDictionary("AddressID") = command.ExecuteScalar().ToString()
        End Using
    End Sub

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1706:ShortAcronymsShouldBeUppercase")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1706:ShortAcronymsShouldBeUppercase")> _
    Public Shared Sub CreateEmployeeAdddress(ByVal employeeID As Integer, ByVal addressID As Integer)
        Using conn As New SqlConnection("context connection=true")

            Dim cmd As SqlCommand = conn.CreateCommand()
            cmd.CommandText = "INSERT INTO HumanResources.EmployeeAddress " + "(EmployeeID, AddressID) VALUES (@EmployeeID, @AddressID)"
            cmd.Parameters.AddWithValue("@EmployeeID", employeeID)
            cmd.Parameters.AddWithValue("@AddressID", addressID)
            conn.Open()
            cmd.ExecuteNonQuery()
        End Using
    End Sub

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1706:ShortAcronymsShouldBeUppercase")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1706:ShortAcronymsShouldBeUppercase")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1706:ShortAcronymsShouldBeUppercase")> _
    Public Shared Sub CreateEmployeeDepartmentHistory(ByVal employeeID As Integer, ByVal departmentID As Integer, ByVal shiftID As Integer)
        Using conn As New SqlConnection("context connection=true")

            Dim cmd As SqlCommand = conn.CreateCommand()
            cmd.CommandText = "INSERT INTO HumanResources.EmployeeDepartmentHistory " + "(EmployeeID, DepartmentID, ShiftID, StartDate) VALUES " + "(@EmployeeID, @DepartmentID, @ShiftID, @StartDate)"
            cmd.Parameters.AddWithValue("@EmployeeID", employeeID)
            cmd.Parameters.AddWithValue("@DepartmentID", departmentID)
            cmd.Parameters.AddWithValue("@ShiftID", shiftID)
            cmd.Parameters.AddWithValue("@StartDate", DateTime.Now)
            conn.Open()
            cmd.ExecuteNonQuery()
        End Using
    End Sub
End Class
