class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = (int)s.size();
        int moves = 0;
        for (int i = 0, j = n-1; i < j; ++i) {
            for (int k = j; k >= i; --k) {
                if (i == k) {
                    moves += ((n >> 1) - i);
                }
                else if (s[i] == s[k]) {
                    for (int p = k; p < j; ++p) {
                        swap(s[p], s[p+1]);
                        ++moves;
                    }
                    --j;
                    break;
                }
            }
        }
        return moves;
    }
};