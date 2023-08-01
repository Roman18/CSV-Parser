@echo off

rem md target 2> nul
rem cd src


rem List of sources
set SRC=src\*.cpp


rem Compilation flags
set CFLAGS=-Wall -Wextra

rem Place to put the build
set RESULT=target\csv.exe

g++.exe -o %RESULT% %SRC% %CFLAGS%