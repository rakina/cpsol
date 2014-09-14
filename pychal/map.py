import sys
from string import maketrans
f = open('input.in','r')
a = "abcdefghijklmnopqrstuvwxyz"
b = "cdefghijklmnopqrstuvwxyzab"
c = maketrans(a,b)
for line in f:
	words = line.split();
	for word in words:
		print word.translate(c),
print "map".translate(c)
f.close()