# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b

class Solution:
    def FindNumbersWithSum(self, array, tsum):
        if array == []:
            return []
        result = []
        head, tail = 0, -1
        while array[head] < array[tail]:
            if array[head] + array[tail] < tsum:
                head += 1
            elif array[head] + array[tail] > tsum:
                tail -= 1
            else:
                result.append((array[head], array[tail], array[head] * array[tail]))
                head += 1
        if result == []:
            return []
        res = min(result, key=lambda x: x[2])
        return [res[0], res[1]]
