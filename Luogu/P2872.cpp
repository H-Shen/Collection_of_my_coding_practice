#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr double EPS = 1e-7;
constexpr int MAXN = 1050;

inline static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

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
        x = find(x), y = find(y);
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

vector<pair<double, double> > Farms(MAXN);

double dist(const pair<double, double> &l, const pair<double, double> &r) {
    return sqrt( (l.first-r.first)*(l.first-r.first)+(l.second-r.second)*(l.second-r.second) );
}

namespace Kruskal {
    struct Edge {
        int u, v;
        double w;
        explicit Edge(int u, int v, double w) : u(u), v(v), w(w) {}
    };
    bool cmp(const Edge &l, const Edge &r) {
        return sgn(l.w - r.w) < 0;
    }
    double init(vector<Edge> &E, int number_of_nodes) {
        double min_dist = 0.0;
        DSU::init(number_of_nodes);
        sort(E.begin(), E.end(), cmp);
        for (const auto &i : E) {
            if (!DSU::is_same_group(i.u, i.v)) {
                DSU::merge(i.u, i.v);
                min_dist += i.w;
            }
        }
        return min_dist;
    }
}

int main() {

    int n, m, u, v;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf %lf", &Farms.at(i).first, &Farms.at(i).second);
    }
    vector<Kruskal::Edge> E;
    // All m roads have been constructed before, thus each of them cost 0
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        E.emplace_back(Kruskal::Edge(u, v, 0.0));
    }
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            E.emplace_back(i, j, dist(Farms.at(i), Farms.at(j)));
        }
    }
    printf("%.2lf\n", Kruskal::init(E, n));

    return 0;
}
