

import pycurl
import StringIO
 
url = "http://i.api.weibo.com/statuses/friends_timeline/ids.json?source=3818214747&uids=1235801883"
url = "http://www.google.com/"
crl = pycurl.Curl()
crl.setopt(pycurl.VERBOSE,1)
crl.setopt(pycurl.FOLLOWLOCATION, 1)
crl.setopt(pycurl.MAXREDIRS, 5)
##crl.setopt(pycurl.USERNAME, 'longhongjun@gmail.com')
crl.fp = StringIO.StringIO()
crl.setopt(pycurl.URL, url)
crl.setopt(crl.WRITEFUNCTION, crl.fp.write)
crl.perform()
print crl.fp.getvalue()

'''
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




