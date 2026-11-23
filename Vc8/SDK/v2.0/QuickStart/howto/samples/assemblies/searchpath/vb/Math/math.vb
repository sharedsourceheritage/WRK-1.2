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
Imports Parser.Samples.Math.Parser


Module Module1

    Sub Main()
        While (True)
            Console.WriteLine("Enter a simple formula. Ex: 4+4 (or q to quit)")
            Dim formula As String = Console.ReadLine()

            If (formula = "q" Or formula = "Q") Then
                Exit While
            End If

            Dim pars As Parser.Samples.Math.Parser.Parser = New Parser.Samples.Math.Parser.Parser
            Try
                Dim argument As Arguments = pars.Parse(formula)
                'do the calc and print the results
                Dim m As Math = New Math
                Console.WriteLine(m.GetResult(Convert.ToInt32(argument.Arg1), argument.Op, Convert.ToInt32(argument.Arg2)))
            Catch ex As Exception
                Console.WriteLine(ex.Message)
            End Try

        End While
    End Sub

    Public Class Math
        Public Function GetResult(ByVal arg1 As Integer, ByVal op As Char, ByVal arg2 As Integer) As String
            Select Case op
                Case "+"
                    Return String.Format("Result: {0:G}", arg1 + arg2)
                Case "-"
                    Return String.Format("Result: {0:G}", arg1 - arg2)
                Case "*"
                    Return String.Format("Result: {0:G}", arg1 * arg2)
                Case "/"
                    Return String.Format("Result: {0:G}", arg1 / arg2)
                Case Else
                    Return "Invalid Operator: " + op
            End Select
        End Function
    End Class

End Module
