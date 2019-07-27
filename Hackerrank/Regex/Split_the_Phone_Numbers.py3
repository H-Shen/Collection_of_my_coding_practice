import re

for i in range(int(input())):
    s = input()
    k = re.search(r'^\d{1,3}(-| )\d{1,3}(-| )\d{4,10}$', s)
    print('CountryCode={a},LocalAreaCode={b},Number={c}'.format(a=s[:k.span(1)[0]],b=s[k.span(1)[0]+1:k.span(2)[0]],c=s[k.span(2)[1]:]))
