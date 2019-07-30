# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/1f2700e2b1904254b55765479e9b8766

class Subset:
    # Return a 2D array as [[],[],[]].
    def getSubsets(self, A, n):
        # write code here
        from itertools import combinations
        Res = []

        for i in range(n + 1):
            generator = combinations(A, i)

            try:
                while 1:
                    result = list(next(generator))
                    result.sort(reverse=True)
                    Res.append(result)
            except:
                pass

        del Res[0]
        Res.sort(reverse=True)
        return Res
