class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1) return 0;
        else if (n & 1) return n;
        return n >> 1;
    }
};