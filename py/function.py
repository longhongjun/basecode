#!/usr/bin/python
#coding=utf-8

import sys
import os
import os.path
import re
pathname = "/home/long/git/basecode"
filelist = []
function_list = []
print filelist
pattern = re.compile(r"(?<=function )(\w+)") 
filename = "/home/long/git/basecode/observer.php"
f = open(filename)
try:
    for line in f:
        if line:
            #print line
            m = pattern.search(line)
            if m:
                print m.group()
                function_list.append(m.group())
finally:
    f.close()
    
print function_list

try:
    for line in f:
        if line:
            #print line
            m = pattern.search(line)
            if m:
                print m.group()
                function_list.append(m.group())
finally:
    f.close()
    


    
         
'''
for root, dirs, files in os.walk(pathname):
    for filename in files:
        filelist.append(os.path.join(root, filename))
    regex=ur".php"
    fun_regex="function (\w+)"
    pattern = re.compile(r"function (\w+)") 
    for filename in filelist:
        if(re.search(regex, filename)):
            f = open(filename)
            try:
                for line in f:
                    print line
                    if line:
                        #print line
                        m = pattern.search(line)
                        if m:
                            print m()
            finally:
                f.close()
            
            
    
    
    #print os.path.join()

    
'''
