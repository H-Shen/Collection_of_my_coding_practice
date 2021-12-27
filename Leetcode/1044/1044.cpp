// 双重滚动哈希防止冲突 模除费马小定理+预处理

using ll = long long;

constexpr int MAXN = 3*1e4+5;
constexpr ll P1 = 31;
constexpr ll P2 = 233;
constexpr ll MOD1 = 1e9 + 7;
constexpr ll MOD2 = 1e9 + 9;

ll p_pow1[MAXN];
ll p_pow2[MAXN];
ll p_pow1_inv[MAXN];
ll p_pow2_inv[MAXN];
ll h1[MAXN];
ll h2[MAXN];

ll multmod(ll a, ll b, ll m) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return ((a * b - (ll) ((long double) a / m * b) * m) % m + m) % m;
}

ll powmod(ll a, ll b, ll m) {
    if (m == 1) return 0;
    ll r;
    for (r = 1, a %= m; b; a = multmod(a, a, m), b >>= 1)
        if (b % 2) r = multmod(r, a, m);
    return r;
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

class Solution {
public:
    int start, end;
    int n;
    pair<ll,ll> hashSubstr(int l, int r) {
        if (l == 0) {
            return {h1[r], h2[r]};
        }
        return {(h1[r] - h1[l-1] + MOD1) * p_pow1_inv[l] % MOD1, 
                (h2[r] - h2[l-1] + MOD2) * p_pow2_inv[l] % MOD2};
    }
    bool check(string&s, int length) {
        unordered_set<pair<ll,ll>, custom_hash> unmap;
        for (int i = 0, j = length-1; j < n; ++i, ++j) {
            pair<ll,ll> temp = hashSubstr(i,j);
            if (unmap.find(temp) != unmap.end()) {
                start = i;
                end = j;
                return true;
            }
            else {
                unmap.insert(temp);
            }
        }
        return false;
    }
    string longestDupSubstring(string s) {
        // prep rolling hash
        memset(p_pow1, 0, sizeof p_pow1);
        memset(p_pow2, 0, sizeof p_pow2);
        memset(h1, 0, sizeof h1);
        memset(h2, 0, sizeof h2);
        p_pow1[0] = 1;
        p_pow2[0] = 1;
        n = (int)s.size();
        for (int i = 1; i < n; ++i) {
            p_pow1[i] = (p_pow1[i - 1] * P1) % MOD1;
            p_pow2[i] = (p_pow2[i - 1] * P2) % MOD2;
        }
        for (int i = 0; i < n; ++i) {
            p_pow1_inv[i] = powmod(p_pow1[i], MOD1 - 2, MOD1);
            p_pow2_inv[i] = powmod(p_pow2[i], MOD2 - 2, MOD2);
        }
        ll hVal1 = 0;
        ll hVal2 = 0;
        for (int i = 0; i < n; ++i) {
            hVal1 = (hVal1 + (s[i] - 'a' + 1) * p_pow1[i]) % MOD1;
            h1[i] = hVal1;
            hVal2 = (hVal2 + (s[i] - 'a' + 1) * p_pow2[i]) % MOD2;
            h2[i] = hVal2;
        }
        start = -1;
        end = -1;
        int l = 1;
        int r = n;
        int mid;
        while (l <= r) {
            mid = l + ((r-l) >> 1);
            if (check(s, mid)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        string ans;
        if (start != -1) {
            for (; start <= end; ++start) {
                ans.push_back(s[start]);
            }
        }
        return ans;
    }
};