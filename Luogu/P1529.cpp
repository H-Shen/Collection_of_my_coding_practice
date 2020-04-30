#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace SSSP {
    constexpr int MAX_NODES = 130;
    constexpr int MAX_EDGES = 20005;
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

constexpr int MAXN = 3;
char u_[MAXN];
char v_[MAXN];

int main() {

    int n;
    int w;
    scanf("%d", &n);
    SSSP::reset();
    SSSP::s = 'Z';
    while (n--) {
        scanf("%s %s %d", u_, v_, &w);
        SSSP::add_edge(u_[0], v_[0], w);
        SSSP::add_edge(v_[0], u_[0], w);
    }
    SSSP::dijkstra();
    int min_dist = numeric_limits<int>::max();
    for (char ch = 'A'; ch < 'Z'; ++ch) {
        min_dist = min(min_dist, SSSP::dis.at(ch));
    }
    for (char ch = 'A'; ch < 'Z'; ++ch) {
        if (SSSP::dis.at(ch) == min_dist) {
            printf("%c %d\n", ch, SSSP::dis.at(ch));
            break;
        }
    }
    return 0;
}