@SET VSINSTALLDIR=c:\Program Files\Microsoft Visual Studio 8
@SET VCINSTALLDIR=c:\Program Files\Microsoft Visual Studio 8\VC
@SET FrameworkDir=c:\WINDOWS\Microsoft.NET\Framework
@SET FrameworkVersion=v2.0.50727
@SET FrameworkSDKDir=c:\Program Files\Microsoft Visual Studio 8\SDK\v2.0
@if "%VSINSTALLDIR%"=="" goto error_no_VSINSTALLDIR
@if "%VCINSTALLDIR%"=="" goto error_no_VCINSTALLDIR

@echo Setting environment for using Microsoft Visual Studio 2005 x64 cross tools.

@rem
@rem Root of Visual Studio IDE installed files.
@rem
@set DevEnvDir=c:\Program Files\Microsoft Visual Studio 8\Common7\IDE

@set PATH=c:\Program Files\Microsoft Visual Studio 8\Common7\IDE;c:\Program Files\Microsoft Visual Studio 8\VC\BIN\x86_amd64;c:\Program Files\Microsoft Visual Studio 8\VC\BIN;c:\Program Files\Microsoft Visual Studio 8\Common7\Tools;c:\Program Files\Microsoft Visual Studio 8\Common7\Tools\bin;c:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\bin;c:\WINDOWS\Microsoft.NET\Framework\v2.0.50727;c:\Program Files\Microsoft Visual Studio 8\VC\VCPackages;c:\Program Files\Microsoft Visual Studio 8\SDK\v2.0\bin;%PATH%
@set INCLUDE=c:\Program Files\Microsoft Visual Studio 8\VC\ATLMFC\INCLUDE;c:\Program Files\Microsoft Visual Studio 8\VC\INCLUDE;c:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\include;c:\Program Files\Microsoft Visual Studio 8\SDK\v2.0\include;%INCLUDE%
@set LIB=c:\Program Files\Microsoft Visual Studio 8\VC\ATLMFC\LIB\amd64;c:\Program Files\Microsoft Visual Studio 8\VC\LIB\amd64;c:\Program Files\Microsoft Visual Studio 8\VC\PlatformSDK\lib\amd64;c:\Program Files\Microsoft Visual Studio 8\SDK\v2.0\LIB\AMD64;%LIB%

@set LIBPATH=c:\Program Files\Microsoft Visual Studio 8\VC\ATLMFC\LIB\amd64;%LIBPATH%

@goto end

:error_no_VSINSTALLDIR
@echo ERROR: VSINSTALLDIR variable is not set. 
@goto end

:error_no_VCINSTALLDIR
@echo ERROR: VCINSTALLDIR variable is not set. 
@goto end

:end
