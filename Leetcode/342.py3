class Solution:
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if (num <= 0):
            return False
        from math import log
        return log(num, 4) % 1 == 0