# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c

class Solution:
    def match(self, s, pattern):
        import re
        k = re.findall(pattern, s)
        return True if s in re.findall(pattern, s) else False