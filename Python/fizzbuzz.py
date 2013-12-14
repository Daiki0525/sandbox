#coding:utf-8

i = 1 

while True:
    if i > 100:
     break
    if i % 15 == 0:
        print ('fizzbuzz')
    elif i % 3 == 0:
        print ('fizz')
    elif i % 5 == 0:
        print ('buzz')
    else:
        print "%d" % i
    i += 1
