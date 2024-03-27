class Solution {
public:
    bool check(const string& s, int l, int r) {
        unordered_map<char,int> freq;
        for (int i = l; i <= r; ++i) {
            ++freq[s[i]];
            if (freq[s[i]] > 2) return false;
        }
        return true;
    }
    int maximumLengthSubstring(string s) {
        int n = (int)s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (j-i+1 < ans) continue;
                if (check(s,i,j)) {
                    ans = max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};