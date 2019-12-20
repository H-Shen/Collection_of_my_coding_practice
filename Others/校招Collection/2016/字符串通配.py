# -*- coding:utf-8 -*-

# https://www.nowcoder.com/practice/28acd1134e344040ad105b3786a79e7a
class WildMatch:
    def chkWildMatch(self, A, lena, B, lenb):
        # write code here
        import re
        Pattern = B.replace('*','+')
        try:
        	return re.findall(Pattern, A)[0] == A
        except:
            return False