'=====================================================================
'
'  File:    AssemblyBrowser.vb
'  Summary: Provides a relational view over an assembly.
'  Date:    April 06, 2005
'
'---------------------------------------------------------------------
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.
'
'  This source code is intended only as a supplement to Microsoft
'  Development Tools and/or on-line documentation.  See these other
'  materials for detailed information regarding Microsoft code samples.
'
'  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
'  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'  PARTICULAR PURPOSE.
'======================================================= 

''' <summary>
''' AssemblyBrowser is a simple utility for composing sql queries over 
''' assembly metadata. It uses a table-valued-function to return
''' a table to SqlServer.
''' </summary>

Public NotInheritable Class AssemblyBrowser
    ''' <summary>
    ''' Get the types in the assembly, as a table
    ''' </summary>
    ''' <param name="name"></param>
    ''' <returns></returns>
    <Microsoft.SqlServer.Server.SqlFunction(FillRowMethodName:="FillTypeRow", Name:="GetTypes", _
        TableDefinition:="FullName nvarchar(256), BaseTypeName nvarchar(256), IsValueType bit, NumFields int, IsSerializable bit, IsISerializable bit, IsLayoutSequential bit, Namespace nvarchar(256), IsPublic bit, IsSealed bit, AssemblyName nvarchar(256)")> _
    Public Shared Function GetTypes(ByVal name As String) As IEnumerable
        Dim e As IEnumerable

        Try
            Dim a As [Assembly] = GetAssembly(name)
            If a Is Nothing Then
                e = New Type(-1) {}
            Else
                e = a.GetTypes()
            End If

        Catch te As ReflectionTypeLoadException
            'could not load some of the types, just return the types that you could load
            e = te.Types
        End Try

        Return e
    End Function

    ''' <summary>
    ''' Called by SQL Server to populate a row in the results of the TVF.  Takes a type and
    ''' breaks the information up into separate columns for the row being generated.
    ''' </summary>
    ''' <param name="row"></param>
    ''' <param name="fullName"></param>
    ''' <param name="baseTypeName"></param>
    ''' <param name="isValueType"></param>
    ''' <param name="numFields"></param>
    ''' <param name="isSerializable"></param>
    ''' <param name="isISerializable"></param>
    ''' <param name="isLayoutSequential"></param>
    ''' <param name="namespace"></param>
    ''' <param name="isPublic"></param>
    ''' <param name="isSealed"></param>
    ''' <param name="assemblyName"></param>
    ''' <remarks></remarks>
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    Public Shared Sub FillTypeRow(ByVal row As Object, <Out()> ByRef fullName As String, <Out()> ByRef baseTypeName As String, _
        <Out()> ByRef isValueType As Boolean, <Out()> ByRef numFields As Integer, <Out()> ByRef isSerializable As Boolean, _
        <Out()> ByRef isISerializable As Boolean, <Out()> ByRef isLayoutSequential As Boolean, <Out()> ByRef [namespace] As String, _
        <Out()> ByRef isPublic As Boolean, <Out()> ByRef isSealed As Boolean, <Out()> ByRef assemblyName As String)

        If row Is Nothing Then
            Return
        End If

        Dim t As Type = CType(row, Type)

        fullName = t.FullName
        If (t.BaseType Is Nothing) Then
            baseTypeName = String.Empty
        Else
            baseTypeName = t.BaseType.FullName
        End If

        isValueType = t.IsValueType

        Dim fields As FieldInfo() = t.GetFields(BindingFlags.Instance Or BindingFlags.Public)

        If (fields Is Nothing) Then
            numFields = 0
        Else
            numFields = fields.Length
        End If

        isSerializable = t.IsSerializable
        isISerializable = GetType(System.Runtime.Serialization.ISerializable).IsAssignableFrom(t)
        isLayoutSequential = t.IsLayoutSequential
        [namespace] = t.Namespace
        isPublic = t.IsPublic
        isSealed = t.IsSealed
        assemblyName = t.Assembly.GetName().Name
    End Sub

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1031:DoNotCatchGeneralExceptionTypes")> _
    Friend Shared Function GetAssembly(ByVal name As String) As [Assembly]
        Try
            Return [Assembly].Load(name)
        Catch
            Return Nothing
        End Try
    End Function

    Private Sub New()
    End Sub

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1024:UsePropertiesWhereAppropriate")> _
    <SqlFunction(FillRowMethodName:="FillAssemblyRow", Name:="GetLoadedAssemblies", _
        TableDefinition:="FullName nvarchar(256)")> _
    Public Shared Function GetLoadedAssemblies() As IEnumerable
        Dim e As IEnumerable = AppDomain.CurrentDomain.GetAssemblies()
        'Dim schemas() As Microsoft.SqlServer.Server.SqlMetaData = _
        '    {New Microsoft.SqlServer.Server.SqlMetaData("FullName", _
        '    SqlDbType.NVarChar, 256)}

        Return e
    End Function

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    Public Shared Sub FillAssemblyRow(ByVal row As Object, <Out()> ByRef fullName As String)
        fullName = CType(row, [Assembly]).FullName
    End Sub
End Class
