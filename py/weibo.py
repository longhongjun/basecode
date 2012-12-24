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

uid = str(sys.argv[1])

#print dir(pycurl)
#url = "http://i.api.weibo.com/statuses/friends_timeline/ids.json?source=3818214747&uids=1235801883"
#info = curl_get_one(url)
#print info
#print sys.argv[1]
#sys.exit(0)

def curl_get_one(url):
    url+="&source=3818214747"
    #print url
    crl = pycurl.Curl()
    #crl.setopt(pycurl.VERBOSE,1)
    crl.setopt(pycurl.USERPWD, 'habaishi4@126.com:chunjiang')
    crl.fp = StringIO.StringIO()
    crl.setopt(pycurl.URL, url)
    crl.setopt(crl.WRITEFUNCTION, crl.fp.write)
    crl.perform()
    info = crl.fp.getvalue()
    info_json = json.loads(info)
    return info_json

def write_file(filename, weibo_list):
    f=open(filename, 'a+')
    lists=weibo_list.encode("utf8")
    f.writelines(lists)
    f.close()
today_time=date.today()

#sys.exit(0)

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


'''
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
