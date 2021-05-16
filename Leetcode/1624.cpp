class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        constexpr int MAXN = 26;
        array<vector<int>, MAXN> stats{};
        int n = (int)s.size();
        for (int i = 0; i < n; ++i) {
            stats[s[i]-'a'].emplace_back(i);
        }
        int ans = -1;
        for (int i = 0; i < MAXN; ++i) {
            if (stats[i].size() > 1) {
                int length = (int)stats[i].size();
                for (int j = 0; j < length - 1; ++j) {
                    ans = max(ans, stats[i].back() - stats[i].front() - 1);
                }
            }
        }
        return ans;
    }
};