#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

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

namespace MDST {
    constexpr ll INF = 0x3f3f3f3f3f3f;
    struct Edge {
        explicit Edge(int u, int v, ll w) : u(u), v(v), w(w) {}
        Edge() = default;
        int u, v;
        ll w;
    };
    vector<Edge> edges;
    vector<int> pre;
    vector<int> id;
    vector<int> visit;
    vector<ll> in;

    void reset() {
        vector<Edge>().swap(edges);
        vector<int>().swap(pre);
        vector<int>().swap(id);
        vector<int>().swap(visit);
        vector<ll>().swap(in);
    }

    // return the sum of MDST, or -INF if there is no MDST
    ll Edmonds(int root, int number_of_nodes) {

        // init
        int number_of_edges = (int)edges.size();
        pre.resize(number_of_nodes + 5);
        id.resize(number_of_nodes + 5);
        visit.resize(number_of_nodes + 5);
        in.resize(number_of_nodes + 5);

        ll result = 0;
        int u, v, tn;
        while (true) {
            for (int i = 0; i < number_of_nodes; ++i) {
                in.at(i) = INF;
            }
            for (int i = 0; i < number_of_edges; ++i) {
                if (edges.at(i).u != edges.at(i).v &&
                    edges.at(i).w < in.at(edges.at(i).v)) {
                    pre.at(edges.at(i).v) = edges.at(i).u;
                    in.at(edges.at(i).v) = edges.at(i).w;
                }
            }
            for (int i = 0; i < number_of_nodes; ++i) {
                if (i != root && in.at(i) == INF) {
                    return -INF;    // No MDST exists
                }
            }
            tn = 0;
            fill(id.begin(), id.end(), -1);
            fill(visit.begin(), visit.end(), -1);
            in.at(root) = 0;
            for (int i = 0; i < number_of_nodes; ++i) {
                result += in.at(i);
                v = i;
                while (visit.at(v) != i && id.at(v) == -1 && v != root) {
                    visit.at(v) = i;
                    v = pre.at(v);
                }
                if (v != root && id.at(v) == -1) {
                    for (u = pre.at(v); u != v; u = pre.at(u)) {
                        id.at(u) = tn;
                    }
                    id.at(v) = tn;
                    ++tn;
                }
            }
            if (tn == 0) {
                break;  // No cycles found
            }
            for (int i = 0; i < number_of_nodes; ++i) {
                if (id.at(i) == -1) {
                    id.at(i) = tn;
                    ++tn;
                }
            }
            for (int i = 0; i < number_of_edges; ) {
                v = edges.at(i).v;
                edges.at(i).u = id.at(edges.at(i).u);
                edges.at(i).v = id.at(edges.at(i).v);
                if (edges.at(i).u != edges.at(i).v) {
                    edges.at(i).w -= in.at(v);
                    ++i;
                } else {
                    swap(edges.at(i), edges.at(--number_of_edges));
                }
            }
            number_of_nodes = tn;
            root = id.at(root);
        }
        return result;
    }
}

int n, m, r, u, v;
ll w;
vector<unordered_map<int, ll, custom_hash> > adj;

int main() {

    IO::read(n, m, r);
    --r;
    adj.resize(n + 5);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, w);
        // offset by 1
        --u;
        --v;
        if (u == v) continue;
        if (adj.at(u).find(v) == adj.at(u).end()) {
            adj.at(u)[v] = w;
        } else {
            adj.at(u)[v] = min(adj.at(u)[v], w);
        }
    }
    // add edges
    for (int i = 0; i < n; ++i) {
        for (const auto &[j, k] : adj.at(i)) {
            MDST::edges.emplace_back(i, j, k);
        }
    }
    ll result = MDST::Edmonds(r, n);
    if (result == -MDST::INF) {
        IO::writeln(-1);
    } else {
        IO::writeln(result);
    }

    return 0;
}