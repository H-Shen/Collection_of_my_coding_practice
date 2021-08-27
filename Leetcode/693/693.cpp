class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool res = true;
        bitset<64> a(n);
        string s = a.to_string();
        string s_new;
        if (n != 0) {
            bool tailZero = true;
            for (const auto &i : s) {
                if (tailZero && i != '0') {
                    tailZero = false;
                    s_new += i;
                } else if (!tailZero) {
                    s_new += i;
                }
            }
        }
        for (size_t i = 0; i < s_new.size() - 1; ++i) {
            if (s_new[i] == s_new[i + 1]) {
                res = false;
                break;
            }
        }
        return res;
    }
};