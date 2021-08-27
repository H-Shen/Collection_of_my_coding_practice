class Solution {
public:
    bool exist(const vector<vector<int> > &stats, const string &s) {
        int a = s[0] - 'a';
        int b = s[1] - 'a';
        if (a == b) return stats[a].size() > 2;
        if (stats[a].size() < 2) return false;
        if (stats[b].size() < 1) return false;
        auto iter = upper_bound(stats[b].begin(),stats[b].end(), stats[a].front());
        if (iter == stats[b].end() || *iter > stats[a].back()) return false;
        return true;
    }
    int countPalindromicSubsequence(string s) {
        constexpr int MAXN = 26;
        vector<vector<int> > stats(MAXN);
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) stats[s[i] - 'a'].emplace_back(i);
        int ans = 0;
        string str = "aaa";
        for (char i = 'a'; i <= 'z'; ++i) {
            for (char j = 'a'; j <= 'z'; ++j) {
                str[0] = str[2] = i;
                str[1] = j;
                if (exist(stats, str)) ++ans;
            }
        }
        return ans;
    }
};