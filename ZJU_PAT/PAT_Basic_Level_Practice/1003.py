import re
 
for i in xrange(input()):
     
    s = raw_input().strip()
 
    if set(s) == {'P', 'A', 'T'}:
        a = re.findall(r'^A*PA{1,}TA*$', s)
        if len(a) == 1 and a[0] == s:
            if s.index('P') * (s.index('T') - (s.index('P') + 2) + 1) == len(s[s.index('T') + 1:]):
                print 'YES'
                continue
    print 'NO'