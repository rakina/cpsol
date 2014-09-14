import sys
import re
from string import maketrans
f = open('input.in','r')
m = {}
for line in f:
	line.replace("\n", "")
	line.replace(" ", "")
	for i in range(3,len(line)-4):
		if line[i].islower() :
			yep = True
			for j in range(1,4):
				if line[i-j].islower() or line[i+j].islower():
					yep = False
					break
			if i > 3:
				yep &= line[i-4].islower()
			if i+4 < len(line):
				yep &= line[i+4].islower()
			if yep:
				print "%d %d" % (i,len(line))
				print line[i-3]+line[i-2]+line[i-1]+line[i]+line[i+1]+line[i+2]+line[i+3]
f.close()