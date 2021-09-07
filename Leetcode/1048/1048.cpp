constexpr int MAXN = 1e3+5;

bitset<MAXN> reach[MAXN];
vector<int> dp;
int length;

class Solution {
public:
    // reduce it to longest path
    bool predecessor(string& a, string& b) {
        int n = (int)a.size();
        int m = (int)b.size();
        if (n != m-1) {
            return false;
        }
        bool flag = false;
        for (int i = 0, j = 0; i < n;) {
            if (a[i] == b[j]) {
                ++i;
                ++j;
            } else {
                if (flag) {
                    return false;
                }
                flag = true;
                ++j;
            }
        }
        return true;
    }
    int solve(int u) {
        if (dp[u] != -1) {
            return dp[u];
        }
        dp[u] = 1;
        for (int i = 0; i < length; ++i) {
            if (i != u && reach[i][u]) {
                dp[u] = max(dp[u], solve(i) + 1);
            }
        }
        return dp[u];
    }
    int longestStrChain(vector<string>& words) {
        for (auto &i : reach) {
            i.reset();
        }
        vector<int>().swap(dp);
        length = (int)words.size();
        int u, v;
        for (int i = 0; i < length-1; ++i) {
            for (int j = i+1; j < length; ++j) {
                if (predecessor(words[i], words[j])) {
                    reach[i][j] = true;
                }
                if (predecessor(words[j], words[i])) {
                    reach[j][i] = true;
                }
            }
        }
        dp.resize(length, -1);
        int ans = 0;
        for (int i = 0; i < length; ++i) {
            ans = max(ans, solve(i));
        }
        return ans;
    }
};