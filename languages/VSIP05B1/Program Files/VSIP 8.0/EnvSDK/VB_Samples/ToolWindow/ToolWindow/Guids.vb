
'***************************************************************************
'         Copyright (c) Microsoft CorporationAll rights reserved.             
'    This code sample is provided "AS IS" without warranty of any kind
'    it is not recommended for use in a production environment.
'***************************************************************************/

' Guids.vb
' MUST match guid.h (for the satellite DLL)

Imports System

Namespace Microsoft.VisualStudio.VSIP.Samples.ToolWindowVB
    Class GuidList
        Private Sub New()
        End Sub

        Public Shared ReadOnly guidToolWindowPkg As Guid = New Guid("{AD5410E4-25BA-4b7a-B4F2-AEBD025B4123}")
        Public Shared ReadOnly guidToolWindowMenuGroup As Guid = New Guid("{A679A6F6-7C0C-4930-A0F9-4D687AA1DF50}")
        Public Shared ReadOnly guidToolWindowCmdSet As Guid = New Guid("{F59E33F4-BF77-4f09-9A7F-2328D5F3EEBB}")
        Public Shared guidToolWindowPersistance As Guid = New Guid("{40ED3A09-2A86-46f3-B0D3-0FD6A2513803}")
    End Class
End Namespace