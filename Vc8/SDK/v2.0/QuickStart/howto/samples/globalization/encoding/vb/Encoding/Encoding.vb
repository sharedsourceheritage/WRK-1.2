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
Imports System.IO
Imports System.Text

Class CultureAndRegion

    Public Shared Sub Main()

        ' Create a text file for this example
        Console.WriteLine("Creating text.txt")
        Dim fs As FileStream
        fs = New FileStream("text.txt", FileMode.OpenOrCreate)

        Console.WriteLine("Writing UTF8")
        Dim t As StreamWriter
        t = New StreamWriter(fs, Encoding.UTF8)
        t.WriteLine("This is in UTF8")
        t.Flush()

        Console.WriteLine("Writing Unicode")
        Dim t2 As StreamWriter
        t2 = New StreamWriter(fs, Encoding.Unicode)
        t2.WriteLine("This is in Unicode")
        t2.Flush()

        Console.WriteLine("Writing Ascii")
        Dim t3 As StreamWriter
        t3 = New StreamWriter(fs, Encoding.ASCII)
        t3.WriteLine("This is in ASCII")
        t3.Flush()

        ' Note that UTF-8 would be preferred as different systems or user settings
        ' could cause different Encoding.Default behaviors.  Additionally, Encoding.Default
        ' could lose or change data, whereas UTF-8 would be lossless.
        Console.Write("Writing Your Default Code Page ")
        Console.WriteLine(Encoding.Default.EncodingName)
        Dim t4 As StreamWriter
        t4 = New StreamWriter(fs, Encoding.Default)
        t4.Write("This is in your default code page ")
        t4.WriteLine(Encoding.Default.EncodingName)
        t4.Flush()

        fs.Close()

        Console.WriteLine()
        Console.WriteLine("Press Enter to continue...")
        Console.ReadLine()
    End Sub

End Class
