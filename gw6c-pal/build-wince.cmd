@ECHO OFF
REM *************************************************************************
REM * $Id: build-wince.cmd,v 1.1 2007/10/17 15:33:16 cnepveu Exp $
REM *
REM * Batch file used to build the Gateway6 Client PAL.
REM *
REM * Prerequisites:
REM *  - Visual Studio 2005 (SP1)
REM *  - Windows Embedded CE (5 or 6) SDK
REM *  - DEVENV executable in %PATH%
REM *
REM * Usage:
REM *   build-wince [/Release /Debug]
REM *
REM *************************************************************************


REM Defaults:
SET CONFIGURATION=Release
SET PLATFORM=
SET COMMAND=Build


REM Overrides:
:ParseArgs
IF /I "%~1" == "/?"             GOTO Usage
IF /I "%~1" == "-h"             GOTO Usage
IF /I "%~1" == "/Release"       SET CONFIGURATION=Release& SHIFT& GOTO ParseArgs
IF /I "%~1" == "/Debug"         SET CONFIGURATION=Debug& SHIFT& GOTO ParseArgs
IF /I "%~1" == "/Clean"         SET COMMAND=Clean& SHIFT& GOTO ParseArgs
IF    "%~1" EQU ""              GOTO Done_Args
ECHO Unknown command-line switch: %~1
GOTO Usage
:Done_Args


REM Build the target
ECHO Launching build of gw6c-pal solution...
ECHO Configuration: COMMAND=%COMMAND% CONFIGURATION=%CONFIGURATION%
ECHO.
DEVENV platform\wince\gw6c-pal.sln /%COMMAND% "%CONFIGURATION%"
IF %ERRORLEVEL% == 0 GOTO build_ok
GOTO build_error


:Usage
ECHO.
ECHO Usage:
ECHO   %0 ^[^/Release^|^/Debug^] ^[^/Clean^]
ECHO.
ECHO   Defaults: ^/Release
ECHO.
GOTO the_end


:build_ok
ECHO.
ECHO Build of gw6c-pal solution completed successfully.
GOTO the_end

:build_error
ECHO.
ECHO Build of gw6c-pal solution FAILED!

:the_end

