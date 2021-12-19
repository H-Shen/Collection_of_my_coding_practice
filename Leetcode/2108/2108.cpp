class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto &s : words) {
            int length = (int)s.size();
            bool haveAns = true;
            for (int i = 0, j = length-1; i <= j; ++i, --j) {
                if (s[i] != s[j]) {
                    haveAns = false;
                    break;
                }
            }
            if (haveAns) {
                return s;
            }
        }
        return string();
    }
};