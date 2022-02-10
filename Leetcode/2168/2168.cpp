using ll = long long;
constexpr int MAXN = 1003;
constexpr int N = 10;
int pre[MAXN][N];

// Rolling hash
namespace RH {
    constexpr ll MOD = 1e9+7;
    constexpr ll P = 31;
    unordered_set<ll> vis;
    vector<ll> Pow;
    vector<ll> Pow_inv;
    vector<ll> H;
    int n;
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
    void pre(const string& s) {
        n = (int)s.size();
        Pow.resize(n);
        Pow_inv.resize(n);
        Pow[0] = 1;
        Pow_inv[0] = 1;
        for (int i = 1; i < n; ++i) {
            Pow[i] = (Pow[i-1] * P) % MOD;
            Pow_inv[i] = powmod(Pow[i], MOD - 2, MOD);
        }
        H.resize(n);
        ll h = 0;
        for (int i = 0; i < n; ++i) {
            h = (h + (s[i] - '0' + 1) * Pow[i]) % MOD;
            H[i] = h;
        }
    }
    
    ll getHash(int l, int r) {
        if (l == 0) {
            return H[r];
        }
        return multmod(H[r] - H[l-1] + MOD, Pow_inv[l], MOD);
    }
    
}

class Solution {
public:
    int equalDigitFrequency(string s) {
        RH::pre(s);
        memset(pre, 0, sizeof pre);
        unordered_set<ll> vis;
        int n = (int)s.size();
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < N; ++j) {
                pre[i][j] = pre[i-1][j];
            }
            ++pre[i][s[i-1] - '0'];
        }
        bool haveAns;
        int temp;
        ll h;
        for (int l = 1; l <= n; ++l) {
            for (int r = l; r <= n; ++r) {
                haveAns = true;
                temp = -1;
                for (int i = 0; i < N; ++i) {
                    if (pre[r][i] - pre[l-1][i] > 0) {
                        if (temp == -1) {
                            temp = pre[r][i] - pre[l-1][i];
                        }
                        else if (temp != pre[r][i] - pre[l-1][i]) {
                            haveAns = false;
                            break;
                        }
                    }
                }
                if (haveAns) {
                    vis.insert(RH::getHash(l-1,r-1));
                }
            }
        }
        return (int)vis.size();
    }
};