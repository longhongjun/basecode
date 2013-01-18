#!/usr/bin/python
#coding=utf-8
#根据 陈鑫《基于行块分布函数的通用网页正文抽取算法》
#Usage: ./getcontent.py filename.html
import re
import sys
 def PreProcess():
     global g_HTML
     _doctype = re.compile(r'<!DOCTYPE.*?>', re.I|re.S)
     _comment = re.compile(r'<!--.*?-->', re.S)
     _javascript = re.compile(r'<script.*?>.*?<\/script>', re.I|re.S)
     _css = re.compile(r'<style.*?>.*?<\/style>', re.I|re.S)
     _other_tag = re.compile(r'<.*?>', re.S)
     _special_char = re.compile(r'&.{1,5};|&#.{1,5};')
     g_HTML = _doctype.sub('', g_HTML)
     g_HTML = _comment.sub('', g_HTML)
     g_HTML = _javascript.sub('', g_HTML)
     g_HTML = _css.sub('', g_HTML)
     g_HTML = _other_tag.sub('', g_HTML)
     g_HTML = _special_char.sub('', g_HTML)
 def GetContent(threshold):
     global g_HTMLBlock
     nMaxSize = len(g_HTMLBlock)
     nBegin = 0
     nEnd = 0
     for i in range(0, nMaxSize):
         if g_HTMLBlock[i]>threshold and i+3<nMaxSize and g_HTMLBlock[i+1]>0 and g_HTMLBlock[i+2]>0 and g_HTMLBlock[i+3]>0:
             nBegin = i
             break
     else:
         return None
     for i in range(nBegin+1, nMaxSize):
         if g_HTMLBlock[i]==0 and i+1<nMaxSize and g_HTMLBlock[i+1]==0:
             nEnd = i
             break
     else:
         return None
     return '\n'.join(g_HTMLLine[nBegin:nEnd+1])
 if __name__ == '__main__' and len(sys.argv) > 1:
     f = file(sys.argv[1], 'r')
     global g_HTML
     global g_HTMLLine
     global g_HTMLBlock
     g_HTML = f.read()
     PreProcess()
     g_HTMLLine = [i.strip() for i in g_HTML.splitlines()]    #先分割成行list，再过滤掉每行前后的空字符
     HTMLLength = [len(i) for i in g_HTMLLine]    #计算每行的长度
     g_HTMLBlock = [HTMLLength[i] + HTMLLength[i+1] + HTMLLength[i+2] for i in range(0, len(g_HTMLLine)-3)]    #计算每块的长度
     print GetContent(200)