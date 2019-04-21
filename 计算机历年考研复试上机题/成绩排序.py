#!/usr/bin/env python
# -*- coding: utf-8 -*-

try:
    while 1:
        n, a, table = [input(), input(), []]
        for i in xrange(n):
            item = raw_input().split()
            table.append((item[0],int(item[1]), i))
        if a == 1:
            result = sorted(table, key=lambda x:(x[1], x[2]))
        else:
            result = sorted(table, key=lambda x:(x[1], -x[2]),reverse=True)
        for m, k, n in result:
            print m, k
except:
    pass
