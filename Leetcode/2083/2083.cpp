using ll = long long;
constexpr int MAXN = 26;

class Solution {
public:
    long long numberOfSubstrings(string s) {
        ll stats[MAXN]{};
        for (auto& ch : s) {
            ++stats[ch - 'a'];
        }
        ll counter = (ll)s.size();
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i] > 1) {
                counter += (stats[i]*(stats[i]-1))>>1;
            }
        }
        return counter;
    }
};