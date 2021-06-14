class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        b = int(''.join(list(map(str, b))))
        return pow(a, b, 1337)