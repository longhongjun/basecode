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
        if self.flag == True:
            self.verbatim +=1 #进入子层div了，层数加1
            return
        for k,v in attrs:#遍历div的所有属性以及其值
            if k == 'class' and v == 'entry-content':#确定进入了<div class='entry-content'>
                self.flag = True
                return

    def end_div(self):#遇到</div>
        if self.verbatim == 0:
            self.flag = False
        if self.flag == True:#退出子层div了，层数减1
            self.verbatim -=1

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

#http://blog.csdn.net/nwpulei/article/details/7272832
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
        


##import urllib2
##import datetime
##vrg = (datetime.date(2012,2,19) - datetime.date.today()).days
##strUrl = 'http://www.nod32id.org/nod32id/%d.html'%(200+vrg)
##req = urllib2.Request(strUrl)#通过网络获取网页
##response = urllib2.urlopen(req)
##the_page = response.read()

the_page ='''<html>
<head>
<title>test</title>
</head>
<body>
<h1>title</h1>
<div class='entry-content'>
<div class= 'ooxx'>我是来捣乱的</div>
<p>感兴趣内容1</p>
<p>感兴趣内容2</p>
……
<p>感兴趣内容n</p>
<div class= 'ooxx'>我是来捣乱的2<div class= 'ooxx'>我是来捣乱的3</div></div>
</div>
<div class='content'>
<p>内容1</p>
<p>内容2</p>
……
<p>内容n</p>
</div>
</body>
</html>
'''

'''

#定义HTML解析器  
class parseLinks(HTMLParser.HTMLParser):
    def handle_startendtag(self, tag, attrs):
        {}
        #print tag,attrs,123
    def handle_data(self, data):
        print data
class URLLister(SGMLParser):
    def reset(self):                              
        SGMLParser.reset(self)
        self.urls = []
    def start_a(self, attrs):                     
        href = [v for k, v in attrs if k=='href']  
        if href:
            self.urls.extend(href)
            
if __name__ == "__main__":  
    #创建HTML解析器的实例

    lParser = parseLinks()
    #打开HTML文件
    content = urllib.urlopen("http://hutu.me/97").read()
    content = unicode(content, "utf-8")
    lParser.feed(content)  
    lParser.close()

    content = urllib.urlopen("http://hutu.me/97").read()
    content = unicode(content, "utf-8")
    parser= urllister.URLLister()
    parser.feed(content)
    parser.close()
    for url in paeser.urls:
        print url

sys.exit(0)

#uid = str(sys.argv[1])

#print dir(pycurl)
#url = "http://i.api.weibo.com/statuses/friends_timeline/ids.json?source=3818214747&uids=1235801883"
#info = curl_get_one(url)
#print info
#print sys.argv[1]


def curl_get_one(url):
    #url+="&source=3818214747"
    #print url
    crl = pycurl.Curl()
    #crl.setopt(pycurl.VERBOSE,1)
    #crl.setopt(pycurl.USERPWD, 'habaishi4@126.com:chunjiang')
    crl.fp = StringIO.StringIO()
    crl.setopt(pycurl.URL, url)
    crl.setopt(crl.WRITEFUNCTION, crl.fp.write)
    crl.perform()
    info = crl.fp.getvalue()
    #info_json = json.loads(info)
    return info

def write_file(filename, weibo_list):
    f=open(filename, 'a+')
    lists=weibo_list.encode("utf8")
    f.writelines(lists)
    f.close()
today_time=date.today()

def get_title_content(content):
    p=re.compile('div')
    #m=re.findall("\<p\>(.*)\<\/p\>", content)

   # m=re.match('(?<=<p>)123(?=</p>)', "<p>123</p><p>222</p>")
    #print m
    #print m.groups()
    m = re.search('(?<=abc)def', 'abcdef')
    print m.groups(0)
    m = re.search('(?<=-)\w+', 'spam-egg')
    print m.groups(0)
    
#sys.exit(0)
print 123

user_url="http://hutu.me/"
for i in range(97,99):
    get_url=user_url+str(i)
    #content = curl_get_one(get_url)
    
    content=13
    title_content=get_title_content(content)
    #print title_content


user_timeline = "http://i2.api.weibo.com/2/statuses/user_timeline.json?feature=1"
user_timeline+="&uid="+uid
#print user_timeline
info = curl_get_one(user_timeline)

total_number = info['total_number']
total_page = total_number/200 + 4

print total_page
file_name = "./" + str(uid)+"-"+str(today_time)+".txt"
if(os.path.isfile(file_name)):
    os.remove(file_name)

for i in range(1,total_page):
    page_url=user_timeline+"&page="+str(i)+"&count=200"
    info=curl_get_one(page_url)
    statuses=info['statuses']
    list=""
    #print statuses
    for status in statuses:
        text=unicode(status['text'])
        created_at = status['created_at']
        list+=text+created_at+"\r\n\r\n"
        created_at=status['created_at']
       # print time.mktime(created_at)
       # sys.exit(0)
    #print list
    write_file(file_name, list)
    #sys.exit(0)



url = "http://i.api.weibo.com/statuses/friends_timeline/ids.json?uids=1235801883&feature=1"
info  = curl_get_one(url)
print info["total_number"]


import sys
def readfile(filename):
    f=file(filename)
    while True:
        line = f.readline()
        if len(line) == 0:
            break;
        print line,
    f.close()

if len(sys.argv) < 2:
    print "no action specified"
    sys.exit()

if sys.argv[1].startswith('--'):
    option = sys.argv[1][2:]
    if (option == 'version'):
        print 'version 12'
    elif option == 'help':
        print 'help'
    else:
        print "unknow option"

    sys.exit()
else:
    for filename in sys.argv[1:]:
        readfile(filename)

import cPickle as p
list = ['1','2','3']
f = file("123a", "w")
p.dump(list, f)
f.close()
f=file("123a")
shortlist = p.load(f)
print shortlist
print dir(p)


f= file("123a", "w")
f.write("123 123123")
f.close()




f = file("123a")
while True:
    line = f.readline()
    if len(line) == 0:
        break
    print line

f.close()
'''
