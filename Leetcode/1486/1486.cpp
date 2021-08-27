class Solution {
public:
    int xorOperation(int n, int start) {
        int curr = start;
        for (int i = 1; i < n; ++i) {
            curr ^= (start + (i << 1));
        }
        return curr;
    }
};