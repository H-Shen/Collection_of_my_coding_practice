# https://www.nowcoder.com/practice/ca7b8af83e2f4ec1af2f23d6733223b5

import re

s = raw_input()
f1 = re.findall(r'[^A-Z]', s)
f2 = re.findall(r'([A-Z])\1', s)
f3 = re.findall(r'([A-Z])+([A-Z])+\1+\2', s)

print 'Dislikes' if (f1 or f2 or f3) else 'Likes'