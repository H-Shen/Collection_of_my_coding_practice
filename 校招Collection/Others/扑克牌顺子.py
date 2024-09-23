# https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4

class Solution:
    def IsContinuous(self, L):
        L = list(filter(lambda x: x != 0, L))
        if L != [] and max(L) - min(L) <= 4 and len(L) == len(set(L)):
            return True
        return False