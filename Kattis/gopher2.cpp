// https://open.kattis.com/problems/gopher2
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-7;
inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

namespace MCBM {
    constexpr int MAX_NODES = 105;
    int uN, vN;
    int g[MAX_NODES][MAX_NODES];
    int linker[MAX_NODES];
    bool used[MAX_NODES];
    bool dfs(int u) {
        for (int v = 0; v < vN; ++v) {
            if (g[u][v] && !used[v]) {
                used[v] = true;
                if(linker[v] == -1 || dfs(linker[v])){
                    linker[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int hungary() {
        int res = 0;
        memset(linker, -1, sizeof(linker));
        for (int u = 0; u < uN; ++u) {
            memset(used, false, sizeof(used));
            if (dfs(u)) {
                ++res;
            }
        }
        return res;
    }
}

struct Node {
    double x, y;
};
vector<Node> gophers;
vector<Node> holes;

int main() {
    
    int n, m;
    double s, v;
    while (~scanf("%d %d %lf %lf", &n, &m, &s, &v)) {
        gophers.resize(n);
        for (auto &[x, y] : gophers) {
            scanf("%lf %lf", &x, &y);
        }
        holes.resize(m);
        for (auto &[x, y] : holes) {
            scanf("%lf %lf", &x, &y);
        }
        MCBM::uN = n;
        MCBM::vN = m;
        double dist;
        double max_dist = s * v;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dist = sqrt((gophers[i].x - holes[j].x) *
                            (gophers[i].x - holes[j].x) +
                            (gophers[i].y - holes[j].y) *
                            (gophers[i].y - holes[j].y));
                if (sgn(max_dist - dist) >= 0) {
                    MCBM::g[i][j] = 1;
                }
            }
        }
        printf("%d\n", n - MCBM::hungary());
        memset(MCBM::g, 0, sizeof(MCBM::g[0][0]) * MCBM::MAX_NODES * MCBM::MAX_NODES);
    }

    return 0;
}
