vector<unordered_set<int>> AL;

namespace Topo {
    int n;
    vector<int> vis, result;
    bool dfs(int u) {
        vis[u] = -1;
        for (const auto &v : AL[u]) {
            if (vis[v] < 0) {
                return false;
            }
            else if (vis[v] == 0) {
                if (!dfs(v)) {
                    return false;
                }
            }
        }
        vis[u] = 1;
        result.emplace_back(u);
        return true;
    }
    bool topo() {
        n = (int)AL.size();
        vector<int>().swap(vis);
        vector<int>().swap(result);
        vis.resize(n);
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 0) {
                if (!dfs(i)) {
                    return false;
                }
            }
        }
        reverse(result.begin(),result.end());
        return true;
    }
    void reset() {
        n = (int)AL.size();
        vector<int>().swap(vis);
        vis.resize(n);
    }
    bool topo2(vector<int>& vec) {
        vector<int>().swap(result);
        for (auto &i : vec) {
            if (vis[i] == 0) {
                if (!dfs(i)) {
                    return false;
                }
            }
        }
        reverse(result.begin(),result.end());
        return true;
    }
    
}

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int maxGroupId = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = maxGroupId;
                ++maxGroupId;
            }
        }
        int u, v;
        // toposort groups
        decltype(AL)().swap(AL);
        AL.resize(maxGroupId);
        for (int i = 0; i < n; ++i) {
            v = group[i];
            for (const auto &j : beforeItems[i]) {
                u = group[j];
                if (v != u) {
                    AL[u].insert(v);
                }
            }
        }
        if (!Topo::topo()) {
            return vector<int>();
        }
        vector<int> ans(n);
        auto iter = ans.begin();
        vector<int> g;
        g.swap(Topo::result);
        vector<vector<int>> vec(maxGroupId);
        // toposort in each group
        for (int j = 0; j < n; ++j) {
            vec[group[j]].emplace_back(j);
        }
        decltype(AL)().swap(AL);
        AL.resize(n);
        Topo::reset();
        for (auto &elements : vec) {
            for (auto &element : elements) {
                v = element;
                for (auto &i : beforeItems[element]) {
                    u = i;
                    if (group[v] == group[u]) {
                        AL[u].insert(v);
                    }
                }
            }
            if (!Topo::topo2(elements)) {
                return vector<int>();
            }
            else {
                swap(elements, Topo::result);
            }
        }
        // output
        for (const auto &i : g) {
            for (const auto &j : vec[i]) {
                *iter = j;
                ++iter;
            }
        }
        return ans;
    }
};