class Solution {
public:
    vector<unordered_set<int> > AL;
    unordered_map<int, int> inDegree;
    vector<int> vis;
    bool dfs(int u) {
        vis[u] = -1;
        for (const auto &v : AL[u]) {
            if (vis[v] == -1) {
                return false;
            }
            else if (vis[v] == 0) {
                if (!dfs(v)) {
                    return false;
                }
            }
        }
        vis[u] = 1;
        return true;
    }
    bool toposort(int n) {
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) {
                if (!dfs(i)) {
                    return false;
                }
            }
        }
        return true;
    }
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        AL.resize(n+1);
        for (int i = 1; i <= n; ++i) {
            inDegree[i] = 0;
        }
        vis.resize(n+1);
        for (const auto &i : relations) {
            AL[i[0]].insert(i[1]);
            ++inDegree[i[1]];
        }
        if (!toposort(n)) {
            return -1;
        }
        int sem = 0;
        while (!inDegree.empty()) {
            vector<int> vec;
            for (const auto &[k, v] : inDegree) {
                if (v == 0) {
                    vec.emplace_back(k);
                }
            }
            for (const auto &u : vec) {
                inDegree.erase(u);
                for (const auto &v : AL[u]) {
                    --inDegree[v];
                }
                AL[u].clear();
            }
            ++sem;
        }
        return sem;
    }
};