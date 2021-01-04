class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        using ll = long long;
        constexpr ll MOD = 1e9 + 7;
        unordered_map<ll, ll> unmap;
        for (const auto &i : deliciousness) {
            ++unmap[i];
        }
        constexpr ll MAXN = 20 + 1;
        vector<pair<ll, ll> > result;
        for (ll i = MAXN; i >= 0; --i) {
            ll powerOfTwo = pow(2, i);
            ll diff;
            for (const auto &[k, v] : unmap) {
                diff = powerOfTwo - k;
                if (unmap.find(diff) != unmap.end()) {
                    if (k > diff) {
                        result.push_back({diff, k});
                    } else {
                        result.push_back({k, diff});
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        ll ways = 0;
        ll temp, halfTemp;
        for (const auto &[a, b] : result) {
            if (a == b) {
                temp = unmap[a];
                if (temp % 2 == 0) {
                    halfTemp = temp / 2;
                    ways += (halfTemp % MOD) * ((temp - 1) % MOD) % MOD;
                } else {
                    halfTemp = (temp - 1) / 2;
                    ways += (halfTemp % MOD) * (temp % MOD) % MOD;
                }
            } else {
                ways += (unmap[a] % MOD) * (unmap[b] % MOD) % MOD;
            }
        }
        return (int)(ways % MOD); 
    }
};