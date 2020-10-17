// https://open.kattis.com/problems/hauntedgraveyard
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using int128 = __int128;
using pii = pair<int, int>;

constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

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

namespace SSSP_SPFA {

    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pii> > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<int> dis;

    inline void
    reset() {
        vector<vector<pii> >().swap(adj);
        vector<int>().swap(dis);
        number_of_nodes = 0;
        source = 0;
    }

    inline void
    init(int n, int s) {
        vector<vector<pii> >().swap(adj);
        source = s;
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5, INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
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

int w, h, g, e;
int source, dest;
vector<vector<int> > M; // 0: walk, 1: gravestone, 2: haunted hole

inline
int convert(int i, int j) {
    return i * h + j;
}

int main() {

    int x, y, x1, y1, x2, y2, t, u, v;
    while (true) {

        IO::read(w, h);
        if (w == 0 && h == 0) break;
        source = convert(0, 0);
        dest = convert(w - 1, h - 1);
        M.resize(w, vector<int>(h, 0));
        SSSP_SPFA::init(w * h, source);

        IO::read(g);
        while (g--) {
            IO::read(x, y);
            M.at(x).at(y) = 1;
        }

        IO::read(e);
        while (e--) {
            IO::read(x1, y1, x2, y2, t);
            M.at(x1).at(y1) = 2;
            u = convert(x1, y1);
            v = convert(x2, y2);
            SSSP_SPFA::add_edge(u, v, t);
        }
        int new_i, new_j;
        for (int i = 0; i < w; ++i) {
            for (int j = 0; j < h; ++j) {
                // Skip the destination since there should be no edges start from the destination!
                if (i == w - 1 && j == h - 1) {
                    continue;
                }
                if (M.at(i).at(j) == 0) {
                    u = convert(i, j);
                    for (int step = 0; step < STEPS; ++step) {
                        new_i = i + dx[step];
                        new_j = j + dy[step];
                        if (new_i >= 0 && new_i < w && new_j >= 0 &&
                            new_j < h && M.at(new_i).at(new_j) != 1) {
                            v = convert(new_i, new_j);
                            SSSP_SPFA::add_edge(u, v, 1);
                        }
                    }
                }
            }
        }
        if (!SSSP_SPFA::spfa()) {
            puts("Never");
        } else if (SSSP_SPFA::dis.at(dest) == SSSP_SPFA::INF) {
            puts("Impossible");
        } else {
            IO::writeln(SSSP_SPFA::dis.at(dest));
        }
        // reset
        vector<vector<int> >().swap(M);
        SSSP_SPFA::reset();
    }
    return 0;
}
