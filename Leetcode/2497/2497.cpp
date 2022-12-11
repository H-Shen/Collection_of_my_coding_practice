class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n = (int)vals.size();
        vector<vector<int>> adj(n);
        int u,v;
        for (auto&i : edges) {
            u = i[0];
            v = i[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        int maxVal = numeric_limits<int>::min();
        for (auto&i : adj) {
            sort(i.begin(), i.end(), [&](const auto &l, const auto &r){
                return vals[l] > vals[r];
            });
        }
        for (int i = 0; i < n; ++i) {
            int temp = vals[i];
            int length = min(k, (int)adj[i].size());
            for (int j = 0; j < length; ++j) {
                if (vals[adj[i][j]] <= 0) {
                    break;
                }
                temp += vals[adj[i][j]];
            }
            maxVal = max(maxVal, temp);
        }
        return maxVal;
    }
};