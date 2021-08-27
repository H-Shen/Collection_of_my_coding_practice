class Solution {
public:
    int balancedStringSplit(string s) {
        int l = 0;
        int r = 0;
        int counter = 0;
        int n = (int)s.size();
        // greedy
        for (const char &ch : s) {
            if (l == 0 && r == 0) {
                if (ch == 'L') ++l;
                else ++r;
                continue;
            }
            if (ch == 'L') {
                ++l;
            } else {
                ++r;
            }
            if (l == r) {
                ++counter;
                l = 0;
                r = 0;
            }
        }
        return counter;
    }
};