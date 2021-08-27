constexpr int MAXN = 1e5+5;
bitset<MAXN> vis;

class Solution {
public:
    vector<vector<int> > AL;
    vector<int> father;
    void dfs(int u, int father_of_u) {
        father[u] = father_of_u;
        for (const auto &v : AL[u]) {
            if (v != father_of_u) {
                dfs(v, u);
            }
        }
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        decltype(AL)().swap(AL);
        AL.resize(n);
        father.resize(n);
        vis.reset();
        for (const auto &i : edges) {
            AL[i[0]].emplace_back(i[1]);
            AL[i[1]].emplace_back(i[0]);
        }
        dfs(0,-1);
        int u, v;
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (hasApple[i]) {
                int id = i;
                while (father[id] != -1) {
                    u = id;
                    v = father[id];
                    if (vis[u]) {
                        break;
                    }
                    vis[u] = true;
                    id = father[id];
                }
            }
        }
        return vis.count() * 2;
    }
};