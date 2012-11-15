#!/usr/bin/python
#coding=utf-8
'''抓取 http://coolshell.cn整站信息,并分析评论,并发邮件'''

import pycurl
import StringIO
 
url = "http://www.coolshell.cn"
crl = pycurl.Curl()
crl.setopt(pycurl.VERBOSE,1)
crl.setopt(pycurl.FOLLOWLOCATION, 1)
crl.setopt(pycurl.MAXREDIRS, 5)
crl.fp = StringIO.StringIO()
crl.setopt(pycurl.URL, url)
crl.setopt(crl.WRITEFUNCTION, crl.fp.write)
crl.perform()
print crl.fp.getvalue()

#获取到总页码

#每页获取数据,获取到每个博文的链接

#取博文,获取到title,link,content




'''

123

'''
