// https://open.kattis.com/problems/jurassicjigsaw
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 12;
char cstr[MAXN];

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
        int w;
        Edge(int u, int v, int w) : u(u), v(v), w(w) {}
        Edge() = default;
    };
    bool cmp(const Edge &lhs, const Edge &rhs) {
        return (lhs.w < rhs.w);
    }
    vector<Edge> init(vector<Edge> &E, int number_of_nodes) {
        DSU::init(number_of_nodes);
        sort(E.begin(), E.end(), cmp);
        vector<Edge> MST;
        for (const auto &[u, v, w] : E) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                MST.emplace_back(Edge(u, v, w));
            }
        }
        return MST;
    }
}

int main() {

    int n, k;
    scanf("%d %d", &n, &k);
    vector<string> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", cstr);
        A.at(i) = cstr;
    }
    vector<Kruskal::Edge> E;
    int counter;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            counter = 0;
            for (int index = 0; index < k; ++index) {
                if (A.at(i).at(index) != A.at(j).at(index)) {
                    ++counter;
                }
            }
            E.emplace_back(Kruskal::Edge(i, j, counter));
        }
    }
    auto result = Kruskal::init(E, n);
    int cost = 0;
    for (const auto &[u, v, w] : result) {
        cost += w;
    }
    printf("%d\n", cost);
    for (const auto &[u, v, w] : result) {
        printf("%d %d\n", u, v);
    }

    return 0;
}
