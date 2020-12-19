class Solution {
public:
    unordered_map<int, int> dp;
    int solve(int n) {
        if (dp.find(n) != dp.end()) return dp[n];
        if (n % 2 == 0) {
            dp[n] = solve(n / 2) + 1;
        } else {
            dp[n] = solve(3 * n + 1) + 1;
        }
        return dp[n];
    }
    int getKth(int lo, int hi, int k) {
        constexpr int MAXN = 1000;
        dp[1] = 0;
        for (int i = 1; i <= MAXN; ++i) {
            dp[i] = solve(i);
        }
        vector<int> temp(hi - lo + 1);
        iota(temp.begin(), temp.end(), lo);
        sort(temp.begin(), temp.end(), [&](int l, int r) {
            if (dp[l] == dp[r]) return l < r;
            return dp[l] < dp[r];
        });
        return temp.at(k - 1);
    }
};