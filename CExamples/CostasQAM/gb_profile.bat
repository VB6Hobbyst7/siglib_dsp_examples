@echo off

rem Batch file for building and executing client application with GCC
rem This build uses the static library, release model

gcc %1.c -Wall -Wno-main -std=c99 -pg -l siglib -l gnuplot_c -l nhl -o %1.exe
rem del *.o
