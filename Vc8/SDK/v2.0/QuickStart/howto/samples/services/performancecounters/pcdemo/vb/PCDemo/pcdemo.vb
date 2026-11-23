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
Imports System.Timers
Imports System.Threading

Namespace Microsoft.Samples.Services.PerformanceCounters

    Public NotInheritable Class PCDemo

        Shared theCounter As PerformanceCounter

        Const objectName As String = "ACounterDemo"
        Const counterName As String = "CountPerSecond"
        Const instanceName As String = "_Total"

        Private Sub New()

        End Sub

        Public Shared Sub Main()
            'Get the category/counters installed...

            If Environment.GetCommandLineArgs().Length > 1 Then
                If Environment.GetCommandLineArgs()(1).StartsWith("/inst") Then
                    If (InstallCounters()) Then
                        Exit Sub
                    Else
                        Console.WriteLine("Continuing with sample...")
                    End If
                Else
                    If Environment.GetCommandLineArgs()(1).StartsWith("/del") Then
                        DeleteCounters()
                        Exit Sub
                    Else
                        ShowUsage()
                        Exit Sub
                    End If
                End If
            End If

            Try
                theCounter = New PerformanceCounter(objectName, counterName, instanceName, False)
                theCounter.RawValue = 0
            Catch E As InvalidOperationException
                Console.WriteLine("The performance counters are not installed.")
                Console.WriteLine("Please use 'pcdemo.exe /inst' to install them.")
                Exit Sub
            End Try

            Dim aTimer As New System.Timers.Timer
            AddHandler aTimer.Elapsed, AddressOf OnTimer

            aTimer.Interval = 100
            aTimer.Enabled = True
            aTimer.AutoReset = False

            Console.WriteLine("Press '+' to increase the interval")
            Console.WriteLine("Press '-' to decrease the interval")
            Console.WriteLine("Press 'q' to quit the sample")
            Console.WriteLine("Started")

            Dim command As Integer
            Do
                command = Console.Read()
                If (command = 43) Then  ' + = ASCII 43
                    aTimer.Interval = Math.Max(1, aTimer.Interval / 2)
                ElseIf (command = 45) Then ' - = ASCII 45
                    aTimer.Interval *= 2
                End If

            Loop Until command = 113
        End Sub

        ' Returns true if we install the counters...
        Private Shared Function InstallCounters() As Boolean
            Try
                If Not PerformanceCounterCategory.Exists(objectName) Then
                    Dim ccd As CounterCreationData = New CounterCreationData()
                    ccd.CounterName = counterName
                    ccd.CounterType = PerformanceCounterType.RateOfCountsPerSecond32
                    Dim ccds As New CounterCreationDataCollection
                    ccds.Add(ccd)
                    PerformanceCounterCategory.Create(objectName, "Sample Object", PerformanceCounterCategoryType.Unknown, ccds)
                    Console.WriteLine("Performance Counter has been successfully created.")
                    InstallCounters = True
                End If
            Catch E As System.UnauthorizedAccessException
                Console.WriteLine("Unable to create Performance Counter.")
                InstallCounters = False
            End Try
        End Function 'InstallCounters

        Private Shared Sub OnTimer(ByVal source As Object, ByVal e As ElapsedEventArgs)
            Try
                theCounter.IncrementBy(1)
                Dim theTimer As System.Timers.Timer = CType(source, System.Timers.Timer)
                theTimer.Enabled = True
            Catch Exc As Exception
                Console.WriteLine("You must have Administrator privelages to run this sample.")
            End Try
        End Sub

        Private Shared Sub DeleteCounters()
            Try
                If PerformanceCounterCategory.Exists(objectName) Then
                    PerformanceCounterCategory.Delete(objectName)
                    Console.Write("Category has been successfully deleted!  ")
                Else
                    Console.Write("Category not installed!  ")
                End If
            Catch E As System.UnauthorizedAccessException
                Console.WriteLine("Unable to create Performance Counter.")
            End Try
        End Sub 'DeleteCounters

        Private Shared Sub ShowUsage()
            Console.WriteLine("Usage")
            Console.WriteLine("-----")
            Console.WriteLine("To install perf counter AcounterDemo: pcdemo /inst")
            Console.WriteLine("To apply changes to perf counter AcounterDemo: pcdemo")
            Console.WriteLine("To delete perf counter AcounterDemo: pcdemo /del")
        End Sub 'ShowUsage 
    End Class
End Namespace