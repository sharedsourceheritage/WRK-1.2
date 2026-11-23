'=====================================================================
'
'  File:    CurrencyConverter.vb for Adventure Works Cycles SQLCLR Layer Sample
'  Summary: Defines the ConvertCurrency method which is exposed as a UDF in SQL Server.
'  Date:    May 25, 2004
'
'---------------------------------------------------------------------
'
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.
'
'This source code is intended only as a supplement to Microsoft
'Development Tools and/or on-line documentation.  See these other
'materials for detailed information regarding Microsoft code samples.
'
'THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
'KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'PARTICULAR PURPOSE.
'
'======================================================= 

Imports System
Imports System.Data.Sql
Imports System.Data.SqlTypes
Imports System.Data.SqlClient
Imports System.Globalization
Imports Microsoft.Samples.SqlServer
Imports System.IO
Imports Microsoft.SqlServer.Server

''' <summary>
''' This class is used to compute the value of US money a given region.
''' </summary>
Public NotInheritable Class CurrencyConverter

    Private Shared USCulture As CultureInfo = CultureInfo.CreateSpecificCulture("en-us")

    Private Sub New()
    End Sub

    ''' <summary>
    '''	Computes the value of a certain amount of money in the USA in a different region.
    ''' </summary>
    ''' <param name="fromAmount">The quantity of money</param>
    ''' <param name="toCultureName">A culture which is a member of the region of interest</param>
    ''' <returns></returns>
    <Microsoft.SqlServer.Server.SqlFunction(DataAccess:=Microsoft.SqlServer.Server.DataAccessKind.Read), CLSCompliant(False)> _
    Public Shared Function ConvertCurrency(ByVal fromAmount As SqlMoney, ByVal toCultureName As SqlString, ByVal onDate As SqlDateTime) As Microsoft.Samples.SqlServer.Currency
        Dim toCulture As CultureInfo = CultureInfo.CreateSpecificCulture(toCultureName.Value)

        If toCulture.Equals(USCulture) Then
            Dim c As Currency = New Currency(USCulture, fromAmount.ToDecimal)
            Return c
        End If

        Dim toCurrencyCode As String _
            = New RegionInfo(toCulture.LCID).ISOCurrencySymbol

        ' Find the rate closest to today
        Using conn As New SqlConnection("context connection=true")

            Dim command As SqlCommand = conn.CreateCommand()
            command.CommandType = CommandType.StoredProcedure
            command.CommandText = "usp_LookupConversionRate"

            Dim onDateParameter As SqlParameter _
                = New SqlParameter("@OnDate", SqlDbType.DateTime)
            onDateParameter.Value = onDate
            command.Parameters.Add(onDateParameter)

            Dim toCurrencyCodeParameter As SqlParameter _
                = New SqlParameter("@ToCurrencyCode", SqlDbType.NChar, 3)
            toCurrencyCodeParameter.Value = toCurrencyCode
            command.Parameters.Add(toCurrencyCodeParameter)

            Dim resultParameter As SqlParameter _
                = New SqlParameter("@Result", SqlDbType.Decimal)
            resultParameter.Precision = 10
            resultParameter.Scale = 4
            resultParameter.Direction = ParameterDirection.Output
            command.Parameters.Add(resultParameter)
            conn.Open()

            command.ExecuteNonQuery()

            Dim conversionFactor As Decimal

            If TypeOf resultParameter.Value Is Decimal Then
                conversionFactor = CType(resultParameter.Value, Decimal)
            Else
                conversionFactor = CType(1.0, Decimal)
                toCulture = USCulture
            End If

            Return New Currency(toCulture, fromAmount.ToDecimal() _
                * conversionFactor)
        End Using
    End Function
End Class
