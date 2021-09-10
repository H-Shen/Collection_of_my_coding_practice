constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 105;

int am[MAXN][MAXN];
int stats[MAXN];

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Floyd-Warshall: O(n^3)
        memset(am, 0x3f, sizeof am);
        for (int i = 0; i < n; ++i) {
            am[i][i] = 0;
        }
        int u,v,w;
        for (const auto &e : edges) {
            u = e[0];
            v = e[1];
            w = e[2];
            am[u][v] = w;
            am[v][u] = w;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    // am[i][j] = min(am[i][j], am[i][k]+am[k][j])
                    am[i][j] = min(am[i][j], am[i][k]+am[k][j]);
                }
            }
        }
        memset(stats, 0, sizeof stats);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && am[i][j] <= distanceThreshold) {
                    ++stats[i];
                }
            }
        }
        int minReachableCities = INF;
        for (int i = 0; i < n; ++i) {
            minReachableCities = min(minReachableCities, stats[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            if (stats[i] == minReachableCities) {
                return i;
            }
        }
        return -1;
    }
};