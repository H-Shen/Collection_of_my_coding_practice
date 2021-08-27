namespace MST_Prim_ {
    constexpr int INF = 0x3f3f3f3f;
    constexpr int MAXN = 1005;
    struct Edge {
        int w = INF;
        int to = -1;
    };
    int adj[MAXN][MAXN];    // adjacency matrix
    Edge minE[MAXN];
    bool prim(int &total_weight, int n) {
        total_weight = 0;
        bitset<MAXN> vis;
        minE[0].w = 0;
        for (int i = 0; i < n; ++i) {
            int v = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (v == -1 || minE[j].w < minE[v].w)) {
                    v = j;
                }
            }
            if (minE[v].w == INF) {
                return false;   // No MST exists
            }
            vis[v] = true;
            total_weight += minE[v].w;
            for (int to = 0; to < n; ++to) {
                if (adj[v][to] < minE[to].w) {
                    minE[to] = {adj[v][to], v};
                }
            }
        }
        return true;
    }
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = (int)points.size();
        memset(MST_Prim_::adj, 0x3f, sizeof(MST_Prim_::adj));
        for (int i = 0; i < n; ++i) {
            MST_Prim_::minE[i].w = MST_Prim_::INF;
            MST_Prim_::minE[i].to = -1;
        }
        int dist;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                MST_Prim_::adj[i][j] = dist;
                MST_Prim_::adj[j][i] = dist;
            }
        }
        int result;
        if (!MST_Prim_::prim(result, n)) {
            return -1;
        }
        return result;
    }
};