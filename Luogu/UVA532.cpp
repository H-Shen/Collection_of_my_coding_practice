#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 35;
char A[MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN];
char cstr[MAXN];

int l, r, c;
int origin_i, origin_j, origin_k;
int dest_i, dest_j, dest_k;

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
unordered_map<int, unordered_set<int, custom_hash>, custom_hash > E;

vector<tuple<int, int, int> > transitions = {
        {0, 0, 1},
        {0, 0, -1},
        {0, -1, 0},
        {0, 1, 0},
        {-1, 0, 0},
        {1, 0, 0},
};

int convert(int i, int j, int k) {
    return r*c*i + c*j + k;
}

void dfs(int last, int i, int j, int k) {
    if (A[i][j][k] == '#') {
        return;
    }
    int pos = convert(i, j, k);
    if (last != -1) {
        E[last].insert(pos);
    }
    if (vis[i][j][k]) {
        return;
    }
    vis[i][j][k] = true;
    if (i == dest_i && j == dest_j && k == dest_k) {
        return;
    }
    int new_i, new_j, new_k;
    for (const auto &step : transitions) {
        new_i = i + get<0>(step);
        new_j = j + get<1>(step);
        new_k = k + get<2>(step);
        if (new_i >= 1 && new_i <= l && new_j >= 1 && new_j <= r && new_k >= 1 && new_k <= c) {
            dfs(pos, new_i, new_j, new_k);
        }
    }
}

namespace SSSP {
    constexpr int MAX_NODES = 42880;
    constexpr int MAX_EDGES = 1000005;
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
    vector<Edge> E(MAX_EDGES);
    vector<int> head(MAX_NODES);
    int counter;
    vector<int> dis(MAX_NODES);
    vector<bool> vis(MAX_NODES);
    int s;

    inline void
    add_edge(int u, int v, int d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }
    struct Node {
        int distance;
        int position;

        explicit Node(int distance, int pos) : distance(distance), position(pos) {}

        bool operator<(const Node &x) const {
            return (x.distance < distance);
        }
    };
    std::priority_queue<Node> Q;
    inline void dijkstra() {
        dis.at(s) = 0;
        Q.push(Node(0, s));
        while (!Q.empty()) {
            Node tmp = Q.top();
            Q.pop();
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
                        Q.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }
    inline void reset() {
        fill(dis.begin(), dis.end(), INF);
        vector<bool>().swap(vis);
        vis.resize(MAX_NODES);
        Q = std::priority_queue<Node>();
    }
}

int main() {

    while (true) {
        scanf("%d %d %d", &l, &r, &c);
        if (l == 0 && r == 0 && c == 0) break;
        for (int i = 1; i <= l; ++i) {
            for (int j = 1; j <= r; ++j) {
                scanf("%s", cstr);
                for (int k = 1; k <= c; ++k) {
                    A[i][j][k] = cstr[k - 1];
                    if (A[i][j][k] == 'S') {
                        origin_i = i;
                        origin_j = j;
                        origin_k = k;
                    } else if (A[i][j][k] == 'E') {
                        dest_i = i;
                        dest_j = j;
                        dest_k = k;
                    }
                }
            }
        }

        dfs(-1, origin_i, origin_j, origin_k);
        SSSP::s = convert(origin_i, origin_j, origin_k);
        SSSP::reset();
        for (const auto &i : E) {
            for (const auto &j : i.second) {
                SSSP::add_edge(i.first, j, 1);
            }
        }
        SSSP::dijkstra();
        int answer = SSSP::dis.at(convert(dest_i, dest_j, dest_k));
        if (answer != SSSP::INF) {
            printf("Escaped in %d minute(s).\n", answer);
        } else {
            printf("Trapped!\n");
        }

        // reset
        memset(A, 0, sizeof(char) * MAXN * MAXN * MAXN);
        memset(vis, 0, sizeof(bool) * MAXN * MAXN * MAXN);
        E.clear();
        SSSP::counter = 0;
        vector<SSSP::Edge>().swap(SSSP::E);
        SSSP::E.resize(SSSP::MAX_EDGES);
        vector<int>().swap(SSSP::head);
        SSSP::head.resize(SSSP::MAX_NODES);
    }

    return 0;
}
