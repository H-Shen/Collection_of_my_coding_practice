class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> A;
        int len = static_cast<int>(s.size());
        int i;
        for (i = 0; i < len; ++i) {
            ++A[s[i]];
        }
        for (i = 0; i < len; ++i) {
            if (A[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};