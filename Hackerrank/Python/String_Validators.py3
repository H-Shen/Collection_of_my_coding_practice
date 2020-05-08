a = input()
import re
if re.search('[a-zA-Z0-9]', a):
    print('True')
else:
    print('False')

if re.search('[a-zA-Z]', a):
    print('True')
else:
    print('False')

if re.search('\d+',a):
    print('True')
else:
    print('False')

if re.search('[a-z]', a):
    print('True')
else:
    print('False')

if re.search('[A-Z]', a):
    print('True')
else:
    print('False')
