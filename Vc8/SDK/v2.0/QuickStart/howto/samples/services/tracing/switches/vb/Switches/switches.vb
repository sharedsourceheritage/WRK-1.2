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
Imports System.IO

Namespace Microsoft.Samples.Tracing.Switches

    Public NotInheritable Class Switches

        Private Sub New()

        End Sub
        Public Shared Sub Main()
            ' setup listeners
            SetupListeners()

            ' setup switches
            Dim boolSwitch As BooleanSwitch = New BooleanSwitch("ABooleanSwitch", "Demo bool switch")
            Dim traceSwitch As TraceSwitch = New TraceSwitch("ATraceSwitch", "Demo trace switch")

            Debug.WriteLine("The app was compiled with DEBUG directive!")
            Trace.WriteLine("The app was compiled with TRACE directive!")

            Trace.WriteLineIf(boolSwitch.Enabled, "This is controlled by boolSwitch!")

            Trace.WriteLineIf(traceSwitch.TraceError, "This is controlled by traceSwitch.Error!")
            Trace.WriteLineIf(traceSwitch.TraceWarning, "This is controlled by traceSwitch.Warning!")
            Trace.WriteLineIf(traceSwitch.TraceInfo, "This is controlled by traceSwitch.Info!")
            Trace.WriteLineIf(traceSwitch.TraceVerbose, "This is controlled by traceSwitch.Verbose!")
            Trace.Close()
        End Sub

        Public Shared Sub SetupListeners()
            Try
                Debug.Listeners.Add(New TextWriterTraceListener(Console.Out))

                Debug.Listeners.Add(New TextWriterTraceListener(File.Create("output.txt")))
                If (Not EventLog.SourceExists("SwitchesDemo")) Then
                    EventLog.CreateEventSource("SwitchesDemo", "SwitchesDemo")
                End If
                Debug.Listeners.Add(New EventLogTraceListener("SwitchesDemo"))

            Catch uae As UnauthorizedAccessException
                Console.WriteLine("Insufficient permissions to setup all listeners: " & uae.Message)
            End Try
        End Sub
    End Class
End Namespace 'Microsoft.Samples