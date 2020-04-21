#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace IO {
    template<typename T>
    inline void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }

    template<typename T, typename... Args>
    inline void read(T &t, Args &... args) {
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
    vector<int>father;
    vector<int>Size;
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
        explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };
    bool cmp(const Edge &l, const Edge &r) {
        return l.w < r.w;
    }
    int init(vector<Edge> &E, int number_of_nodes) {
        DSU::init(number_of_nodes);
        sort(E.begin(), E.end(), cmp);
        int sum = 0;
        for (const auto &[u, v, w] : E) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                sum += w;
            }
        }
        // return -1 if no such network can be built
        if (DSU::Size[DSU::find(0)] != number_of_nodes) {
            return -1;
        }
        return sum;
    }
}

int n, c;
struct Node {
    int x, y;
};
bool is_valid(const Node &l, const Node &r, int &cost) {
    cost = (l.x-r.x)*(l.x-r.x)+(l.y-r.y)*(l.y-r.y);
    return cost >= c;
}

int main() {

    IO::read(n, c);
    vector<Node> A(n);
    for (int i = 0; i < n; ++i) {
        IO::read(A.at(i).x, A.at(i).y);
    }
    int cost;
    vector<Kruskal::Edge> E;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (is_valid(A.at(i), A.at(j), cost)) {
                E.emplace_back(i, j, cost);
            }
        }
    }
    IO::writeln(Kruskal::init(E, n));

    return 0;
}