// https://open.kattis.com/problems/gridmst
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int INF = 0x3f3f3f3f;
constexpr int MAX_NODES = 100005;
constexpr int MAXN = 1005;
constexpr int STEPS = 4;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

struct Node {
    int x, y, id;
    explicit Node(int x, int y, int id) : x(x), y(y), id(id) {}
    Node() = default;
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

namespace DSU {
    vector<int> father, Size;
    int number_of_sets;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
        number_of_sets = n;
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
        --number_of_sets;
    }
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
    }
    int check_set_size(int x) {
        return Size[find(x)];
    }
    int number_of_disjoint_sets() {
        return number_of_sets;
    }
}

namespace MST_Kruskal {
    struct Edge {
        int u, v;
        int w;
        explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}
        Edge() = default;
    };

    inline
    ll kruskal(vector<Edge> &E) {
        // sort by the edge's weight in increasing order
        sort(E.begin(), E.end(),
             [](const Edge &lhs, const Edge &rhs) {
                 return (lhs.w < rhs.w);
             });

        ll cost = 0;    // to calculate the total weight of the MST
        for (const auto &[u, v, w] : E) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                cost += w;
            }
        }
        return cost;
    }
}

int dist[MAXN][MAXN];
queue<Node> q;
int n, x, y, global_id;
vector<pair<int, int> > original_points;

void bfs() {
    Node cur;
    int new_x, new_y;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        for (int step = 0; step < STEPS; ++step) {
            new_x = cur.x + dx[step];
            new_y = cur.y + dy[step];
            if (new_x >= 0 && new_x < MAXN && new_y >= 0 && new_y < MAXN && dist[new_x][new_y] == INF) {
                dist[new_x][new_y] = cur.id;
                q.push(Node(new_x, new_y, cur.id));
            }
        }
    }
}

int manhattan_dist(const pair<int, int> &l, const pair<int, int> &r) {
    return abs(l.first-r.first) + abs(l.second-r.second);
}

int main() {

    IO::read(n);
    memset(dist, 0x3f, sizeof dist);
    for (int i = 0; i < n; ++i) {
        IO::read(x, y);
        if (dist[x][y] == INF) {
            dist[x][y] = global_id;
            q.push(Node(x, y, global_id));
            original_points.emplace_back(x, y);
            ++global_id;
        }
    }
    bfs();

    // create edges
    vector<MST_Kruskal::Edge> edges;
    int new_i, new_j, u, v, w;
    for (int i = 0; i < MAXN; ++i) {
        for (int j = 0; j < MAXN; ++j) {
            for (int step = 0; step < STEPS; ++step) {
                new_i = i + dx[step];
                new_j = j + dy[step];
                if (new_i >= 0 && new_i < MAXN && new_j >= 0 && new_j < MAXN && dist[new_i][new_j] != dist[i][j]) {
                    u = dist[i][j];
                    v = dist[new_i][new_j];
                    w = manhattan_dist(original_points.at(u), original_points.at(v));
                    edges.emplace_back(u, v, w);
                }
            }
        }
    }
    DSU::init(MAX_NODES);
    IO::writeln(MST_Kruskal::kruskal(edges));

    return 0;
}
