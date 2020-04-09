// https://open.kattis.com/problems/grid
//
#include <bits/extc++.h>

using namespace std;

namespace SSSP {
    constexpr int MAX_NODES = 250005;
    constexpr int MAX_EDGES = 1000020;
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
    int node_number;
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
    priority_queue<Node> Q;
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
}

unordered_map<int, int> conversion;

int main() {
    
    int r, c;
    char ch;
    scanf("%d %d", &r, &c);
    vector<vector<int> > A(r, vector<int>(c));
    getchar_unlocked();
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%c", &ch);
            A.at(i).at(j) = ch - '0';
        }
        getchar_unlocked();
    }

    // indexing
    int node_number = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            ++node_number;
            conversion[i * c + j] = node_number;
        }
    }
    // Initialization
    for (int i = 1; i <= node_number; ++i) {
        SSSP::dis.at(i) = SSSP::INF;
    }


    int dist;
    int current_node;
    int new_node;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            dist = A.at(i).at(j);
            if (dist != 0) {
                current_node = conversion[i * c + j];
                // 4 directions
                try {
                    A.at(i).at(j - dist);
                    new_node = conversion[i * c + (j - dist)];
                    SSSP::add_edge(current_node, new_node, 1);
                } catch (...) {}
                try {
                    A.at(i).at(j + dist);
                    new_node = conversion[i * c + (j + dist)];
                    SSSP::add_edge(current_node, new_node, 1);
                } catch (...) {}
                try {
                    A.at(i - dist).at(j);
                    new_node = conversion[(i - dist) * c + j];
                    SSSP::add_edge(current_node, new_node, 1);
                } catch (...) {}
                try {
                    A.at(i + dist).at(j);
                    new_node = conversion[(i + dist) * c + j];
                    SSSP::add_edge(current_node, new_node, 1);
                } catch (...) {}
            }
        }
    }

    int top_left = 1;
    int buttom_right = node_number;
    SSSP::s = top_left;
    SSSP::dijkstra();
    if (SSSP::dis.at(buttom_right) == SSSP::INF) {
        printf("-1\n");
    } else {
        printf("%d\n", SSSP::dis.at(buttom_right));
    }

    return 0;
}
