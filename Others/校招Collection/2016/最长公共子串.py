# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/02e7cc263f8a49e8b1e1dc9c116f7602
class LongestSubstring:
    def findLongest(self, A, n, B, m):
        # write code here
        M=[[0 for i in xrange(m+1)] for j in xrange(n+1)]
        mmax=0
        p=0
        for i in xrange(n):
            for j in xrange(m):
                if A[i]==B[j]:
                    M[i+1][j+1]=M[i][j]+1
                    if M[i+1][j+1]>mmax:
                        mmax=M[i+1][j+1]
                        p=i+1
        return mmax