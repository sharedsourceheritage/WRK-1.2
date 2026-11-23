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
Imports System.ServiceProcess

Namespace Microsoft.Samples
    Public NotInheritable Class SimpleService
        Inherits System.ServiceProcess.ServiceBase

#Region " Component Designer generated code "


        Public Sub New()
            MyBase.New()
            CanPauseAndContinue = True

            ' This call is required by the Component Designer.
            InitializeComponent()

            ' Add any initialization after the InitializeComponent() call
            ServiceName = "Hello-World Service"
            Timer.Interval = 1000
            AddHandler Timer.Elapsed, AddressOf OnTimer
        End Sub

        'UserService overrides dispose to clean up the component list.
        Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
            If disposing Then
                If Not (components Is Nothing) Then
                    components.Dispose()
                End If
            End If
            MyBase.Dispose(disposing)
        End Sub

        ' The main entry point for the process
        <MTAThread()> _
        Shared Sub Main()
            Dim ServicesToRun() As System.ServiceProcess.ServiceBase

            ' More than one NT Service may run within the same process. To add
            ' another service to this process, change the following line to
            ' create a second service object. For example,
            '
            '   ServicesToRun = New System.ServiceProcess.ServiceBase () {New Service1, New MySecondUserService}
            '
            ServicesToRun = New System.ServiceProcess.ServiceBase() {New SimpleService}

            System.ServiceProcess.ServiceBase.Run(ServicesToRun)
        End Sub

        'Required by the Component Designer
        Private components As System.ComponentModel.IContainer

        ' NOTE: The following procedure is required by the Component Designer
        ' It can be modified using the Component Designer.  
        ' Do not modify it using the code editor.
        Friend WithEvents Timer As System.Timers.Timer
        <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
            Me.Timer = New System.Timers.Timer
            CType(Me.Timer, System.ComponentModel.ISupportInitialize).BeginInit()
            '
            'Timer
            '
            Me.Timer.Enabled = True
            CType(Me.Timer, System.ComponentModel.ISupportInitialize).EndInit()

        End Sub

#End Region

        Protected Overrides Sub OnStart(ByVal args() As String)
            EventLog.WriteEntry("Hello-World Service started")
            Timer.Enabled = True
        End Sub

        Protected Overrides Sub OnStop()
            EventLog.WriteEntry("Hello-World Service stopped")
            Timer.Enabled = False
        End Sub

        Protected Overrides Sub OnPause()
            EventLog.WriteEntry("Hello-World Service paused")
            Timer.Enabled = False
        End Sub

        Protected Overrides Sub OnContinue()
            EventLog.WriteEntry("Hello-World Service continued")
            Timer.Enabled = True
        End Sub

        Protected Friend Sub OnTimer(ByVal source As Object, ByVal e As Timers.ElapsedEventArgs)
            EventLog.WriteEntry("Hello World!")
        End Sub
    End Class
End Namespace