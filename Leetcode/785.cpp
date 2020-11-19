class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        constexpr int INF = 0x3f3f3f3f;
        int n = (int)graph.size();
        vector<int> color(n, INF);
        bool result = true;
        // bfs from 0
        queue<int> q;
        for (int s = 0; s < n; ++s) {
            if (color.at(s) == INF) {
                color.at(s) = 0;
                q.push(s);
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const auto &v : graph.at(u)) {
                    if (color.at(v) == INF) {
                        color.at(v) = 1 - color.at(u);
                        q.push(v);
                    } else if (color.at(v) == color.at(u)) {
                        result = false;
                        return result;
                    }
                }
            }
        }
        return result;
    }
};