#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<int> dis;

    inline void
    reset() {
        vector<vector<pair<int, int> > >().swap(adj);
        vector<int>().swap(dis);
        number_of_nodes = 0;
        source = 0;
    }

    inline void
    init(int n) {
        vector<vector<pair<int, int> > >().swap(adj);
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5);
        adj.resize(number_of_nodes + 5);
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

int main() {

    int t, n, m, w, u, v, p;
    bool have_negative_cycle;
    IO::read(t);
    while (t--) {
        IO::read(n, m, w);
        SSSP3::init(n);
        for (int i = 0; i < m; ++i) {
            IO::read(u, v, p);
            SSSP3::adj.at(u).emplace_back(make_pair(v, p));
            SSSP3::adj.at(v).emplace_back(make_pair(u, p));
        }
        for (int i = 0; i < w; ++i) {
            IO::read(u, v, p);
            SSSP3::adj.at(u).emplace_back(make_pair(v, -p));
        }
        have_negative_cycle = false;
        // Enumerate source from 1 to n
        for (int s = 1; s <= n; ++s) {
            fill(SSSP3::dis.begin(), SSSP3::dis.end(), SSSP3::INF);
            SSSP3::source = s;
            SSSP3::dis.at(SSSP3::source) = 0;
            if (!SSSP3::spfa()) {
                have_negative_cycle = true;
                break;
            }
        }
        if (have_negative_cycle) {
            fputs_unlocked("YES\n", stdout);
        } else {
            fputs_unlocked("NO\n", stdout);
        }
        SSSP3::reset();
    }

    return 0;
}
