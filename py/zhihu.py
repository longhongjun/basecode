#!/usr/bin/python
#coding=utf-8

import pycurl
import StringIO
import json
import sys
import datetime
from datetime import date
import os
import time
import re

import HTMLParser  
import urllib  
import sys

import sys
import urllib
import HTMLParser

from sgmllib import SGMLParser
class GetIdList(SGMLParser):
    def reset(self):
        self.IDlist = []
        self.flag = False
        self.getdata = False
        self.verbatim = 0
        SGMLParser.reset(self)
        
    def start_div(self, attrs):
        #print attrs
        if(attrs and attrs[0] and [1] and attrs[0][1] == 'zm-editable-content'):
            self.getdata=True
        if(attrs and attrs[0] and [1] and attrs[0][1] == 'zm-editable-content clearfix'):
            self.getdata=True
    
    def end_div(self):#遇到</div>
        self.getdata=False

    def start_p(self, attrs):
        if self.flag == False:
            return
        self.getdata = True
        
    def end_p(self):#遇到</p>
        if self.getdata:
            self.getdata = False

    def handle_data(self, text):#处理文本
        if self.getdata:
            self.IDlist.append(text)
            
    def printID(self):
        for i in self.IDlist:
            print i

def some_url(url):
    content = urllib.urlopen(url).read()
    content = unicode(content, "utf-8")
    content_len = len(content)
    if(content_len > 10000):
        lister = GetIdList()
        lister.feed(content)
        #lister.printID()
        return lister.IDlist
    else:
        return ""
def write_file(filename, weibo_list):
    f=open(filename, 'a+')
    lists=weibo_list.encode("utf8")
    f.writelines(lists)
    f.close()
content=""
filename = "./zhihu.txt"
f=open(filename, 'r')
file_content = f.readlines()
f.close()
for line in file_content:
    content+=line
content = unicode(content, "utf-8")
content_len = len(content)
if(content_len > 10000):
    lister = GetIdList()
    lister.feed(content)
    lister.printID()
    print lister.IDlist
    for i in lister.IDlist:
        write_file('./zhihu2.txt', i+"\r\n")


'''   
user_url="http://hutu.me/"
filename = "./blog1.txt"
for i in range(1,1000):
    get_url=user_url+str(i)
    content = some_url(get_url)
    if(content):
        write_file(filename, get_url+'---\r\n')
        print get_url
        for i in content:
            #print i
            write_file(filename, i+'\r\n')


'''














    
