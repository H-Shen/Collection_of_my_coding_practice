// https://loj.ac/problem/10130
// 1. Use a father array to obtain the root of the tree
// 2. Use single dfs to get height of each node and store them in the array 'h'
// 3. Thus the distance of two nodes u and v = h(u) + h(v) - 2*h(lca(u,v))
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
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
        return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

namespace IO {
template <typename T>
inline void read(T &t) {
    int n = 0;
    int c = getchar_unlocked();
    t = 0;
    while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
    if (n)
        t = -t;
}

template <typename T, typename... Args>
inline void read(T &t, Args &... args) {
    read(t);
    read(args...);
}

template <typename T>
inline void write(T x) {
    if (x < 0)
        x = -x, putchar_unlocked('-');
    if (x > 9)
        write(x / 10);
    putchar_unlocked(x % 10 + 48);
}

template <typename T>
inline void writeln(T x) {
    write(x);
    putchar_unlocked('\n');
}
}  // namespace IO

namespace DSU {
// father[x]: the father of x
// Size[x]:  the size of tree/disjoint set whose ancestor is 'x'
vector<int> father;
vector<int> Size;
int number_of_sets;  // the number of disjoint sets

// iniitalization
inline void init(int n) {
    // reset
    vector<int>().swap(father);
    vector<int>().swap(Size);
    // initialize: 5 is an offset just in case
    father.resize(n + 5);
    iota(father.begin(), father.end(), 0);
    Size.resize(n + 5, 1);
    number_of_sets = n;
}

// find the ancestor of i with path compression
inline int find(int x) {
    if (x != father[x]) {
        father[x] = find(father[x]);
    }
    return father[x];
}

// merge x and y
inline void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    if (Size[x] > Size[y]) {  // Make sure the tree with less nodes combines to the tree with more nodes
        swap(x, y);
    }
    father[x] = y;
    Size[y] += Size[x];
    --number_of_sets;
}

// check if x and y are in the same set
inline bool is_same_group(int i, int j) { return find(i) == find(j); }

// check the size of set where 'x' is
inline int check_set_size(int x) { return Size[find(x)]; }

// check the number of disjoint sets
inline int number_of_disjoint_sets() { return number_of_sets; }
}  // namespace DSU

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
            unmap[{ u, v }] = ancestor.at(DSU::find(v));
            unmap[{ v, u }] = ancestor.at(DSU::find(v));
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
}  // namespace LCA0

constexpr int MAXN = 100005;
vector<int> father(MAXN, -1);
vector<vector<int> > adj(MAXN);
vector<int> h(MAXN);

void dfs(int u, int height) {
    h.at(u) = height;
    for (const auto &v : adj.at(u)) {
        dfs(v, height + 1);
    }
}

int main() {
    int n, m, s, u, v;
    IO::read(n);
    LCA0::init(MAXN);
    for (int i = 1; i <= n - 1; ++i) {
        IO::read(u, v);
        LCA0::adj.at(u).emplace_back(v);
        LCA0::adj.at(v).emplace_back(u);
        father.at(v) = u;
        s = u;
        adj.at(u).emplace_back(v);
    }
    // get father
    while (true) {
        if (father.at(s) == -1) {
            break;
        }
        s = father.at(s);
    }
    // get height for each node
    dfs(s, 0);
    vector<pair<int, int> > query_list;
    IO::read(m);
    for (int i = 1; i <= m; ++i) {
        IO::read(u, v);
        query_list.emplace_back(make_pair(u, v));
        LCA0::queries.at(u).emplace_back(v);
        LCA0::queries.at(v).emplace_back(u);
    }
    LCA0::Tarjan(s);  // Run Tarjan from root
    // output
    int ancestor, dist;
    for (const auto &[u, v] : query_list) {
        ancestor = LCA0::unmap[{ u, v }];
        dist = h.at(u) + h.at(v) - 2 * h.at(ancestor);
        IO::writeln(dist);
    }
    return 0;
}
