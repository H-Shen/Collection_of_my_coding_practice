class Solution {
public:
    vector<vector<int> > AL;
    vector<int> d1, d2;
    void dfs(int u, int father_of_u) {
        d1[u] = 0;
        d2[u] = 0;
        for (const auto &v : AL[u]) {
            if (v != father_of_u) {
                dfs(v, u);
                int temp = d1[v] + 1;
                if (temp > d1[u]) {
                    d2[u] = d1[u];
                    d1[u] = temp;
                }
                else if (temp > d2[u]) {
                    d2[u] = temp;
                }
            }
        }
    }
    int treeDiameter(vector<vector<int>>& edges) {
        if (edges.empty()) {
            return 0;
        }
        int n = (int)edges.size()+1;
        AL.resize(n);
        d1.resize(n);
        d2.resize(n);
        for (const auto &i : edges) {
            AL[i[0]].emplace_back(i[1]);
            AL[i[1]].emplace_back(i[0]);
        }
        dfs(0, -1);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(d1[i] + d2[i], ans);
        }
        return ans;
    }
};