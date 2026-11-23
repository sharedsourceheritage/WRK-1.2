Namespace My

    Class MyApplication

#If _MyType = "WindowsForms" Then
        'OnInitialize is used for advanced customization of the My Application Model (MyApplication).
        'Startup code for your specific application should be placed in a Startup event handler.
        <Global.System.Diagnostics.DebuggerStepThrough()> _
        Protected Overrides Function OnInitialize(ByVal commandLineArgs As System.Collections.ObjectModel.ReadOnlyCollection(Of String)) As Boolean
            'Set the splash screen timeout. 
            Me.MinimumSplashScreenDisplayTime = 2000
            Return MyBase.OnInitialize(commandLineArgs)
        End Function
#End If

    End Class

End Namespace
