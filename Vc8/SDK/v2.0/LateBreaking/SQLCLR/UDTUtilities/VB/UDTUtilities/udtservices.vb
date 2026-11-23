'=====================================================================
'
'  File:    UdtServices.vb
'  Summary: This file defines streaming tvfs that are used to return the fields, methods, and properties
'           defined in a UDT.
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

'Imports System.Reflection
'Imports System.Data.SqlTypes
'Imports System.Text
'Imports System.Globalization
'Imports System.Data.SqlClient

''' <summary>
''' Utility Udt functions
''' </summary>
Public NotInheritable Class UdtServices
#Region "udt fields"

    ''' <summary>
    ''' Get the fields in the UDT callable from tsql, as a table
    ''' </summary>
    ''' <param name="udtName"></param>
    ''' <returns></returns>
    <Microsoft.SqlServer.Server.SqlFunction(FillRowMethodName:="FillFieldRow", Name:="GetFields", TableDefinition:="Name nvarchar(128), Type nvarchar(128), RoutineProperties nvarchar(128)")> _
    Public Shared Function GetUdtFields(ByVal udtName As String) As IEnumerable
        Dim fields As ArrayList = GetSqlFields(GetUdt(udtName))

        Return fields
    End Function

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    Public Shared Sub FillFieldRow(ByVal row As Object, ByRef [name] As String, ByRef type As String, ByRef routineProperties As String)
        Dim fi As FieldInfo = CType(row, FieldInfo)

        [name] = fi.Name
        type = fi.FieldType.Name
        routineProperties = String.Empty
    End Sub


#End Region

#Region "udt properties"

    ''' <summary>
    ''' Get the properties defined in a particular UDT
    ''' </summary>
    ''' <param name="udtName"></param>
    ''' <returns></returns>
    <Microsoft.SqlServer.Server.SqlFunction(FillRowMethodName:="FillPropertyRow", Name:="GetProperties", TableDefinition:="Name nvarchar(128), Type nvarchar(128), RoutineProperties nvarchar(128)")> _
    Public Shared Function GetUdtProperties(ByVal udtName As String) As IEnumerable
        Dim properties As ArrayList = GetSqlProperties(GetUdt(udtName))

        Return properties
    End Function

    ''' <summary>
    ''' Called by SQL Server to populate a row of the results of the TVF.  
    ''' </summary>
    ''' <param name="row"></param>
    ''' <param name="name"></param>
    ''' <param name="type"></param>
    ''' <param name="routineProperties"></param>
    ''' <remarks></remarks>
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    Public Shared Sub FillPropertyRow(ByVal row As Object, ByRef name As String, ByRef type As String, ByRef routineProperties As String)
        Dim pi As PropertyInfo = CType(row, PropertyInfo)

        name = pi.Name
        type = pi.PropertyType.Name

        Dim methInfo As MethodInfo = pi.GetGetMethod()
        Dim attrs As Object() = methInfo.GetCustomAttributes( _
            GetType(Microsoft.SqlServer.Server.SqlMethodAttribute), True)

        If Not (attrs Is Nothing) AndAlso attrs.Length = 1 Then
            Dim attr As Microsoft.SqlServer.Server.SqlMethodAttribute _
                = CType(attrs(0), Microsoft.SqlServer.Server.SqlMethodAttribute)

            routineProperties = GetRoutineProperties(attr)
        End If
    End Sub

#End Region

#Region "udt methods"

    ''' <summary>
    ''' Get the methods on the UDT callable from tsql, as a table
    ''' </summary>
    ''' <param name="udtName"></param>
    ''' <returns></returns>
    <Microsoft.SqlServer.Server.SqlFunction(FillRowMethodName:="FillMethodRow", Name:="GetMethods", TableDefinition:="Name nvarchar(128), Parameters nvarchar(4000), Type nvarchar(128), RoutineProperties nvarchar(128)")> _
    Public Shared Function GetUdtMethods(ByVal udtName As String) As IEnumerable
        Dim methods As ArrayList = GetSqlMethods(GetUdt(udtName))

        Return methods
    End Function

    ''' <summary>
    ''' Called by SQL Server to populate a row being returned by the TVF.  Breaks apart the 
    ''' MethodInfo object into the data which will populate each column of the row being returned.
    ''' </summary>
    ''' <param name="row"></param>
    ''' <param name="name"></param>
    ''' <param name="parameters"></param>
    ''' <param name="type"></param>
    ''' <param name="routineProperties"></param>
    ''' <remarks></remarks>
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> _
    Public Shared Sub FillMethodRow(ByVal row As Object, ByRef name As String, ByRef parameters As String, _
        ByRef type As String, ByRef routineProperties As String)
        Dim methInfo As MethodInfo = CType(row, MethodInfo)

        name = methInfo.Name

        Dim sb As New StringBuilder("(")
        Dim first As Boolean = True

        Dim pi As ParameterInfo
        For Each pi In methInfo.GetParameters()
            If first Then
                first = False
            Else
                sb.Append(", ")
            End If

            sb.Append(pi.Name).Append(" ").Append(pi.ParameterType.Name)
        Next pi

        sb.Append(")")
        parameters = sb.ToString()
        type = methInfo.ReturnType.Name

        Dim attrs As Object() = methInfo.GetCustomAttributes( _
            GetType(Microsoft.SqlServer.Server.SqlMethodAttribute), True)

        If Not (attrs Is Nothing) AndAlso attrs.Length = 1 Then
            Dim attr As Microsoft.SqlServer.Server.SqlMethodAttribute _
                = CType(attrs(0), Microsoft.SqlServer.Server.SqlMethodAttribute)

            routineProperties = GetRoutineProperties(attr)
        End If
    End Sub

