using ll = long long;
constexpr ll MOD = 1e9+7;
constexpr ll MAXN = 1e9+5;

vector<ll> powerOfTwo;

class Solution {
public:
    inline
    ll powmod(ll a, ll b, ll m) const {
        ll ans = 1LL;
        a = (a % m + m) % m;
        for (; b; b >>= 1) {
            if (b & 1) ans = (a * ans) % m;
            a = (a * a) % m;
        }
        return ans;
    }
    inline
    ll rangeMulti(vector<ll>& pre, int l, int r) const {
        if (l == 0) {
            return pre[r] % MOD;
        }
        return (pre[r] % MOD) * (powmod(pre[l-1], MOD-2, MOD)) % MOD;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        if (powerOfTwo.empty()) {
            powerOfTwo.emplace_back(1LL);
            while (powerOfTwo.back() < MAXN) {
                powerOfTwo.emplace_back(powerOfTwo.back()*2LL);
            }
        }
        ll nCopy(n);
        vector<ll> vec;
        while (nCopy > 0) {
            auto iter = lower_bound(powerOfTwo.begin(), powerOfTwo.end(), nCopy);
            if (iter == powerOfTwo.end() || (*iter) > nCopy) {
                --iter;
            }
            vec.emplace_back(*iter);
            nCopy -= vec.back();
        }
        sort(vec.begin(),vec.end());
        vector<ll> pre(vec.size());
        pre[0] = vec[0];
        for (size_t i = 1; i != pre.size(); ++i) {
            pre[i] = pre[i-1] * vec[i] % MOD;
        }
        vector<int> ans;
        for (const auto&i : queries) {
            ans.emplace_back((int)(rangeMulti(pre, i[0], i[1])));
        }
        return ans;
    }
};