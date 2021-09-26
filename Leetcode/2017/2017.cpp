using ll = long long;

class Solution {
public:
    // 贪心枚举第一个robot1转弯的所有可能性 并计算所有可能性下robot2能collect的最大值
    long long gridGame(vector<vector<int>>& grid) {
        int m = (int)grid[0].size();
        vector<ll> pre1(m+1);
        for (int i = 1; i <= m; ++i) {
            pre1[i] = pre1[i-1] + (ll)grid[0][i-1];
        }
        vector<ll> pre2(m+1);
        for (int i = 1; i <= m; ++i) {
            pre2[i] = pre2[i-1] + (ll)grid[1][i-1];
        }
        ll sum1 = accumulate(grid[0].begin(),grid[0].end(),(ll)0);
        ll minVal = numeric_limits<ll>::max();
        if (m > 1) {
            for (int i = 0; i <= m-1; ++i) {
                // robot1第一格就拐
                if (i == 0) {
                    minVal = min(minVal, sum1-pre1[1]);
                }
                // robot1最后一格才拐
                else if (i == m-1) {
                    minVal = min(minVal, pre2[m-1]);
                }
                // robot1中间拐
                else {
                    // robot2会贪心地选取最大值
                    minVal = min(minVal, max(sum1-pre1[i+1], pre2[i]));
                }
            }
        }
        return minVal;
    }
};