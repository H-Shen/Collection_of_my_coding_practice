using ll = long long;

class Solution {
public:
    // 错排公式
    // D_1 = 0
    // D_n = n*D_(n-1)+(-1)^n
    ll D(ll n) {
        constexpr ll MOD = 1e9+7;
        if (n == 1) {
            return 0;
        }
        ll ans = 0;
        for (ll i = 2; i <= n; ++i) {
            if (i & 1) {
                ans = (ans*i-1) % MOD;
            } else {
                ans = (ans*i+1) % MOD;
            }
        }
        return ans;
    }
    int findDerangement(int n) {
        return (int)D(n);
    }
};