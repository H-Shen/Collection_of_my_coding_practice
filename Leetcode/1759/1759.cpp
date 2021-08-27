using ll = long long;

class Solution {
public:
    int countHomogenous(string s) {
        int n = (int)s.size();
        vector<pair<char,ll> > vec;
        char ch = 0;
        ll counter = 0;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                ++counter;
                ch = s[i];
                continue;
            }
            if (ch == s[i]) {
                ++counter;
            } else {
                vec.emplace_back(ch, counter);
                ch = s[i];
                counter = 1;
            }
        }
        if (ch != 0) {
            vec.emplace_back(ch, counter);
        }
        
        constexpr ll MOD = 1e9+7;
        ll ans = 0;
        for (const auto &[k, v] : vec) {
            ans = (ans + ((1+v)*v>>1)) % MOD;
        }
        ans %= MOD;
        return (int)ans;
    }
};