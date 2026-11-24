@Echo off
SetLocal

Set BatchDir=%~dp0
pushd "%BatchDir%"

:: Check that VS is installed on this machine
if "%VS80COMNTOOLS%" == "" (
	@echo ERROR: VisualStudio .NET Whidbey is not installed on this machine.
	exit /b 0
)
if not exist "%VS80COMNTOOLS%\vsvars32.bat" (
	@echo ERROR: VisualStudio .NET Whidbey is not installed on this machine.
	exit /b 0
)
:: Setup the VisualStudio environment if needed
if "%DevEnvDir%" == "" call "%VS80COMNTOOLS%\vsvars32.bat"



if exist "%DevEnvDir%\Extensibility Projects\Vsip Wizards.vsdir"   del "%DevEnvDir%\Extensibility Projects\Vsip Wizards.vsdir"
if exist "%DevEnvDir%\Extensibility Projects\Language Package.ico" del "%DevEnvDir%\Extensibility Projects\Language Package.ico"
if exist "%DevEnvDir%\Extensibility Projects\Language Package.vsz" del "%DevEnvDir%\Extensibility Projects\Language Package.vsz"
if exist "%DevEnvDir%\Extensibility Projects\Visual Studio Integration Package.ico" del "%DevEnvDir%\Extensibility Projects\Visual Studio Integration Package.ico"
if exist "%DevEnvDir%\Extensibility Projects\Visual Studio Integration Package.vsz" del "%DevEnvDir%\Extensibility Projects\Visual Studio Integration Package.vsz"

popd
