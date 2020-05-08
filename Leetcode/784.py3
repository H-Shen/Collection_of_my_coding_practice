class Solution:
    def letterCasePermutation(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        from itertools import product
        a = [0, 1]
        pos = list()

        for i in range(len(S)):
            if S[i].isalpha():
                pos.append(i)

        res = list()
        c = product(a, repeat=len(pos))
        for comb in c:
            tmpStr = [i for i in range(len(S))]
            cnt = 0
            for i in range(len(S)):
                if S[i].isdigit():
                    tmpStr[i] = S[i]
                elif comb[cnt] == 0:
                    tmpStr[i] = S[i].upper()
                    cnt += 1
                else:
                    tmpStr[i] = S[i].lower()
                    cnt += 1
            res.append(''.join(tmpStr))
        return res