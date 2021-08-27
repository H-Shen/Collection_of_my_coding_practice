using ll = long long;
constexpr ll MOD = 1e9+7;

class Solution {
public:
    int numSub(string s) {
        int n = (int)s.size();
        ll counter = 0;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ++counter;
            } else {
                if (counter > 0) {
                    ans = (ans + counter*(counter+1)/2) % MOD;
                    counter = 0;
                }
            }
        }
        if (counter > 0) {
            ans = (ans + counter*(counter+1)/2) % MOD;
        }
        return (int)(ans % MOD);
    }
};