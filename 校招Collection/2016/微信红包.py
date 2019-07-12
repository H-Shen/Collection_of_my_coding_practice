# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54
class Gift:
    def getValue(self, gifts, n):
        # write code here
        a = set(gifts)
        if n % 2 == 0:
            half = n // 2
        else:
            half = n // 2 + 1
        for i in a:
            if gifts.count(i) > half:
                return i
        return 0