# -*- coding:utf-8 -*-

# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

# https://www.nowcoder.com/practice/e51af77572f74a5fa069b4d5a3a0953e

class Bipartition:
    def getBipartition(self, A, B):
        # write code here
        MidA = [sum([i.x for i in A]) / 4.0, sum([i.y for i in A]) / 4.0]
        MidB = [sum([i.x for i in B]) / 4.0, sum([i.y for i in B]) / 4.0]
        k = (MidB[1] - MidA[1]) / (MidB[0] - MidA[0])
        b = MidB[1] - k * MidB[0]
        return [k, b]