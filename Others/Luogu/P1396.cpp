#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

namespace Kruskal {
    struct Edge {
        int u, v, w;
    };
    bool cmp(const Edge &l, const Edge &r) {
        return l.w < r.w;
    }
    int init(vector<Edge> &E, int number_of_nodes, int s, int t) {
        int max_w = -1;
        DSU::init(number_of_nodes);
        sort(E.begin(), E.end(), cmp);
        for (const auto &[u, v, w] : E) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                max_w = max(w, max_w);
                if (DSU::is_same_group(s, t)) {
                    return max_w;
                }
            }
        }
        return max_w;
    }
}

int main() {

    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    vector<Kruskal::Edge> E(m);
    for (auto &[u, v, w] : E) {
        scanf("%d %d %d", &u, &v, &w);
    }
    printf("%d\n", init(E, n, s, t));
    return 0;
}
