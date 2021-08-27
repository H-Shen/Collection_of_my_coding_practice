class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        constexpr int MAXN = 10005;
        int freq[MAXN]{};
        for (const auto &i : deck) ++freq[i];
        bool first = true;
        int Gcd = 1;
        for (int i = 0; i < MAXN; ++i) {
            if (freq[i] > 0) {
                if (first) {
                    first = false;
                    Gcd = freq[i];
                } else {
                    Gcd = gcd(freq[i], Gcd);
                    if (Gcd < 2) return false;
                }
            }
        }
        return Gcd >= 2;
    }
};