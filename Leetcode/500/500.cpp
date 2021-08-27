class Solution {
public:
    vector<string> findWords(vector<string> &words) {

        auto sameRowCheck = [](string s, unordered_map<char, int> A) {
            bool res = true;
            int len = static_cast<int>(s.size());
            if (len == 0) {
                return false;
            }

            for (int i = 0; i < len; ++i) {
                s[i] = static_cast<char>(tolower(s[i]));
            }

            int currentVal = A[s[0]];
            for (int i = 1; i < len; ++i) {
                if (currentVal != A[s[i]]) {
                    res = false;
                    break;
                }
            }
            return res;
        };

        string a("qwertyuiop");
        string b("asdfghjkl");
        string c("zxcvbnm");
        unordered_map<char, int> A;
        for (const auto &i : a) A[i] = 1;
        for (const auto &i : b) A[i] = 2;
        for (const auto &i : c) A[i] = 3;

        vector<string> res;
        for (const auto &i : words) {
            if (sameRowCheck(i, A)) {
                res.push_back(i);
            }
        }
        return res;
    }
};