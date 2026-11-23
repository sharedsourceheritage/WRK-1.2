@SET VSINSTALLDIR=J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2
@SET VC8INSTALLDIR=J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8
@SET FrameworkDir=C:\WINDOWS\Microsoft.NET\Framework
@SET FrameworkVersion=v2.0.50727
@SET FrameworkSDKDir=J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\SDK\v2.0
@if "%VSINSTALLDIR%"=="" goto error_no_VSINSTALLDIR
@if "%VC8INSTALLDIR%"=="" goto error_no_VC8INSTALLDIR

@echo Setting environment for using Microsoft Visual Studio 2005 x86 tools.

@rem
@rem Root of Visual Studio IDE installed files.
@rem
@set DevEnvDir=J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\Common7\IDE

@set PATH=J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\Common7\IDE;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\BIN;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\Common7\Tools;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\Common7\Tools\bin;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\PlatformSDK\bin;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\SDK\v2.0\bin;C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\VC8Packages;%PATH%
@set INCLUDE=J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\ATLMFC\INCLUDE;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\INCLUDE;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\PlatformSDK\include;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\SDK\v2.0\include;%INCLUDE%
@set LIB=J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\ATLMFC\LIB;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\LIB;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\PlatformSDK\lib;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\SDK\v2.0\lib;%LIB%
@set LIBPATH=C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727;J:\Releases\_MICROSOFT.RESEARCH\WRK-V1.2\VC8\ATLMFC\LIB

@goto end

:error_no_VSINSTALLDIR
@echo ERROR: VSINSTALLDIR variable is not set. 
@goto end

:error_no_VC8INSTALLDIR
@echo ERROR: VC8INSTALLDIR variable is not set. 
@goto end

:end
