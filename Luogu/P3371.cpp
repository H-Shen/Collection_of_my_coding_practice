#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll NON_EXIST = 2147483647;

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

// An implementation of Shortest Path Faster Algorithm
namespace SSSP3 {
    constexpr ll INF = 0x3f3f3f3f3f;
    vector<vector<pair<int, ll> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<ll> dis;

    inline void
    init(int n, int s) {
        vector<vector<pair<int, ll> > >().swap(adj);
        source = s;
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5, INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    // O(mn)
    inline bool
    spfa() {
        vector<int> cnt(number_of_nodes + 5);
        vector<bool> in_queue(number_of_nodes + 5, false);
        queue<int> q;
        q.push(source);
        in_queue.at(source) = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue.at(u) = false;
            for (const auto &[v, w] : adj.at(u)) {
                if (dis.at(v) > dis.at(u) + w) {
                    dis.at(v) = dis.at(u) + w;
                    if (!in_queue.at(v)) {
                        q.push(v);
                        in_queue.at(v) = true;
                        ++cnt.at(v);
                        if (cnt.at(v) > number_of_nodes) {
                            return false;   // a negative cycle exists
                        }
                    }
                }
            }
        }
        return true;
    }
}

int main(int argc, char *argv[]) {

    int n, m, s, u, v;
    ll w;
    IO::read(n, m, s);
    SSSP3::init(n, s);
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, w);
        SSSP3::adj.at(u).emplace_back(make_pair(v, w));
    }
    // Case 1: the source is in a negative cycle
    if (!SSSP3::spfa()) {
        for (int i = 1; i <= n; ++i) {
            IO::write(NON_EXIST);
            putchar_unlocked(' ');
        }
        return 0;
    }
    // Case 2: the source is not in a negative cycle
    for (int i = 1; i <= n; ++i) {
        if (SSSP3::dis.at(i) == SSSP3::INF) {
            IO::write(NON_EXIST);
            putchar_unlocked(' ');
        } else {
            IO::write(SSSP3::dis.at(i));
            putchar_unlocked(' ');
        }
    }

    return 0;
}