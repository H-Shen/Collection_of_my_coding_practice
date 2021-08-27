// an O(n^2) answer, almost TLE
class Solution {
public:
    static const int MAXN = 5005;
    bitset<MAXN> AM[MAXN];
    int dp[MAXN];
    int id;
    int DP(int source) {
        if (dp[source] > 0) {
            return dp[source];
        }
        for (size_t i = AM[source]._Find_first(); i < AM[source].size(); i = AM[source]._Find_next(i)) {
            dp[source] = max(dp[source], DP((int)i) + 1);
        }
        return dp[source];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        bitset<MAXN> bs;
        id = (int)envelopes.size();
        for (int i = 0; i < id; ++i) {
            for (int j = 0; j < id; ++j) {
                if (envelopes[i][0] < envelopes[j][0] && envelopes[i][1] < envelopes[j][1]) {
                    AM[i][j] = true;
                    bs[i] = true;
                }
            }
        }
        // dp to get the longest path in the graph
        int longestPath = 0;
        for (size_t i = bs._Find_first(); i < bs.size(); i = bs._Find_next(i))
            longestPath = max(longestPath, DP((int)i));
        return longestPath + 1;
    }
};