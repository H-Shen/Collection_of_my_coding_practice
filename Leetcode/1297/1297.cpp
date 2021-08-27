using ll = long long;

constexpr ll PRIME = 31;
constexpr ll MOD = 1e9+9;
constexpr int MAXN = 26;
ll p_pow[MAXN];

ll getHash(const string &s, int i, int j) {
    ll ans = 0;
    for (int k = i, index = 0; k <= j; ++k, ++index) {
        // 'a'->1 'b'->2 ...
        ans = (ans + (s[k] - 'a' + 1)*p_pow[index]) % MOD;
    }
    return ans;
}

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        // pre
        p_pow[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            p_pow[i] = (p_pow[i-1] * PRIME) % MOD;
        }
        bitset<MAXN> bs;
        int n = (int)s.size();
        int maxOccur = 0;
        unordered_map<ll,int> unmap;
        for (int i = minSize; i <= maxSize; ++i) {
            for (int j = 0; i+j-1 < n; ++j) {
                bs.reset();
                for (int k = j; k <= i+j-1; ++k) {
                    bs[s[k]-'a'] = true;
                }
                if ((int)bs.count() <= maxLetters) {
                    ++unmap[getHash(s,j,i+j-1)];
                }
            }
        }
        for (const auto &[k,v] : unmap) maxOccur = max(maxOccur,v);
        return maxOccur;
    }
};