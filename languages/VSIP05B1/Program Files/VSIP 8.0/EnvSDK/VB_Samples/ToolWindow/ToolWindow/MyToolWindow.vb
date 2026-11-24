Imports System.Windows.Forms
Imports System.Runtime.InteropServices
Imports Microsoft.VisualStudio.Shell.Interop
Imports OLEInterop = Microsoft.VisualStudio.OLE.Interop
Imports MSVSIP = Microsoft.VisualStudio.Shell

Namespace Microsoft.VisualStudio.VSIP.Samples.ToolWindowVB

    Public Class MyUserControl
        Inherits System.Windows.Forms.UserControl

#Region " Windows Form Designer generated code "

        Public Sub New()
            MyBase.New()

            'This call is required by the Windows Form Designer.
            InitializeComponent()
        End Sub

        'UserControl overrides dispose to clean up the component list.
        Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
            If disposing Then
                If Not (components Is Nothing) Then
                    components.Dispose()
                End If
            End If
            MyBase.Dispose(disposing)
        End Sub

        Protected Overrides Function ProcessDialogChar(ByVal charCode As Char) As Boolean
            If charCode <> "" And ProcessMnemonic(charCode) Then
                Return True
            End If
            Return MyBase.ProcessDialogChar(charCode)
        End Function

        'Required by the Windows Form Designer
        Private components As System.ComponentModel.IContainer

        'NOTE: The following procedure is required by the Windows Form Designer
        'It can be modified using the Windows Form Designer.  
        'Do not modify it using the code editor.
        Friend WithEvents Button1 As System.Windows.Forms.Button
        <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
            Me.Button1 = New System.Windows.Forms.Button
            Me.SuspendLayout()
            '
            'Button1
            '
            Me.Button1.Anchor = CType((((System.Windows.Forms.AnchorStyles.Top Or System.Windows.Forms.AnchorStyles.Bottom) _
                        Or System.Windows.Forms.AnchorStyles.Left) _
                        Or System.Windows.Forms.AnchorStyles.Right), System.Windows.Forms.AnchorStyles)
            Me.Button1.BackColor = System.Drawing.SystemColors.Control
            Me.Button1.Location = New System.Drawing.Point(40, 32)
            Me.Button1.Name = "Button1"
            Me.Button1.Size = New System.Drawing.Size(75, 80)
            Me.Button1.TabIndex = 0
            Me.Button1.Text = "&Click Me!"
            '
            'MyToolWindow
            '
            Me.BackColor = System.Drawing.SystemColors.ActiveCaptionText
            Me.Controls.Add(Me.Button1)
            Me.Name = "MyToolWindow"
            Me.ResumeLayout(False)

        End Sub

        Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
            MessageBox.Show(Me, _
                String.Format("We are inside {0}.Button1_Click()", Me.ToString()), _
                "Managed Tool Window (VB)")
        End Sub

#End Region

    End Class

    <Guid("40ED3A09-2A86-46f3-B0D3-0FD6A2513803")> _
    Public Class MyToolWindow
        Inherits Microsoft.VisualStudio.Shell.ToolWindowPane

        Private myUserControl As MyUserControl

        Public Sub New()
            MyBase.New(Nothing)
            Caption = "Managed Tool Window (VB)"
            myUserControl = New MyUserControl()
        End Sub

        Public Overrides ReadOnly Property Window() As System.Windows.Forms.IWin32Window
            Get
                Return myUserControl
            End Get
        End Property

        Protected Overrides Sub Dispose(ByVal disposing As Boolean)
            If disposing Then
                Dim windowFrame As IVsWindowFrame = Me.Frame()
                If Not windowFrame Is Nothing Then
                    windowFrame.CloseFrame(CType(__FRAMECLOSE.FRAMECLOSE_SaveIfDirty, UInteger))
                End If
            End If
        End Sub

    End Class
End Namespace