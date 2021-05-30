class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = (int)s.size();
        int counter = 0;
        string str;
        for (int i = 0; i < n - 2; ++i) {
            str.clear();
            str.push_back(s[i]);
            str.push_back(s[i+1]);
            str.push_back(s[i+2]);
            if (str[0] != str[1] && str[1] != str[2] && str[2] != str[0]) {
                ++counter;
            }
        }
        return counter;
    }
};