#!/bin/sh

for /f "delims= tokens=1*" %%a in (./) do echo %%a

#set path=/home
#%path%
#for /R %i in (*) do echo %i
