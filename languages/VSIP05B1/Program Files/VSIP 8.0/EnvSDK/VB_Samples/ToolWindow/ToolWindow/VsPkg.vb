'***************************************************************************
'         Copyright (c) Microsoft Corporation, All rights reserved.             
'    This code sample is provided "AS IS" without warranty of any kind, 
'    it is not recommended for use in a production environment.
'***************************************************************************'

' VsPkg.vb : Implementation of ToolWindow
'
Imports System
Imports System.Diagnostics
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.ComponentModel.Design
Imports ShellInterop = Microsoft.VisualStudio.Shell.Interop
Imports OLEInterop = Microsoft.VisualStudio.OLE.Interop
Imports MSVSIP = Microsoft.VisualStudio.Shell

Namespace Microsoft.VisualStudio.VSIP.Samples.ToolWindowVB
    '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    ' CBscPkgPackage

    'Some alternate InstalledProductRegistration attributes
    <MSVSIP.DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0Exp"), _
    MSVSIP.ProvideMenuResource(1000, 1), _
    MSVSIP.RegisterLoadKey("Standard", "8.0", "Managed Tool Window (VB)", "Microsoft", 1), _
    MSVSIP.InstalledProductRegistration(ProductNameResId:=100, ProductDetailsResId:=102, IconResId:=103, ProductID := "8.0"), _
    MSVSIP.ProvideToolWindow(GetType(MyToolWindow)), _
    Guid("AD5410E4-25BA-4b7a-B4F2-AEBD025B4123")> _
    Public Class VBToolWindow : Inherits MSVSIP.Package
        Public Sub New()
            Trace.WriteLine(String.Format("Entering constructor for: {0}", Me.ToString()))
        End Sub


        Private Sub ShowToolWindow(ByVal sender As Object, ByVal e As EventArgs)
            Dim window As MSVSIP.ToolWindowPane = FindToolWindow(GetType(MyToolWindow), 0, True)
            If (Not window Is Nothing) And (Not window.Frame Is Nothing) Then
                windowFrame = CType(window.Frame, Microsoft.VisualStudio.Shell.Interop.IVsWindowFrame)
            End If
            If Not windowFrame Is Nothing Then
                NativeMethods.ThrowOnFailure(windowFrame.Show())
            End If
        End Sub

        Protected Overrides Sub Initialize()
            MyBase.Initialize()

            ' Get the command service to add this package's commands
            Dim mcs As MSVSIP.OleMenuCommandService = CType(GetService(GetType(IMenuCommandService)), MSVSIP.OleMenuCommandService)
            If Not mcs Is Nothing Then
                Dim cmd As CommandID = New CommandID(GuidList.guidToolWindowCmdSet, PkgCmdIDList.icmdMyTool)
                Dim command As MenuCommand = New MenuCommand(New EventHandler(AddressOf ShowToolWindow), cmd)
                command.Visible = True
                command.Enabled = True
                command.Supported = True
                mcs.AddCommand(command)
            End If
        End Sub

        Protected Overloads Sub Dispose(ByVal disposing As Boolean)
            Trace.WriteLine(String.Format("Entering Dispose for: {0}", Me.ToString()))

            MyBase.Dispose(disposing)
        End Sub




        '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
        '' ToolWindow Fields
        Private windowFrame As ShellInterop.IVsWindowFrame
    End Class

End Namespace