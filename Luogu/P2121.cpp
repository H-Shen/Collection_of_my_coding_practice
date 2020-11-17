#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

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

namespace DSU {
    vector<int> father;
    vector<int> Size;
    void init(int n) {
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
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

namespace MaximalSpanningTree {
    struct Edge {
        int u, v, w, neg_w;
        explicit Edge(int u, int v, int w) : u(u), v(v), w(w), neg_w(-w) {}
        Edge() = default;
    };
    inline
    ll kruskal(vector<Edge> &E, const int &k) {
        sort(E.begin(), E.end(), [](const Edge &l, const Edge &r) {
            return (l.neg_w < r.neg_w);
        });
        ll max_sum = 0;
        int counter = 0;
        for (const auto &[u, v, w, neg_w] : E) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                max_sum += w;
                ++counter;
                if (counter == k) {
                    break;
                }
            }
        }
        return max_sum;
    }
}

int main() {

    int n, m, K, u, v, w;
    IO::read(n, m, K);
    DSU::init(n);
    vector<MaximalSpanningTree::Edge> E;
    while (m--) {
        IO::read(u, v, w);
        E.emplace_back(MaximalSpanningTree::Edge(u, v, w));
    }
    IO::writeln(MaximalSpanningTree::kruskal(E, K));
    return 0;
}