class Solution {
public:
    bool makePalindrome(string s) {
        int counter = 0;
        for (int i = 0, j = (int)s.size()-1; i <= j; ++i, --j) {
            if (s[i] != s[j]) {
                ++counter;
            }
        }
        return counter <= 2;
    }
};