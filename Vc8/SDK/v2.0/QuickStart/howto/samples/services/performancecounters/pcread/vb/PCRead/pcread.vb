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

Imports System
Imports System.Diagnostics
Imports System.Threading
Imports System.Timers
Imports Microsoft.VisualBasic
Imports System.Globalization

Namespace Microsoft.Samples

    Public NotInheritable Class PCRead
        Shared objectName As String
        Shared counterName As String
        Shared instanceName As String
        Shared theCounter As PerformanceCounter

        Private Sub New()

        End Sub

        Public Shared Sub Main()
            Dim appName As String = Environment.GetCommandLineArgs()(0)

            If (Environment.GetCommandLineArgs().Length <> 4 And Environment.GetCommandLineArgs().Length <> 3) Then
                Console.WriteLine("Usage: {0} <object> <counter> [<instance>]", appName)
                Exit Sub
            End If

            objectName = Environment.GetCommandLineArgs()(1)
            counterName = Environment.GetCommandLineArgs()(2)
            instanceName = ""
            If (Environment.GetCommandLineArgs().Length = 4) Then
                instanceName = Environment.GetCommandLineArgs()(3)
            End If

            objectName = objectName.Trim()
            counterName = counterName.Trim()
            instanceName = instanceName.Trim()

            If (Not PerformanceCounterCategory.Exists(objectName)) Then
                Console.WriteLine("Object {0} does not exists!", objectName)
                Exit Sub
            End If

            If (Not PerformanceCounterCategory.CounterExists(counterName, objectName)) Then
                Console.WriteLine("Counter {0} does not exists!", counterName)
                Exit Sub
            End If

            theCounter = New PerformanceCounter(objectName, counterName, instanceName)

            Dim aTimer As System.Timers.Timer = New System.Timers.Timer()
            AddHandler aTimer.Elapsed, AddressOf OnTimer

            aTimer.Interval = 500
            aTimer.Enabled = True
            aTimer.AutoReset = False

            Console.WriteLine("Press 'q' and hit Enter to quit the sample")
            While (Console.Read() <> 113)
            End While
        End Sub

        Private Shared Sub OnTimer(ByVal source As Object, ByVal e As ElapsedEventArgs)
            Try
                Console.WriteLine("Current value =  " + theCounter.NextValue().ToString(CultureInfo.InvariantCulture))
            Catch
                Console.WriteLine("Instance {0} does not exist!", instanceName)
                Exit Sub
            End Try

            Dim theTimer As System.Timers.Timer = CType(source, System.Timers.Timer)
            theTimer.Enabled = True
        End Sub
    End Class
End Namespace