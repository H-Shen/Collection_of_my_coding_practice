using ll = long long;

class Solution {
public:
    ll f1(const string&text, string& pattern) {
        vector<int>v1, v2;
        string s = pattern[0] + text;
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == pattern[0]) v1.emplace_back(i);
            else if (s[i] == pattern[1]) v2.emplace_back(i);
        }
        if (v1.empty() || v2.empty()) return 0;
        ll ans = 0;
        for (auto&i : v1) {
            ans += (ll)(v2.end() - lower_bound(v2.begin(),v2.end(),i));
        }
        return ans;
    }
    ll f2(const string&text, string& pattern) {
        vector<int>v1, v2;
        string s = text + pattern[1];
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == pattern[0]) v1.emplace_back(i);
            else if (s[i] == pattern[1]) v2.emplace_back(i);
        }
        if (v1.empty() || v2.empty()) return 0;
        ll ans = 0;
        for (auto&i : v1) {
            ans += (ll)(v2.end() - lower_bound(v2.begin(),v2.end(),i));
        }
        return ans;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        if (pattern[0] == pattern[1]) {
            ll cnt = 0;
            for (auto&i : text) {
                if (i == pattern[0]) ++cnt;
            }
            ++cnt;
            return cnt*(cnt-1)/2;
        }
        return max(f1(text, pattern), f2(text, pattern));
    }
};