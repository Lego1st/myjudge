@echo off
echo Make your I/O list easy and fast
echo All folders in testdata :
dir /b /ad testdata
set /p task=Please enter your task: 
dir /b /o /s /aa testdata\%task% > source\list.txt
cd source
sort.exe
del list.txt
pause