using ll = long long;

class Solution {
public:
    long long fixedRatio(string s, int num1, int num2) {
        // ratio = N(0) / N(1) = (r-(l-1))/(pre[r]-pre[l-1])
        int n = (int)s.size();
        vector<ll> pre(n+1);
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i-1] + ((s[i-1] == '1') ? 1 : 0);
        }
        vector<ll> f(n+1);
        for (int i = 0; i <= n; ++i) {
            f[i] = (ll)(num1+num2)*pre[i] - (ll)num2*i;
        }
        unordered_map<ll, ll> freq;
        for (int i = 0; i <= n; ++i) {
            ++freq[f[i]];
        }
        ll cnt = 0;
        for (const auto &[k,v] : freq) {
            if (v > 1) {
                cnt += (v*(v-1)>>1);
            }
        }
        return cnt;
    }
};