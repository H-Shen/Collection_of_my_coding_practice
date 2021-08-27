constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int bellmanford(const vector<vector<int>>& edges, int n, int src, int dst, int k) {
        vector<int> dist(n, INF);
        dist[src] = 0;
        int u, v, w;
        for (int i = 0; i < k+1; ++i) {
            vector<int> last = dist;
            for (const auto &j : edges) {
                u = j[0]; v = j[1]; w = j[2];
                // relax
                if (dist[v] > last[u] + w) {
                    dist[v] = last[u] + w;
                }
            }
        }
        return (dist[dst] >= INF) ? -1 : dist[dst]; // no negative weights in the graph
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return bellmanford(flights, n, src, dst, k);
    }
};