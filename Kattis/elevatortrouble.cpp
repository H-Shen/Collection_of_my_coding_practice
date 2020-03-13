// https://open.kattis.com/problems/elevatortrouble
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 1000005;

namespace SSSP {
    constexpr int MAX_NODES = 1000005;
    constexpr int MAX_EDGES = 3500000;
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

bool vis[MAXN];
int f, s, g, u, d;
unordered_map<int, unordered_set<int> > E;

void dfs(int last, int n) {
    if (last != -1) {
        E[last].insert(n);
    }
    if (vis[n]) {
        return;
    }
    vis[n] = true;
    if (n == g) {
        return;
    }
    // up
    int up = n + u;
    if (up >= 1 && up <= f) {
        dfs(n, up);
    }
    // down
    int down = n - d;
    if (down >= 1 && down <= f) {
        dfs(n, down);
    }
}

int main() {

    //freopen("/Users/hshen/myCpp/input", "r", stdin);
    scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
    dfs(-1, s);
    if (!vis[g]) {
        printf("use the stairs\n");
    } else {
        SSSP::reset();
        SSSP::s = s;
        for (const auto &[u_, v_list] : E) {
            for (const auto &v_ : v_list) {
                SSSP::add_edge(u_, v_, 1);
            }
        }
        SSSP::dijkstra();
        printf("%d\n", SSSP::dis.at(g));
    }

    return 0;
}
