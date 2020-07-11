#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int DIRECTIONS = 8;

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

namespace SSSP {

    constexpr int INF = 0x3f3f3f3f;

    struct Edge {
        int to;
        int distance;
        int next;
        bool operator==(const Edge &other) const {
            return to == other.to && distance == other.distance &&
                   next == other.next;
        }
    };
    struct Node {
        int distance;
        int position;
        explicit Node(int distance, int pos) : distance(distance),
                                               position(pos) {}
        bool operator<(const Node &x) const {
            return (x.distance < distance);
        }
    };

    vector<Edge> E;
    vector<int> head;
    int counter;
    vector<int> dis;
    vector<bool> vis;
    std::priority_queue<Node> q;
    int source;

    void init(int number_of_nodes, int number_of_edges) {
        E.resize(number_of_edges + 5);
        head.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
        vis.resize(number_of_nodes + 5);
    }

    inline void
    add_edge(int u, int v, int d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }

    inline void dijkstra() {
        dis.at(source) = 0;
        q.push(Node(0, source));
        while (!q.empty()) {
            Node tmp = q.top();
            q.pop();
            int x = tmp.position;
            // Base case
            if (vis.at(x)) {
                continue;
            }
            vis.at(x) = true;
            for (int i = head.at(x); i; i = E.at(i).next) {
                int y = E.at(i).to;
                if (dis.at(y) > dis.at(x) + E.at(i).distance) {
                    dis.at(y) = dis.at(x) + E.at(i).distance;
                    if (!vis.at(y)) {
                        q.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }
}

int di[DIRECTIONS];
int dj[DIRECTIONS];
int m, n, m1, m2;
int origin_i, origin_j, dest_i, dest_j;
vector<vector<int> > M;
vector<vector<bool> > vis;
unordered_map<int, unordered_set<int, custom_hash>, custom_hash> G;

void dfs(int last, int i, int j) {
    if (M.at(i).at(j) == 0 || M.at(i).at(j) == 2) {
        return;
    }
    int pos = i * n + j;
    if (last != -1) {
        G[last].insert(pos);
    }
    if (vis.at(i).at(j)) {
        return;
    }
    vis.at(i).at(j) = true;
    if (i == dest_i && j == dest_j) {
        return;
    }
    // iterate 8 directions
    int new_i;
    int new_j;
    for (int k = 0; k < DIRECTIONS; ++k) {
        new_i = i + di[k];
        new_j = j + dj[k];
        if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n) {
            dfs(i * n + j, new_i, new_j);
        }
    }
}

int main(int argc, char *argv[]) {

    IO::read(m, n, m1, m2);
    vector<int> dx_ = {m2, -m2, m2, -m2, m1, -m1, m1, -m1};
    vector<int> dy_ = {m1, m1, -m1, -m1, m2, m2, -m2, -m2};
    for (int i = 0; i < DIRECTIONS; ++i) {
        di[i] = dx_.at(i);
        dj[i] = dy_.at(i);
    }

    M.resize(m, vector<int>(n));
    vis.resize(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            IO::read(M.at(i).at(j));
            if (M.at(i).at(j) == 3) {
                origin_i = i;
                origin_j = j;
            } else if (M.at(i).at(j) == 4) {
                dest_i = i;
                dest_j = j;
            }
        }
    }
    dfs(-1, origin_i, origin_j);
    int total_edges = 0;
    for (const auto &[k, v_list] : G) {
        total_edges += static_cast<int>(v_list.size());
    }
    SSSP::init(n * m, total_edges);
    for (const auto &[k, v_list] : G) {
        for (const auto &v : v_list) {
            SSSP::add_edge(k, v, 1);
        }
    }
    SSSP::source = origin_i * n + origin_j;
    SSSP::dijkstra();
    IO::writeln(SSSP::dis.at(dest_i * n + dest_j));

    return 0;
}