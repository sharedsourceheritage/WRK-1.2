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
imports System.Runtime.InteropServices
Imports SHDocVw

Namespace Microsoft.Samples.Interop.TestClient

    Public NotInheritable Class Test

        Private Sub New()
        End Sub

        Public Shared Sub Main()

            Dim explorer As SHDocVw.InternetExplorer
            Dim webBrowser As SHDocVw.IWebBrowserApp

            explorer = New SHDocVw.InternetExplorer
            webBrowser = explorer

            webBrowser.Visible = True
            webBrowser.GoHome()

            Console.WriteLine("Press Enter to quit")
            Dim s As String = Console.ReadLine

            Try
                webBrowser.Quit()
            Catch e As COMException
                Console.WriteLine("Explorer closed")
            End Try

        End Sub
    End Class
End Namespace


