#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

using int128 = __int128_t;
using uint128 = __uint128_t;

inline
string print_int128(int128 a) {
    if (!a) {
        return "0";
    }
    string s;
    while (a) {
        s = char(llabs((long long) (a % 10)) + '0') + s;
        if (a < 0 && a > -10) {
            s = '-' + s;
        }
        a /= 10;
    }
    return s;
}

inline
int128 stoint128(const string &s) {
    int128 a = 0, sgn = 1;
    for (const char &ch : s) {
        if (ch == '-') sgn *= -1;
        else a = a * 10 + sgn * (ch - '0');
    }
    return a;
}

auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
};

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }
    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
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
}

// Lowest Common Ancestor - Tarjan's off-line algorithm
// O(n + m) for m queries
namespace LCA0 {

    vector<vector<int> > adj;
    vector<int> ancestor;
    vector<bool> vis;
    vector<vector<int> > queries;
    unordered_map<pii, int, custom_hash> unmap;

    void Tarjan(int u) {
        vis.at(u) = true;
        ancestor.at(u) = u;
        for (const auto &v : adj.at(u)) {
            if (!vis.at(v)) {
                Tarjan(v);
                DSU::merge(u, v);
                ancestor.at(DSU::find(u)) = u;
            }
        }
        for (const auto v : queries.at(u)) {
            if (vis.at(v)) {
                unmap[{u, v}] = ancestor.at(DSU::find(v));
                unmap[{v, u}] = ancestor.at(DSU::find(v));
            }
        }
    }

    void init(int n) {
        DSU::init(n);
        ancestor.resize(n + 5);
        vis.resize(n + 5, false);
        adj.resize(n + 5);
        queries.resize(n + 5);
    }
}

int n, m, s, u, v;

// n nodes, (n - 1) edges, the root is s, m queries,
// for each query, u and v are given, print lca of u and v
int main() {

    IO::read(n, m);
    LCA0::init(n);
    for (int i = 1; i <= n - 1; ++i) {
        u = i + 1;
        IO::read(v);
        LCA0::adj.at(u).emplace_back(v);
        LCA0::adj.at(v).emplace_back(u);
    }
    for (int i = 2; i <= n; ++i) {
        LCA0::adj.at(i).emplace_back(1);
        LCA0::adj.at(1).emplace_back(i);
    }

    vector<pair<int, int> > query_list;
    for (int i = 1; i <= m; ++i) {
        IO::read(u, v);
        query_list.emplace_back(make_pair(u, v));
        LCA0::queries.at(u).emplace_back(v);
        LCA0::queries.at(v).emplace_back(u);
    }
    s = 1;
    LCA0::Tarjan(s);    // Run Tarjan from root
    // output
    for (const auto &[u, v] : query_list) {
        if (LCA0::unmap[{u, v}] != v) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}
