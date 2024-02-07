class Solution {
public:
    int distributeCandies(int n, int limit) {
        // (a,b,c)
        // a,b,c <= limit
        int cnt = 0;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (i+j+k == n && i <= limit && j <= limit && k <= limit) {
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};