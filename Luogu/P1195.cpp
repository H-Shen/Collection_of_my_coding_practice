#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
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
        x = find(x),
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
        explicit Edge(int u, int v, int w) :
        u(u), v(v), w(w) {}
        Edge() = default;
    };
    bool cmp(const Edge &l, const Edge &r) {
        return l.w < r.w;
    }
    int init(vector<Edge> &E, int number_of_nodes, int k) {
        int components = 0;
        DSU::init(number_of_nodes);
        sort(E.begin(), E.end(), cmp);
        int result = 0;
        for (const auto &[u, v, w] : E) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                ++components;
                result += w;
                if (components + k == number_of_nodes) {
                    return result;
                }
            }
        }
        return -1;
    }
}

vector<Kruskal::Edge> E;

int main() {

    int n, m, k;
    IO::read(n, m, k);
    E.resize(m);
    for (int i = 0; i < m; ++i) {
        IO::read(E.at(i).u, E.at(i).v, E.at(i).w);
    }
    int result = Kruskal::init(E, n, k);
    if (result != -1) {
        IO::writeln(result);
    } else {
        printf("No Answer\n");
    }

    return 0;
}