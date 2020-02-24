// https://open.kattis.com/problems/communicationssatellite
//
#pragma GCC optimize("Ofast")
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr double EPS = 1e-8;
inline static
int sgn(const double &x) {
    if (x > EPS) {
        return 1;
    }
    if (x > -EPS) {
        return 0;
    }
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
        if (father[x] != x) {
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

// The collection of methods and data structures for Kruskal's algorithm
namespace Kruskal {
    struct Edge {
        int u, v;
        double w;
        Edge(int u, int v, double w) : u(u), v(v), w(w) {}
        Edge() = default;
    };
    bool cmp(const Edge &lhs, const Edge &rhs) {
        return sgn(lhs.w - rhs.w) == -1;
    }

    double init(vector<Edge> E, int number_of_nodes) {
        double cost = 0;
        DSU::init(number_of_nodes);
        sort(E.begin(), E.end(), cmp);
        for (const auto &[u, v, w] : E) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                cost += w;
            }
        }
        return cost;
    }
}

struct Node {
    int id;
    int x;
    int y;
    double r;
};

int main() {

    int n;
    scanf("%d", &n);
    vector<Node> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %lf", &A.at(i).x, &A.at(i).y, &A.at(i).r);
        A.at(i).id = i;
    }
    vector<Kruskal::Edge> E;
    double dist;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dist = sqrt((A[i].x-A[j].x)*(A[i].x-A[j].x)+(A[i].y-A[j].y)*(A[i].y-A[j].y))-A[i].r-A[j].r;
            E.emplace_back(Kruskal::Edge(A[i].id, A[j].id, dist));
        }
    }
    printf("%.8lf\n", Kruskal::init(E, n));

    return 0;
}
