@echo off

@if not "%MINGW_ROOT%" == "" (@set "PATH=%PATH%;%MINGW_ROOT%")

cd .

if "%1"=="" ("C:\PROGRA~1\MATLAB\R2019b\bin\win64\gmake"  -f Traditional_MPC_MMC_qudratic.mk all) else ("C:\PROGRA~1\MATLAB\R2019b\bin\win64\gmake"  -f Traditional_MPC_MMC_qudratic.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1
