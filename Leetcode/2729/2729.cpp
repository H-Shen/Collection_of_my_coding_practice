constexpr int N = 10;
int freq[N];

class Solution {
public:
    bool isFascinating(int n) {
        memset(freq, 0, sizeof freq);
        string a = to_string(n);
        a += to_string(2*n);
        a += to_string(3*n);
        for (const auto &i : a) ++freq[i-'0'];
        if (freq[0] > 0) return false;
        for (int i = 1; i <= 9; ++i) {
            if (freq[i] != 1) return false;
        }
        return true;
    }
};