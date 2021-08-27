class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        constexpr int MAXN = 103;
        bitset<MAXN> reach[MAXN]{};
        for (int i = 0; i < n; ++i) {
            reach[i][i] = true;
        }
        for (const auto &i : prerequisites) {
            reach[i.front()][i.back()] = true;
        }
        // floyd warshall
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (reach[i][k]) {
                    reach[i] |= reach[k];
                }
            }
        }
        vector<bool> result(queries.size());
        for (size_t i = 0; i != queries.size(); ++i) {
            result[i] = reach[queries[i].front()][queries[i].back()];
        }
        return result;
    }
};