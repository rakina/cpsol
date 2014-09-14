import sys
import re
import urllib
url = "http://www.pythonchallenge.com/pc/def/linkedlist.php?nothing=%s"
template = "and the next nothing is (\d+)"
kya = "25357"

while True:
	html = urllib.urlopen(url%kya).read()
	kya = re.search(template,html).group(1)
	print kya