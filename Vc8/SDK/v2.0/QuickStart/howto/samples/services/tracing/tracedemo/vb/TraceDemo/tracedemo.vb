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

' You need to create a configuration file (TraceDemo.exe.config) with the
' following code to view the trace messages:
'
' <?xml version="1.0" encoding="UTF-8" ?>
' <configuration>
'     <system.diagnostics>
'         <switches>
'             <!-- Set value property of the TraceMethods switch to one of the following:
'                  0 (false) or 1 (true) -->
'             <add name="TraceMethods" value="1" />
' 
'             <!-- Set value property of the Arithmetic switch to one of the following:
'                  1(error), 2(warning), 3(info), 4(verbose) -->
'             <add name="Arithmetic" value="4" />
'         </switches>
'         <trace autoflush="false" indentsize="4" />
'     </system.diagnostics>
' </configuration>

Namespace Microsoft.Samples

    Public NotInheritable Class TraceDemo
        Shared traceMethods As BooleanSwitch
        Shared arithmeticSwitch As TraceSwitch

        Private Sub New()

        End Sub

        Public Shared Sub Main()
            Debug.Listeners.Add(New TextWriterTraceListener(Console.Out))
            traceMethods = New BooleanSwitch("TraceMethods", "TraceDemo Method Tracing Switch")
            arithmeticSwitch = New TraceSwitch("Arithmetic", "Arithmetic Operations")

            Dim a As Integer
            Dim b As Integer
            For a = 0 To 4
                For b = 0 To 4
                    Console.WriteLine(CStr(a) + "/" + CStr(b) + "=" + CStr(Percent(a, b)))
                Next b
            Next a
        End Sub

        Public Shared Function Divide(ByVal a As Int64, ByVal b As Int64) As Int64
            If (traceMethods.Enabled) Then
                Trace.WriteLine("Divide(" + CStr(a) + "," + CStr(b) + ") called")
            End If

            If (b = 0) Then
                Trace.WriteLineIf(arithmeticSwitch.TraceWarning, "!!!!!!!!!!!!!!!!!!Division by 0!!!!!!!!!!!!!!!!")
                b = 1
            End If

            Dim ratio As Int64 = CType(a / b, Int64)

            If (traceMethods.Enabled) Then
                Trace.WriteLine("Divide(" + CStr(a) + "," + CStr(b) + ") returns " + CStr(ratio))
            End If
            Divide = ratio
        End Function

        Public Shared Function Percent(ByVal a As Int64, ByVal b As Int64) As Int64
            If (traceMethods.Enabled) Then
                Trace.WriteLine("Percent(" + CStr(a) + "," + CStr(b) + ") called")
            End If

            Dim percentResult As Int64 = CType(Divide(100 * a, b), Int64)

            If (traceMethods.Enabled) Then
                Trace.WriteLine("Percent(" + CStr(a) + "," + CStr(b) + ") returns " + CStr(percentResult))
            End If
            Percent = percentResult
        End Function
    End Class

End Namespace