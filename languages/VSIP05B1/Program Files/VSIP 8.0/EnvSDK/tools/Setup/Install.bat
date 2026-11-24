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
if "%DevEnvDir%" == "" (
    @Echo ERROR: Can't find the installation folder for VisualStudio .NET Whidbey
    exit /b 0
)

:: Update the VSIPHelper project file to refer to VS DLLs in the correct location
call SetVsRef.bat "%BatchDir%\..\..\.."

popd