#End Region

#Region "internal utility functions"
    Private Sub New()
    End Sub

    ''' <summary>
    ''' Utility function to get the string representation of
    ''' routine properties on a type
    ''' </summary>
    ''' <param name="attr"></param>
    ''' <returns></returns>
    Private Shared Function GetRoutineProperties(ByVal attr As Microsoft.SqlServer.Server.SqlMethodAttribute) As String
        Dim sb As New StringBuilder()

        If attr.OnNullCall Then
            sb.Append("on_null_call ")
        End If

        If attr.IsMutator Then
            sb.Append("mutator ")
        End If

        If attr.IsDeterministic Then
            sb.Append("deterministic ")
        End If

        If attr.IsPrecise Then
            sb.Append("precise ")
        End If

        If attr.DataAccess <> Microsoft.SqlServer.Server.DataAccessKind.None Then
            sb.Append("data_access " & [Enum].GetName( _
                GetType(Microsoft.SqlServer.Server.DataAccessKind), attr.DataAccess))
        End If

        Return sb.ToString()
    End Function

    ''' <summary>
    ''' Is this a valid parameter type that can be accessible from tsql
    ''' </summary>
    ''' <param name="t"></param>
    ''' <returns></returns>
    Private Shared Function IsSqlParameterType(ByVal t As Type) As Boolean
        If validParameterTypes.ContainsKey(t) Then
            Return True
        End If

        If t.FullName.StartsWith("System.Data.SqlTypes") Then
            Return True
        End If

        If t.GetCustomAttributes( _
            GetType(Microsoft.SqlServer.Server.SqlUserDefinedTypeAttribute), _
            True).Length = 1 Then
            Return True
        End If

        Return False
    End Function

    ''' <summary>
    ''' Is the field type valid?
    ''' </summary>
    ''' <param name="f"></param>
    ''' <param name="declaringType"></param>
    ''' <returns></returns>
    Private Shared Function IsSqlField(ByVal f As FieldInfo, ByVal declaringType As Type) As Boolean
        If Not f.DeclaringType Is declaringType Then
            Return False
        End If

        Return IsSqlParameterType(f.FieldType)
    End Function

    ''' <summary>
    ''' Is the property valid to be called from tsql?
    ''' </summary>
    ''' <param name="f"></param>
    ''' <param name="declaringType"></param>
    ''' <returns></returns>
    Private Shared Function IsSqlProperty(ByVal f As PropertyInfo, ByVal declaringType As Type) As Boolean
        If Not f.DeclaringType Is declaringType Then
            Return False
        End If

        Return IsSqlParameterType(f.PropertyType)
    End Function

    ''' <summary>
    ''' Is the method valid to be called from tsql?
    ''' </summary>
    ''' <param name="m"></param>
    ''' <param name="declaringType"></param>
    ''' <returns></returns>
    Private Shared Function IsSqlMethod(ByVal m As MethodInfo, ByVal declaringType As Type) As Boolean
        If Not m.DeclaringType Is declaringType Then
            Return False
        End If

        Dim info As ParameterInfo
        For Each info In m.GetParameters()
            If Not IsSqlParameterType(info.ParameterType) Then
                Return False
            End If
        Next info

        Return IsSqlParameterType(m.ReturnType)
    End Function

    ''' <summary>
    ''' Get the udt specified by the clr type name.
    ''' </summary>
    ''' <param name="udtName"></param>
    ''' <returns></returns>
    Private Shared Function GetUdt(ByVal udtName As String) As Type
        Return Type.GetType(udtName, True)
    End Function

    ''' <summary>
    ''' Get the methods on a type
    ''' </summary>
    ''' <param name="t"></param>
    ''' <returns></returns>
    Private Shared Function GetSqlMethods(ByVal t As Type) As ArrayList
        Dim methods As MethodInfo() = t.GetMethods(BindingFlags.Instance Or BindingFlags.Public Or BindingFlags.DeclaredOnly)
        Dim temp As New ArrayList()

        Dim info As MethodInfo
        For Each info In methods
            If IsSqlMethod(info, t) Then
                temp.Add(info)
            End If
        Next info

        Return temp
    End Function

    ''' <summary>
    ''' get the properties on a type
    ''' </summary>
    ''' <param name="t"></param>
    ''' <returns></returns>
    Private Shared Function GetSqlProperties(ByVal t As Type) As ArrayList
        Dim props As PropertyInfo() = t.GetProperties(BindingFlags.Instance Or BindingFlags.Public Or BindingFlags.DeclaredOnly)
        Dim temp As New ArrayList()

        Dim info As PropertyInfo
        For Each info In props
            If IsSqlProperty(info, t) Then
                temp.Add(info)
            End If
        Next info

        Return temp
    End Function

    ''' <summary>
    ''' get the fields on a type
    ''' </summary>
    ''' <param name="t"></param>
    ''' <returns></returns>
    Private Shared Function GetSqlFields(ByVal t As Type) As ArrayList
        Dim fields As FieldInfo() = t.GetFields(BindingFlags.Instance Or BindingFlags.Public Or BindingFlags.DeclaredOnly)
        Dim temp As New ArrayList()

        Dim info As FieldInfo
        For Each info In fields
            If IsSqlField(info, t) Then
                temp.Add(info)
            End If
        Next info

        Return temp
    End Function

    ''' <summary>
    ''' readonly static used to cache frequently used information
    ''' </summary>
    Private Shared ReadOnly validParameterTypes As Hashtable = GetValidParameterTypes()

    ''' <summary>
    ''' initialize the cached mapping of valid parameter types
    ''' </summary>
    Private Shared Function GetValidParameterTypes() As Hashtable
        Dim validTypes As New Hashtable()

        validTypes(GetType(Boolean)) = True
        validTypes(GetType(Byte)) = True
        validTypes(GetType(Short)) = True
        validTypes(GetType(Char)) = True
        validTypes(GetType(Integer)) = True
        validTypes(GetType(Single)) = True
        validTypes(GetType(Long)) = True
        validTypes(GetType(Double)) = True
        validTypes(GetType(String)) = True
        validTypes(GetType(Guid)) = True

        Return validTypes
    End Function
#End Region

#Region "public utility functions"

    <Microsoft.SqlServer.Server.SqlFunction(DataAccess:=Microsoft.SqlServer.Server.DataAccessKind.Read)> _
    Public Shared Function GetFullAssemblyName(ByVal sqlName As String) As String
        Using conn As New SqlConnection("context connection=true")
            Dim cmd As SqlCommand = conn.CreateCommand()
            cmd.CommandText = "SELECT @sqlName, " _
                & "assemblyproperty(@sqlName, 'VersionMajor'), " _
                & "assemblyproperty(@sqlName, 'VersionMinor'), " _
                & "assemblyproperty(@sqlName, 'VersionBuild'), " _
                & "assemblyproperty(@sqlName, 'VersionRevision'), " _
                & "assemblyproperty(@sqlName, 'CultureInfo'), " _
                & "assemblyproperty(@sqlName, 'PublicKey'), " _
                & "assemblyproperty(@sqlName, 'Architecture');"

            cmd.Parameters.AddWithValue("@sqlName", sqlName)
            conn.Open()
            Dim rdr As SqlDataReader = cmd.ExecuteReader()
            If Not rdr.Read() Then
                Throw New ArgumentException( _
                    String.Format(System.Globalization.CultureInfo.InvariantCulture, _
                    "Assembly {0} does not exist.", sqlName))
            End If

            Dim culture As SqlString
            Dim publicKeyToken As SqlBinary

            If (rdr.IsDBNull(5)) Then
                culture = SqlString.Null
            Else
                culture = rdr.GetSqlString(5)
            End If

            If (rdr.IsDBNull(6)) Then
                publicKeyToken = SqlBinary.Null
            Else
                publicKeyToken = rdr.GetSqlBinary(6)
            End If

            Return GetAssemblyName(rdr.GetString(0), rdr.GetInt32(1), rdr.GetInt32(2), _
                rdr.GetInt32(3), rdr.GetInt32(4), culture, publicKeyToken)
        End Using
    End Function

    ''' <summary>
    ''' Helper function to return the assembly name from 
    ''' its components stored in sql metadata.
    ''' </summary>
    ''' <param name="friendlyName"></param>
    ''' <param name="majorVersion"></param>
    ''' <param name="minorVersion"></param>
    ''' <param name="build"></param>
    ''' <param name="revision"></param>
    ''' <param name="culture"></param>
    ''' <param name="publicKeyToken"></param>
    ''' <returns></returns>
    Private Shared Function GetAssemblyName(ByVal friendlyName As String, ByVal majorVersion As Integer, ByVal minorVersion As Integer, ByVal build As Integer, ByVal revision As Integer, ByVal culture As SqlString, ByVal publicKeyToken As SqlBinary) As String
        Dim sb As New StringBuilder()
        sb.Append(friendlyName).Append(","c)
        sb.Append("Version=")
        sb.Append(majorVersion).Append("."c)
        sb.Append(minorVersion).Append("."c)
        sb.Append(build).Append("."c)
        sb.Append(revision).Append(","c)
        sb.Append("Culture=")
        If (culture.IsNull) Then
            sb.Append("neutral")
        Else
            sb.Append(culture.Value)
        End If

        sb.Append(","c)
        sb.Append("PublicKeyToken=")
        If publicKeyToken.IsNull Then
            sb.Append("null")
        Else
            Dim b As Byte
            For Each b In publicKeyToken.Value
                sb.Append(b.ToString("X2", CultureInfo.InvariantCulture))
            Next b
        End If

        Return sb.ToString()
    End Function

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")> _
    Private Shared Function ToHexString(ByVal value() As Byte) As String
        If value Is Nothing Then
            Return Nothing
        End If

        Dim sb As New StringBuilder()
        Dim b As Byte

        For Each b In value
            sb.Append(b.ToString("X2", CultureInfo.InvariantCulture))
        Next b

        Return sb.ToString()
    End Function
#End Region
End Class
