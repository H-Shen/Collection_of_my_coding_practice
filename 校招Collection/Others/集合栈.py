# -*- coding:utf-8 -*-
# https://www.nowcoder.com/practice/69f0ffed01c741c5ae5594a23f7cd739

class SetOfStacks:
    def setOfStacks(self, ope, size):
        stack = list()
        for i in ope:
            if i[0] == 1:
                stack.append(i[1])
            elif i[0] == 2:
                _ = stack.pop()
        L = len(stack)
        return filter(lambda x: x != [], [stack[j * size:(j + 1) * size] for j in xrange(L)])