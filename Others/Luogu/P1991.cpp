#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double EPS = 1e-7;
inline int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

namespace DSU {
    vector<int> father;
    vector<int> Size;
    inline
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    inline
    int find(int x) {
        if (father[x] != x) father[x] = find(father[x]);
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    inline
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

namespace Kruskal {
    struct Edge {
        int u, v;
        double w;
        Edge(int u, int v, double w) : u(u), v(v), w(w) {}
    };
    bool cmp(const Edge &l, const Edge &r) {
        return sgn(l.w - r.w) < 0;
    }
    vector<Edge> init(vector<Edge> A, int number_of_nodes, int satellite) {
        DSU::init(number_of_nodes);
        sort(A.begin(), A.end(), cmp);
        vector<Edge> result;
        int length = 0;
        for (const auto &i : A) {
            if (!DSU::is_same_group(i.u, i.v)) {
                DSU::merge(i.u, i.v);
                result.emplace_back(i);
                ++length;
                if (length == number_of_nodes - satellite) {
                    break;
                }
            }
        }
        return result;
    }
}

struct Node {
    double x, y;
};

int main() {

    int s, p;
    scanf("%d %d", &s, &p);
    vector<Node> A(p);
    for (int i = 0; i < p; ++i) {
        scanf("%lf %lf", &A.at(i).x, &A.at(i).y);
    }
    vector<Kruskal::Edge> M;
    double dist;
    for (int i = 0; i < p - 1; ++i) {
        for (int j = i + 1; j < p; ++j) {
            dist = sqrt((A.at(i).x-A.at(j).x)*(A.at(i).x-A.at(j).x) + (A.at(i).y-A.at(j).y)*(A.at(i).y-A.at(j).y));
            M.emplace_back(Kruskal::Edge(i, j, dist));
        }
    }
    auto result = Kruskal::init(M, p, s);
    double D = 0.0;
    if (!result.empty()) {
        D = result.back().w;
    }
    printf("%.2lf\n", D);
    return 0;
}
