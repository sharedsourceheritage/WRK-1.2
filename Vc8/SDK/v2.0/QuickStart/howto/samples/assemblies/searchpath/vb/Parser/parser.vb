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
Namespace Samples.Math.Parser

    Public Class Arguments
        Private _arg1 As String
        Private _op As Char
        Private _arg2 As String


        Public Property Arg1() As String
            Get
                Return _arg1
            End Get
            Set(ByVal Value As String)
                _arg1 = Value
            End Set
        End Property

        Public Property Op() As Char
            Get
                Return _op
            End Get
            Set(ByVal Value As Char)
                _op = Value
            End Set
        End Property

        Public Property Arg2() As String
            Get
                Return _arg2
            End Get
            Set(ByVal Value As String)
                _arg2 = Value
            End Set
        End Property
    End Class

    Public Class Parser
        Public Function Parse(ByVal formula As String) As Arguments
            Dim args As Arguments = New Arguments
            Dim opsAndSpace() As Char = {" ", "+", "-", "*", "/"}
            Dim pos As Integer = formula.IndexOfAny(opsAndSpace)
            args.Arg1 = formula.Substring(0, pos)
            'args.Arg2 = args.Arg1

            ' skip whitespace to get the operator
            While (formula.Chars(pos) = " ")
                pos += 1
            End While
            args.Op = formula.Chars(pos)


            ' skip whitespace to get to the second arg
            pos += 1
            While (formula.Chars(pos) = " ")
                pos += 1
            End While

            ' get the second arg
            args.Arg2 = formula.Substring(pos)

            Return args
        End Function

    End Class

End Namespace

