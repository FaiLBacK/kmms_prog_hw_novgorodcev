@echo off
chcp 1251 > nul
chcp 65001 > nul

set EXE=program.exe

if exist %EXE% del %EXE%

g++ -c array_functions.cpp -o array_functions.o

g++ -c input_output.cpp -o input_output.o

g++ -c main.cpp -o main.o

g++ main.o input_output.o array_functions.o -o %EXE%

%EXE%
