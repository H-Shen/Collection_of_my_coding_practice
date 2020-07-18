#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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

// An implementation of Shortest Path Faster Algorithm
namespace SSSP3 {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<int> dis;

    inline void
    init(int n, int s) {
        vector<vector<pair<int, int> > >().swap(adj);
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

int main() {

    int n, m, s, t, w;
    int shortest_path_from_1_to_n;
    int shortest_path_from_n_to_1;
    IO::read(n, m);
    // check the shortest path from 1 to n
    SSSP3::init(n, 1);
    for (int i = 0; i < m; ++i) {
        IO::read(s, t, w);
        SSSP3::adj.at(s).emplace_back(make_pair(t, -w));
    }
    if (!SSSP3::spfa()) {
        fputs_unlocked("Forever love\n", stdout);
        return 0;
    } else {
        shortest_path_from_1_to_n = SSSP3::dis.at(n);
    }
    // reset
    SSSP3::source = n;
    fill(SSSP3::dis.begin(), SSSP3::dis.end(), SSSP3::INF);
    SSSP3::dis.at(SSSP3::source) = 0;
    // check the shortest path from n to 1
    if (!SSSP3::spfa()) {
        fputs_unlocked("Forever love\n", stdout);
        return 0;
    } else {
        shortest_path_from_n_to_1 = SSSP3::dis.at(1);
    }

    IO::writeln(min(shortest_path_from_1_to_n, shortest_path_from_n_to_1));

    return 0;
}