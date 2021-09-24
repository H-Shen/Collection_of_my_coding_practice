constexpr int INF = 0x3f3f3f3f;
constexpr int MAXN = 105;
constexpr int COLORS = 2;

int dist[MAXN][COLORS];
vector<vector<int>> al1, al2;

void bellmanford(int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int u = 0; u < n; ++u) {
            if (dist[u][0] != INF) {
                for (const auto &v : al2[u]) {
                    if (dist[v][1] > dist[u][0] + 1) {
                        dist[v][1] = dist[u][0] + 1;
                    }
                }
            }
            if (dist[u][1] != INF) {
                for (const auto &v : al1[u]) {
                    if (dist[v][0] > dist[u][1] + 1) {
                        dist[v][0] = dist[u][1] + 1;
                    }
                }
            }
        }
    }
}

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        memset(dist, 0x3f, sizeof dist);
        decltype(al1)().swap(al1);
        decltype(al2)().swap(al2);
        al1.resize(n);
        al2.resize(n);
        for (const auto &i : red_edges) {
            al1[i[0]].emplace_back(i[1]);
        }
        for (const auto &i : blue_edges) {
            al2[i[0]].emplace_back(i[1]);
        }
        dist[0][0] = 0;
        dist[0][1] = 0;
        bellmanford(n);
        vector<int> ans(n);
        int temp;
        for (int i = 0; i < n; ++i) {
            temp = min(dist[i][0], dist[i][1]);
            if (temp == INF) {
                ans[i] = -1;
            } else {
                ans[i] = temp;
            }
        }
        return ans;
    }
};