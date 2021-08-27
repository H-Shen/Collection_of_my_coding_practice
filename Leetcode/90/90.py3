class Solution:
    def subsetsWithDup(self, a):
        """
        :type a: List[int]
        :rtype: List[List[int]]
        """
        from itertools import combinations
        A = list()
        for i in range(0, len(a) + 1):
            A.extend(list(combinations(a, i)))
        A = list(set(A))
        for i in range(len(A)):
            A[i] = tuple(sorted(list(A[i])))
        A = list(set(A))
        for i in range(len(A)):
            A[i] = list(A[i])
        return A