class Solution {
public:
    string f(const string &s) {
        int res = 0;
        for (const auto &ch : s) {
            res += ch - '0';
        }
        return to_string(res);
    }
    int getLucky(string s, int k) {
        string num;
        for (const auto &i : s) {
            num += to_string((int)(i-'a'+1));
        }
        for (int i = 0; i < k; ++i) {
            num = f(num);
        }
        return stoi(num);
    }
};