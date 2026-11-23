'-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET Framework SDK Code Samples.
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

imports System
imports System.Text
imports Microsoft.VisualBasic
imports System.Runtime.InteropServices

Namespace Microsoft.Samples
    <CLSCompliant(False)> _
    <StructLayout(LayoutKind.Sequential)> Public Structure SystemTime
        Private _year As Short
        Private _month As Short
        Private _dayOfWeek As Short
        Private _day As Short
        Private _hour As Short
        Private _minute As Short
        Private _second As Short
        Private _milliseconds As Short

        Public ReadOnly Property Year() As Short
            Get
                Return _year
            End Get
        End Property
        Public ReadOnly Property Month() As Short
            Get
                Return _month
            End Get
        End Property
        Public ReadOnly Property DayOfWeek() As Short
            Get
                Return _dayOfWeek
            End Get
        End Property
        Public ReadOnly Property Day() As Short
            Get
                Return _day
            End Get
        End Property
        Public ReadOnly Property Hour() As Short
            Get
                Return _hour
            End Get
        End Property
        Public ReadOnly Property Minute() As Short
            Get
                Return _minute
            End Get
        End Property
        Public ReadOnly Property Second() As Short
            Get
                Return _second
            End Get
        End Property
        Public ReadOnly Property Milliseconds() As Short
            Get
                Return _milliseconds
            End Get
        End Property

        Public Overrides Function Equals(ByVal obj As Object) As Boolean
            If obj Is GetType(SystemTime) Then
                Dim sysTime As SystemTime = obj

                If sysTime.Year = _year And sysTime.Month = _month And _
                        sysTime.DayOfWeek = _dayOfWeek And sysTime.Day = _day And _
                        sysTime.Hour = _hour And sysTime.Minute = _minute And _
                        sysTime.Second = _second And sysTime.Milliseconds = _milliseconds Then
                    Return True
                End If
            End If

            Return False
        End Function

        Public Overrides Function GetHashCode() As Integer
            Return _year Xor _month Xor _dayOfWeek Xor _day Xor _hour Xor _minute Xor _second Xor _milliseconds
        End Function

    End Structure

    Friend NotInheritable Class NativeMethods
        Private Sub New()

        End Sub

        Declare Auto Sub GetSystemTime Lib "Kernel32.dll" (ByRef sysTime As SystemTime)

        Declare Auto Function MsgBox Lib "User32.dll" Alias "MessageBox" _
        (ByVal hWnd As Integer, ByVal txt As String, ByVal caption As String, ByVal Typ As Integer) As Integer
    End Class

    Public NotInheritable Class TestPInvoke
        Private Sub New()

        End Sub

        Public Shared Sub Main()
            Dim sysTime As New SystemTime
            NativeMethods.GetSystemTime(sysTime)

            Dim dt As String
            dt = String.Format("System time is: Year: {0} Month: {1} DayOfWeek: {2} Day: {3}", _
                sysTime.Year, _
                sysTime.Month, _
                sysTime.DayOfWeek, _
                sysTime.Day)

            NativeMethods.MsgBox(0, dt, "Platform Invoke Sample", 0)
        End Sub
    End Class
End Namespace