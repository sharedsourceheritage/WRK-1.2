@SET VSINSTALLDIR=J:\SphinxLogic\_git\OS\WRK-V1.2\
@SET VCINSTALLDIR=J:\SphinxLogic\_git\OS\WRK-V1.2\VC8
@SET FrameworkDir=C:\WINDOWS\Microsoft.NET\Framework
@SET FrameworkVersion=v2.0.50727
@SET FrameworkSDKDir=J:\SphinxLogic\_git\OS\WRK-V1.2\SDK\v2.0
@if "%VSINSTALLDIR%"=="" goto error_no_VSINSTALLDIR
@if "%VCINSTALLDIR%"=="" goto error_no_VCINSTALLDIR

@echo Setting environment for using Microsoft Visual Studio 2005 x86 tools.

@rem
@rem Root of Visual Studio IDE installed files.
@rem
@set DevEnvDir=J:\SphinxLogic\_git\OS\WRK-V1.2\Common7\IDE

@set PATH=J:\SphinxLogic\_git\OS\WRK-V1.2\Common7\IDE;J:\SphinxLogic\_git\OS\WRK-V1.2\VC8\BIN;J:\SphinxLogic\_git\OS\WRK-V1.2\Common7\Tools;J:\SphinxLogic\_git\OS\WRK-V1.2\Common7\Tools\bin;J:\SphinxLogic\_git\OS\WRK-V1.2\VC8\PlatformSDK\bin;J:\SphinxLogic\_git\OS\WRK-V1.2\SDK\v2.0\bin;C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727;J:\SphinxLogic\_git\OS\WRK-V1.2\VC8\VCPackages;%PATH%
@set INCLUDE=J:\SphinxLogic\_git\OS\WRK-V1.2\VC8\ATLMFC\INCLUDE;J:\SphinxLogic\_git\OS\WRK-V1.2\VC8\INCLUDE;J:\SphinxLogic\_git\OS\WRK-V1.2\VC8\PlatformSDK\include;J:\SphinxLogic\_git\OS\WRK-V1.2\SDK\v2.0\include;%INCLUDE%
@set LIB=J:\SphinxLogic\_git\OS\WRK-V1.2\VC8\ATLMFC\LIB;J:\SphinxLogic\_git\OS\WRK-V1.2\VC8\LIB;J:\SphinxLogic\_git\OS\WRK-V1.2\VC8\PlatformSDK\lib;J:\SphinxLogic\_git\OS\WRK-V1.2\SDK\v2.0\lib;%LIB%
@set LIBPATH=C:\WINDOWS\Microsoft.NET\Framework\v2.0.50727;J:\SphinxLogic\_git\OS\WRK-V1.2\VC\ATLMFC\LIB

@goto end

:error_no_VSINSTALLDIR
@echo ERROR: VSINSTALLDIR variable is not set. 
@goto end

:error_no_VCINSTALLDIR
@echo ERROR: VCINSTALLDIR variable is not set. 
@goto end

:end
