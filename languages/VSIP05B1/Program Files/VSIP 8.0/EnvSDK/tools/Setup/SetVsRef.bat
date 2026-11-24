:: Check that VS is installed on this machine
if "%VS80COMNTOOLS%" == "" (
    @echo ERROR: VisualStudio .NET Whidbey is not installed on this machine.
    exit /b 1
)
:: Setup the VisualStudio environment if needed
if "%DevEnvDir%" == "" call "%VS80COMNTOOLS%\vsvars32.bat"

Set ReplaceTokens=%~dp0ReplaceTokens
Set VSIPinstall=%~dpnx1
Set TemplatesDir=%VSIPinstall%\EnvSDK\Tools\Wizards\Templates
Set EnvSDKdir=%VSIPInstall%\EnvSDK

REM **********************
:REPLACETOKEN
call :DoTokensReplace "%EnvSDKdir%\CS_Samples\AutoExtender\AutoExtender\AutoExtender.csproj"

REM **********************
REM Copy some Wizard files in the Extensibility Projects folder
Copy "%TemplatesDir%\Vs\*"    "%DevEnvDir%\Extensibility Projects\"

:ExitBatch
exit /b 0



:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
::  Procedure to replace the tokens
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
:DoTokensReplace
Set  FileIn=%~dpnx1
Set  TempFile=%temp%\__TokenReplace.tmp
echo processing: %FileIn%
copy /y "%FileIn%" "%TempFile%"
"%ReplaceTokens%" VsDir "%DevEnvDir%" < "%TempFile%" > "%FileIn%
del "%TempFile%"
goto :EOF
