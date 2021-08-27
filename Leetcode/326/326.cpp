class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 3486784401LL % (long long)n == 0;   // 3486784401=3^20
    }
};