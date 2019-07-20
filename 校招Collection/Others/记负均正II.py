# https://www.nowcoder.com/practice/64f6f222499c4c94b338e588592b6a62

from __future__ import division

try:
    while 1:
        negative = 0
        positive = 0
        positiveCount = 0
        L = map(int, raw_input().split())
        for s in L:
            if s < 0:
                negative += 1
            else:
            	positive += s
            	positiveCount += 1
        if positiveCount == 0 or positive == 0:
            avg = 0.0
       	else:
            avg = positive / positiveCount
            avg = '%.1f' % avg
        print negative
        print avg
except:
	pass