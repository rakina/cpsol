import sys
from string import maketrans
f = open('input.in','r')
m = {}
for line in f:
	for char in line:
		if char.isalpha():
			print char
f.close()