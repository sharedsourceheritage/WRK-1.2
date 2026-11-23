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
Imports System.Collections
Imports System.Configuration
Imports System.Data.SqlClient
Imports System.Web.UI
Imports System.Web.UI.WebControls

Public Class WarehouseDB

    Public Shared Function GetProductCategories() As CategoryList
        
        Dim categories As New CategoryList
        
        Dim connStr As String = ConfigurationManager.ConnectionStrings("GrocerToGo").ConnectionString
        Dim mySource As SqlDataSource = New SqlDataSource(connStr, "GetCategories")
        mySource.SelectCommandType = SqlDataSourceCommandType.StoredProcedure
        Dim result As IEnumerable = mySource.Select(DataSourceSelectArguments.Empty)
        
        Dim row As DataRowView
        For Each row in result
        
            categories.Add(New Category( _
                row("CategoryId").ToString(), _
                row("CategoryName").ToString()) _
            )
        Next
        Return categories
    End Function

    Public Shared Function GetProductsForCategory(categoryId As String) As ProductList 
    
        Dim products As New ProductList

        Dim connStr As String = ConfigurationManager.ConnectionStrings("GrocerToGo").ConnectionString
        Dim mySource As SqlDataSource = New SqlDataSource(connStr, "GetProductsForCategory")
        mySource.SelectCommandType = SqlDataSourceCommandType.StoredProcedure
        mySource.SelectParameters.Add(New Parameter("catId", TypeCode.Int32, categoryId))
        Dim result As IEnumerable = mySource.Select(DataSourceSelectArguments.Empty)
        
        Dim row As DataRowView
        For Each row in result
        
            products.Add(New Product( _
                row("ProductId").ToString(), _
                row("ProductName").ToString()) _
            )
        Next
        Return products
    End Function

End Class

Public Class Category

    Public Id As String 
    Public Name As String

    Public Sub New (ByVal id As String, ByVal name As String)
        Me.Id = id
        Me.Name = name
    End Sub
End Class

Public Class CategoryList 
    Inherits ArrayList

    Default Public Shadows Property DefaultProperty(i As Integer) As Category 
        Get
            Return Ctype(MyBase.Item(i), Category)
        End Get 
        Set
          MyBase.Item(i) = value 
        End Set
    End Property
End Class

Public Class Product

    Public Id As String 
    Public Name As String

    Public Sub New (ByVal id As String, ByVal name As String)
        Me.Id = id
        Me.Name = name
    End Sub
End Class

Public Class ProductList 
    Inherits ArrayList

    Default Public Shadows Property DefaultProperty(i As Integer) As Product 
        Get
            Return Ctype(MyBase.Item(i), Product)
        End Get 
        Set
          MyBase.Item(i) = value 
        End Set
    End Property
End Class

