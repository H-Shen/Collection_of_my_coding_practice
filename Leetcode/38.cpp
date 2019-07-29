class Solution {
public:
    string countAndSay(int n) {

        auto handle = [](const string &s) {
            string res;
            string tmp;
            char lastChar = '\0';
            for (const auto &ch : s) {
                if (lastChar == '\0') {
                    lastChar = ch;
                    tmp += lastChar;
                } else if (ch == lastChar) {
                    tmp += lastChar;
                } else {
                    res += to_string(tmp.size()) + tmp.front();
                    lastChar = ch;
                    tmp = lastChar;
                }
            }
            if (!tmp.empty()) {
                res = res + to_string(tmp.size()) + tmp.front();
            }

            return res;
        };

        string res = "1";
        for (int i = 2; i <= n; ++i) {
            res = handle(res);
        }
        return res;
    }
};