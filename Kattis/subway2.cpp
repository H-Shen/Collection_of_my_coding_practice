// https://open.kattis.com/problems/subway2

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr double WALK = 10*1000*1.0/60;
constexpr double SUBWAY = 4.0*WALK;

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

// An implementation of Floyd_Warshall Algorithm O(n^3) for finding
// all pairs of shortest path in a graph
namespace APSP {
    constexpr double INF = 0x3f3f3f3f3f * 1.0;
    vector<vector<double> > am; // adjacency matrix
    int n;
    void init(int number_of_nodes) {
        // reset
        vector<vector<double> >().swap(am);
        n = number_of_nodes;
        am.resize(n, vector<double>(n, INF));
        for (int i = 0; i < n; ++i) {
            am[i][i] = 0.0;
        }
    }
    void floyd_warshall() { // order: k, i, j
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (am[i][k] < INF && am[k][j] < INF) {
                        if (am[i][j] > am[i][k] + am[k][j]) {
                            am[i][j] = am[i][k] + am[k][j];
                        }
                    }
    }
    double dist(const int &u, const int &v) {
        return am[u][v];
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
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().
                        time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM =
                chrono::steady_clock::now().
                time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

unordered_map<pair<int, int>, int, custom_hash> node2id;
vector<pair<int, int> > id2node;
int id;
vector<vector<int> > stations;

double dist(const pair<int, int> &l, const pair<int, int> &r, double speed) {
    return sqrt((l.first-r.first)*(l.first-r.first)+(l.second-r.second)*(l.second-r.second)) / speed;
}

int main() {

    int x, y;
    IO::read(x, y);
    // home: id = 0
    node2id[{x, y}] = id;
    id2node.emplace_back(x, y);
    ++id;
    // school: id = 1
    IO::read(x, y);
    node2id[{x, y}] = id;
    id2node.emplace_back(x, y);
    ++id;
    vector<int> vec;
    pair<int, int> temp;
    while (IO::can_read(x, y)) {
        if (x == -1 && y == -1) {
            stations.emplace_back(vec);
            decltype(vec)().swap(vec);
        } else {
            temp.first = x;
            temp.second = y;
            if (node2id.find(temp) == node2id.end()) {
                node2id[temp] = id;
                id2node.emplace_back(x, y);
                vec.emplace_back(id);
                ++id;
            } else {
                vec.emplace_back(node2id[temp]);
            }
        }
    }
    APSP::init(id);
    double d;
    int u, v;
    int n = (int)stations.size();
    for (int i = 0; i < n; ++i) {
        int m = (int)stations.at(i).size();
        for (int j = 0; j < m - 1; ++j) {
            u = stations.at(i).at(j);
            v = stations.at(i).at(j + 1);
            d = dist(id2node[u], id2node[v], SUBWAY);
            APSP::am[u][v] = d;
            APSP::am[v][u] = d;
        }
    }
    for (int i = 0; i < id; ++i) {
        for (int j = 0; j < id; ++j) {
            if (APSP::am[i][j] == APSP::INF) {
                APSP::am[i][j] = dist(id2node[i], id2node[j], WALK);
            }
        }
    }
    APSP::floyd_warshall();
    IO::writeln(lround(APSP::dist(0, 1)));

    return 0;
}
