using ll = long long;

constexpr int MAXN = 1005;
constexpr ll MOD = 1e9+9;
constexpr ll Pow = 31;

ll p_pow[MAXN];
ll p_pow_inv[MAXN];
ll hash1[MAXN];
ll hash2[MAXN];

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

class Solution {
public:
    ll hashSubstr1(int l, int r) {
        if (l == 0) {
            return hash1[r] % MOD;
        }
        // ((hash1[r] - hash1[l-1]) / p_pow[l]) % MOD = ((hash1[r] - hash1[l-1]) * p_pow[l]^(MOD-2)%MOD) % MOD
        // You need the modular multiplicative inverse of p_pow[l] here!
        return multmod(hash1[r] - hash1[l-1] + MOD, p_pow_inv[l], MOD);
    }
    ll hashSubstr2(int l, int r) {
        if (l == 0) {
            return hash2[r] % MOD;
        }
        return multmod(hash2[r] - hash2[l-1] + MOD, p_pow_inv[l], MOD);
    }
    bool checkOneByOne(vector<int>& nums1, vector<int>& nums2, int l1, int r1, int l2, int r2) {
        if (r1 - l1 != r2 - l2) return false;
        for (int i = l1, j = l2; i <= r1; ++i, ++j) {
            if (nums1[i] != nums2[j]) return false;
        }
        return true;
    }
    bool check(vector<int>& nums1, vector<int>& nums2, int n, int m, int length) {
        unordered_map<ll,vector<pair<int,int>>> unmap1, unmap2;
        for (int l = 0, r = length-1; r < n; ++l, ++r) {
            unmap1[hashSubstr1(l,r)].emplace_back(l,r);
        }
        for (int l = 0, r = length-1; r < m; ++l, ++r) {
            unmap2[hashSubstr2(l,r)].emplace_back(l,r);
        }
        int l1,r1,l2,r2;
        for (auto&[k,v] : unmap1) {
            if (unmap2.find(k) != unmap2.end()) {
                for (auto&i : v) {
                    l1 = i.first;
                    r1 = i.second;
                    for (auto&j : unmap2[k]) {
                        l2 = j.first;
                        r2 = j.second;
                        if (checkOneByOne(nums1,nums2,l1,r1,l2,r2)) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    // 二分答案的长度 并用rolling hash检查
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(p_pow, 0, sizeof p_pow);
        p_pow[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            p_pow[i] = (p_pow[i-1] * Pow) % MOD;
        }
        for (int i = 0; i < MAXN; ++i) {
            p_pow_inv[i] = powmod(p_pow[i], MOD-2, MOD);
        }
        memset(hash1, 0, sizeof hash1);
        ll hashVal = 0;
        int n = (int)nums1.size();
        for (int i = 0; i < n; ++i) {
            hashVal = (hashVal + (nums1[i] + 1) * p_pow[i]) % MOD;
            hash1[i] = hashVal;
        }
        memset(hash2, 0, sizeof hash2);
        int m = (int)nums2.size();
        hashVal = 0;
        for (int i = 0; i < m; ++i) {
            hashVal = (hashVal + (nums2[i] + 1) * p_pow[i]) % MOD;
            hash2[i] = hashVal;
        }
        int l = 1;
        int r = min(n,m);
        int mid;
        int ans = 0;
        while (l <= r) {
            mid = l + ((r-l) >> 1);
            if (check(nums1, nums2, n, m, mid)) {
                ans = max(mid, ans);
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return ans;
    }
};