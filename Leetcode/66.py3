class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        num = str(int(''.join(map(lambda x : str(x), digits))) + 1)
        return [int(i) for i in num]
