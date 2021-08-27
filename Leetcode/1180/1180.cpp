class Solution {
public:
    int countLetters(string S) {
        vector<pair<char,int>> v;
        int n = (int)S.size();
        char ch = 0;
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ++counter;
                ch = S[i];
                continue;
            }
            if (S[i] == ch) {
                ++counter;
            } else {
                v.emplace_back(ch, counter);
                ch = S[i];
                counter = 1;
            }
        }
        if (ch != 0) {
            v.emplace_back(ch, counter);
        }
        int result = 0;
        for (const auto &[i, j] : v) {
            result += ((1+j)*j) >> 1;
        }
        return result;
    }
};