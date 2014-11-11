#coding:utf-8

i = 1 

while True:
    str = ''
    if i > 100:
     break
    if i % 3 == 0:
        str = 'fizz'
    if i % 5 == 0:
        str = str + 'buzz'
    if str == '':
        str = "%d" % i
    print str
    i += 1
