class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        constexpr int MAXN = 2*1e5+5;
        bitset<MAXN> vis;
        vector<int> AL[MAXN]{};
        for (const auto &i : edges) {
            AL[i[0]].emplace_back(i[1]);
            AL[i[1]].emplace_back(i[0]);
        }
        queue<int> q;
        q.push(start);
        vis[start] = true;
        while (!q.empty()) {
            int u = q.front();
            if (u == end) {
                return true;
            }
            q.pop();
            for (const auto &v : AL[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};