class Solution {
public:
    int countDistinct(string s) {
        using ll = long long;
        // Adjust p and m if any hash collision happens
        constexpr ll p = 233;
        constexpr ll m = 1e9 + 9;
        int n = (int)s.size();
        vector<ll> p_pow(n);
        p_pow[0] = 1;
        for (int i = 1; i < n; i++)
            p_pow[i] = (p_pow[i-1] % m * p % m) % m;

        vector<ll> h(n + 1, 0);
        for (int i = 0; i < n; i++)
            h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

        int cnt = 0;
        for (int l = 1; l <= n; l++) {
            set<ll> hs;
            for (int i = 0; i <= n - l; i++) {
                ll cur_h = (h[i + l] + m - h[i]) % m;
                cur_h = (cur_h * p_pow[n-i-1]) % m;
                hs.insert(cur_h);
            }
            cnt += (int)hs.size();
        }
        return cnt;
    }
};