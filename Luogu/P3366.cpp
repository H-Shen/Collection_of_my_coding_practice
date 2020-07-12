#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }

    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

// DSU: Union_Find_Set
// Complexity: O (a(n)) per operation. Note: O (log n) if one of
// union-by-size or path compression is omitted
// a(n) is the inverse Ackermann function
namespace DSU {
    // father[x]: the father of x
    // Size[x]:  the rank, rank is the size of the tree whose root is x
    vector<int> father;
    vector<int> Size;

    // iniitalization
    inline
    void init(int n) {
        // reset
        vector<int>().swap(father);
        vector<int>().swap(Size);
        // initialize: 5 is an offset just in case
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }

    // find the ancestor of i with path compression
    inline
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }

    // merge x and y
    inline
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] >
            Size[y]) {  // Make sure the tree with less nodes combines to the tree with more nodes
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }

    // check if x and y are in the same set
    inline
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
    }
}

// The collection of methods and data structures are used to obtain an MST of a
// undirected-graph using Kruskal's algorithm with Disjoint Set
// Usage: vector<Edge> A(n), .... , MST0::kruskal(A, n);
namespace MST0 {
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        // For a pair of integers
        size_t operator()(pair<uint64_t, uint64_t> x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x.first + FIXED_RANDOM) ^
                   (splitmix64(x.second + FIXED_RANDOM) >> 1);
        }
    };

    struct Edge {
        int u, v;
        int w;

        explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}

        Edge() = default;
    };

    inline
    vector<Edge> kruskal(const vector<Edge> &E, int number_of_nodes) {
        // initialize a DSU
        DSU::init(number_of_nodes);
        // We use a hash-map to store the minimal weight between a pair of nodes
        unordered_map<pair<int, int>, int, custom_hash> unmap;
        pair<int, int> temp_pair;
        decltype(unmap)::iterator temp_iter;
        for (const auto &[u, v, w] : E) {
            if (u > v) {
                temp_pair.first = v;
                temp_pair.second = u;
            } else {
                temp_pair.first = u;
                temp_pair.second = v;
            }
            temp_iter = unmap.find(temp_pair);
            if (temp_iter == unmap.end()) {
                unmap[temp_pair] = w;
            } else {
                temp_iter->second = min(w, temp_iter->second);
            }
        }
        vector<Edge> E_filter(unmap.size());
        int index = 0;
        for (const auto &[nodes, w] : unmap) {
            E_filter.at(index).u = nodes.first;
            E_filter.at(index).v = nodes.second;
            E_filter.at(index).w = w;
            ++index;
        }
        // sort by the edge's weight in increasing order
        sort(E_filter.begin(), E_filter.end(),
             [](const Edge &lhs, const Edge &rhs) {
                 return (lhs.w < rhs.w);
             });

        vector<Edge> minimum_spanning_tree;
        // int cost = 0;    // to calculate the total weight of the MST
        for (const auto &[u, v, w] : E_filter) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                minimum_spanning_tree.emplace_back(Edge(u, v, w));
                // cost += w;
            }
        }
        return minimum_spanning_tree;
    }
}


int main() {

    int n, m;
    IO::read(n, m);
    vector<MST0::Edge> E(m);
    int temp_edge = 1;
    for (auto &[u, v, w] : E) {
        IO::read(u, v, w);
        temp_edge = u;
    }
    auto result = MST0::kruskal(E, n);
    if (DSU::Size[DSU::find(temp_edge)] != n) {
        fputs_unlocked("orz\n", stdout);
    } else {
        // sum the cost of all edges
        ll cost = 0;
        for (auto &[u, v, w] : result) {
            cost += w;
        }
        IO::writeln(cost);
    }
    return 0;
}
