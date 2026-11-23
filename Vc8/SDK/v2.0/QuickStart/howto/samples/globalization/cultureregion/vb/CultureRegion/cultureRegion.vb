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
Imports System.Globalization

Class CultureAndRegion

    Public Shared Sub Main()

        Dim c As CultureInfo
        c = New CultureInfo("en-us")
        Console.WriteLine("The CultureInfo is set to: {0}", c.DisplayName)
        Console.WriteLine("The parent culture is: {0}", c.Parent.DisplayName)
        Console.WriteLine("The three letter ISO language name is: {0}", c.ThreeLetterISOLanguageName)
        Console.WriteLine("The default calendar for this culture is: {0}", c.Calendar.ToString())

        Console.WriteLine()

        Dim r As RegionInfo
        r = New RegionInfo("us")
        Console.WriteLine("The name of this region is: {0}", r.Name)
        Console.WriteLine("The ISO currency symbol for the region is: {0}", r.ISOCurrencySymbol)
        Console.WriteLine("Is this region metric : {0}", r.IsMetric)


        Console.WriteLine()
        Console.WriteLine()

        Dim c2 As CultureInfo
        c2 = New CultureInfo("de-ch")
        Console.WriteLine("The CultureInfo is set to: {0}", c2.DisplayName)
        Console.WriteLine("The parent culture is: {0}", c2.Parent.DisplayName)
        Console.WriteLine("The three letter ISO language name is: {0}", c2.ThreeLetterISOLanguageName)
        Console.WriteLine("The default calendar for this culture is: {0}", c2.Calendar.ToString())
        Console.WriteLine()

        Dim r2 As RegionInfo
        r2 = New RegionInfo("de")
        Console.WriteLine("The name of this region is: {0}", r2.Name)
        Console.WriteLine("The ISO currency symbol for the region is: {0}", r2.ISOCurrencySymbol)
        Console.WriteLine("Is this region metric : {0}", r2.IsMetric)

        Console.WriteLine()
        Console.WriteLine("Press Enter to continue...")
        Console.ReadLine()

    End Sub

End Class

