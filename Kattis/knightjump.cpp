// https://open.kattis.com/problems/knightjump
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace SSSP {
    constexpr int MAX_NODES = 10005;
    constexpr int MAX_EDGES = 5000005;
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

vector<vector<bool> > vis;
unordered_map<int, unordered_set<int> > E;
vector<vector<char> > A;
int n;

vector<pair<int, int> > transitions = {
        {2, -1},
        {2, 1},
        {-2, -1},
        {-2, 1},
        {1, -2},
        {1, 2},
        {-1, -2},
        {-1, 2}
};

void dfs(int last, int i, int j) {
    if (A.at(i).at(j) == '#') {
        return;
    }
    int pos = i*n+j;
    if (last != -1) {
        E[last].insert(pos);
    }
    if (vis.at(i).at(j)) {
        return;
    }
    vis.at(i).at(j) = true;
    if (i == 0 && j == 0) {
        return;
    }
    int new_i, new_j;
    for (const auto &step : transitions) {
        new_i = i + step.first;
        new_j = j + step.second;
        if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < n) {
            dfs(pos, new_i, new_j);
        }
    }
}

int main() {

    int knight_i{};
    int knight_j{};
    scanf("%d", &n);
    getchar();
    A.resize(n, vector<char>(n));
    vis.resize(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%c", &A.at(i).at(j));
            if (A.at(i).at(j) == 'K') {
                knight_i = i;
                knight_j = j;
            }
        }
        getchar();
    }
    dfs(-1, knight_i, knight_j);
    if (!vis.at(0).at(0)) {
        printf("-1\n");
    } else {
        SSSP::reset();
        for (const auto &[u, v_list] : E) {
            for (const auto &v : v_list) {
                SSSP::add_edge(u, v, 1);
            }
        }
        SSSP::s = knight_i * n + knight_j;
        SSSP::dijkstra();
        printf("%d\n", SSSP::dis.at(0));
    }
    return 0;
}
