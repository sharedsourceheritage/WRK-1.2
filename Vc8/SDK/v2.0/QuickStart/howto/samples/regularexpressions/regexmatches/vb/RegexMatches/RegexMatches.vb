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
Imports System.Text.RegularExpressions

Namespace Microsoft.Samples
    Public NotInheritable Class RegexMatcherMulti

        Private Sub New()

        End Sub

        Shared Sub Main()
            Dim DigitRegex As Regex = New Regex("(?<number>\d+)")
            Dim S As String = "abc 123 def 456 ghi 789"
            Dim Args As String() = Environment.GetCommandLineArgs()

            If Args.Length > 1 Then
                S = String.Join(" ", Args, 1, Args.Length - 1)
            End If

            Dim Mc As MatchCollection = DigitRegex.Matches(S)

            If Mc.Count > 0 Then
                System.Console.WriteLine("Digits:")
                Dim M As Match
                For Each M In Mc
                    System.Console.WriteLine("  " & M.Value)
                Next
            Else
                System.Console.WriteLine("[" & S & "] contains no numbers.")
            End If

            System.Console.WriteLine()
            System.Console.WriteLine("Press Enter to Continue...")
            System.Console.ReadLine()
        End Sub
    End Class
End Namespace
