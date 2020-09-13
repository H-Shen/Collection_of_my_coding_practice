#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;

constexpr int MAXN = 400005;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(const uint64_t &x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

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
        if (father[x] != x) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    inline
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
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

bitset<MAXN> is_broken;
vector<int> broken;
vector<vector<int> > adj;   // the adjacency list that includes broken nodes
vector<pii> edges;

int main() {

    int n, m;
    IO::read(n, m);
    DSU::init(n);
    adj.resize(n + 5);
    edges.resize(m);
    for (auto &[u, v] : edges) {
        IO::read(u, v);
        adj.at(u).emplace_back(v);
        adj.at(v).emplace_back(u);
    }
    int k;
    IO::read(k);
    broken.resize(k);
    for (auto &i : broken) {
        IO::read(i);
        is_broken[i] = true;
    }
    int connected_components = n - k;
    for (const auto &[u, v] : edges) {
        if (!is_broken[u] && !is_broken[v] && !DSU::is_same_group(u, v)) {
            DSU::merge(u, v);
            --connected_components;
        }
    }
    vector<int> output;
    output.emplace_back(connected_components);
    reverse(broken.begin(), broken.end());
    for (const auto &u : broken) {
        is_broken[u] = false;
        ++connected_components; // the 'u' appears as a new component
        for (const auto &v : adj.at(u)) {
            if (!is_broken[v] && !DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                --connected_components;
            }
        }
        output.emplace_back(connected_components);
    }
    reverse(output.begin(), output.end());
    for (const auto &i : output) {
        IO::writeln(i);
    }
    return 0;
}
