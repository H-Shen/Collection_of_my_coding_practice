using ll = long long;

constexpr int MAXN = 2*1e4+5;

ll Pow[MAXN];
ll H[MAXN];

inline ll getHash(string &s, int l, int r, ll mod) {
    ll h = 0;
    for (int i = l; i <= r; ++i) {
        h = (h + (s[i]-'a'+1)*Pow[i-l])%mod;
    }
    return h % mod;
}


class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        Pow[0] = 1;
        ll mod = modulo;
        for (int i = 1; i < MAXN; ++i) {
            Pow[i] = (Pow[i-1] * power) % mod;
        }
        H[0] = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            H[i+1] = (H[i] + (s[i] - 'a' + 1) * Pow[i]) % mod;
        }
        for (int i = 0; i + k - 1 < (int)s.size(); ++i) {
            ll curHash = (H[i+k] + mod - H[i]) % mod;
            // re-confirm
            if (curHash == (ll)hashValue * Pow[i] % mod && getHash(s,i,i+k-1,mod) == (ll)hashValue) {
                return s.substr(i, k);
            }
        }
        return string();
    }
};