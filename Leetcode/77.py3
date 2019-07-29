class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        from itertools import combinations
        a = [i for i in range(1, n + 1)]
        L = list(combinations(a, k))
        for i in range(len(L)):
            L[i] = list(L[i])
        return L
