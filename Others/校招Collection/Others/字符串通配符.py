# https://www.nowcoder.com/practice/43072d50a6eb44d2a6c816a283b02036

import re
try:
	while 1:
		pattern, s = raw_input(), raw_input()
		pattern = pattern.replace('.', '\\.').replace('?', '.').replace('*', '[0-9A-z]*')
		a = re.findall(pattern, s)
		print str(bool(len(a) == 1 and a[0] == s)).lower()
except:
	pass