class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> in_degree(n);
        for (const auto &i : edges) {
            in_degree[i[1]] = true;
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (!in_degree[i]) {
                result.emplace_back(i);
            }
        }
        return result;
    }
};