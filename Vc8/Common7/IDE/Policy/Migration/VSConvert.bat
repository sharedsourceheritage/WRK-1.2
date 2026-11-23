@echo off

if "%2"=="" goto parambad
goto paramgood

:parambad
echo Usage:
echo %0 [.tdl file to convert].TDL [output filename]
echo	Please do not specify the output file extension
goto exit

:paramgood

if exist "%1" goto sourcegood

echo Source TDL file "%1" not found!
goto parambad

:sourcegood


msxsl.exe 2>nul
if not "%errorlevel"=="9009" goto msxslexists

echo msxsl.exe not found.
echo
echo Please download and install msxsl.exe
goto exit

:msxslexists

if exist vspolicy.xslt goto xsltexists
echo Translation .XSLTs not found.
echo Please run %0 script from the "vspolicy/migration" directory.
goto exit

:xsltexists

echo Converting definitions...
msxsl %1 vspolicydef.xslt -o %2.vspolicydef
echo Converting actions...
msxsl %1 vspolicy.xslt DefinitionFile=%2.vspolicydef -o %2.vspolicy
echo Errors in definitions: 
msxsl %2.vspolicydef printmessages.xslt
echo Errors in actions:
msxsl %2.vspolicy printmessages.xslt

:exit