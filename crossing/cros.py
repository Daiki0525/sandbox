#!/usr/bin/python
# coding: UTF-8

f = open('crossing.txt')
#f = open('sample.txt')
lines = f.readlines() # 1行毎にファイル終端まで全て読む(改行文字も含まれる)
f.close()
 
# str => int
nums = map(int,lines)

ix = 1
iy = 1
count = 0

print "stand by ok!!"

# Main
for num in nums:
    if (ix % 1000 == 0):
        print ix
    for iy in range(0,ix - 1):
        if num < nums[iy]:
            count += 1
    ix += 1
# print crossing point 
print "count = ",count
