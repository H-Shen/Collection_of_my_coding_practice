#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 100005;

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
};
int nodes[MAXN];
vector<bool> vis;
unordered_map<int, unordered_set<int>, custom_hash> adj;
int u, v;
bool has_self_loop = false;
bool has_cycle = false;
int id = 1;
int edges = 0;

void reset() {
    has_self_loop = false;
    has_cycle = false;
    memset(nodes, 0, MAXN * sizeof(int));
    adj.clear();
    vector<bool>().swap(vis);
    id = 1;
    edges = 0;
}

bool is_cyclic(int node_id, int father_node_id) {
    vis.at(node_id) = true;
    for (const auto adj_node_id : adj[node_id]) {
        if (!vis.at(adj_node_id)) {
            if (is_cyclic(adj_node_id, node_id)) {
                return true;
            }
        } else if (adj_node_id != father_node_id) {
            return true;
        }
    }
    return false;
}

int main() {

    while (true) {
        IO::read(u, v);
        if (u == -1 && v == -1) {
            break;
        }
        else if (u == 0 && v == 0) {
            // output
            if (has_self_loop) {
                IO::writeln(0);
                reset();
                continue;
            }
            // check if it is a component with n nodes and n-1 edges
            DSU::init(id);
            for (const auto &[k, v_list] : adj) {
                for (const auto &v_ : v_list) {
                    DSU::merge(k, v_);
                }
            }
            int total_nodes = id - 1;
            unordered_set<int> groups;
            for (int i = 1; i <= total_nodes; ++i) {
                groups.insert(DSU::find(i));
            }
            if (!(1 == static_cast<int>(groups.size()) && edges == total_nodes - 1)) {
                IO::writeln(0);
                reset();
                continue;
            }
            // check if it has a cycle
            vis.resize(total_nodes + 5, false);
            for (int i = 1; i <= total_nodes; ++i) {
                if (!vis.at(i)) {
                    if (is_cyclic(i, -1)) {
                        has_cycle = true;
                        break;
                    }
                }
            }
            if (has_cycle) {
                IO::writeln(0);
            }
            // otherwise, the maze is correct
            else {
                IO::writeln(1);
            }
            reset();
        } else {
            if (nodes[u] == 0) {
                nodes[u] = id;
                ++id;
            }
            if (nodes[v] == 0) {
                nodes[v] = id;
                ++id;
            }
            if (u == v) {
                has_self_loop = true;
            } else {
                adj[nodes[u]].insert(nodes[v]);
                adj[nodes[v]].insert(nodes[u]);
                ++edges;
            }
        }
    }
    return 0;
}