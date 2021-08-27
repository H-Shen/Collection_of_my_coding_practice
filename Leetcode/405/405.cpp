const string mapping = "0123456789abcdef";
using ll = long long;

class Solution {
public:
    string f(ll n) {
        string s;
        while (n > 0) {
            s.push_back(mapping[n % 16]);
            n /= 16;
        }
        if (s.empty()) {
            s = "0";
        }
        while (s.back() == '0' && s.size() > 1) {
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        return s;
    }
    ll f(const string &s) {
        ll res = 0;
        int n = (int)s.size();
        vector<ll> p(n+1);
        p[0] = 1;
        for (int i = 1; i < n+1; ++i) {
            p[i] = p[i-1] * 16;
        }
        int index = 0;
        unordered_map<char,int> unmap;
        for (int i = 0; i < 16; ++i) {
            unmap[mapping[i]] = i;
        }
        for (int i = 0; i < n; ++i) {
            res += p[n-1-i] * unmap[s[i]];
        }
        return res;
    }
    string toHex(int num) {
        if (num >= 0) {
            return f(num);
        }
        unordered_map<char,char> unmap;
        for (int i = 0; i < 8; ++i) {
            unmap[mapping[i]] = mapping[15-i];
            unmap[mapping[15-i]] = mapping[i];
        }
        string s = f(-1LL*num);
        while (s.size() < 8) {
            s = '0' + s;
        }
        for (auto &i : s) {
            i = unmap[i];
        }
        return f(f(s)+1);
    }
};