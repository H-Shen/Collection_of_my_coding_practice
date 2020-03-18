// https://open.kattis.com/problems/blockcrusher
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int r, c;
vector<vector<char> > A;

pair<int, int> convert(int pos) {
    pair<int, int> result;
    result.first = pos / c;
    result.second = pos % c;
    return result;
}
int convert(int i, int j) {
    return c*i+j;
}

namespace SSSP {
    constexpr int MAX_NODES = 1205;
    constexpr int MAX_EDGES = 10005;
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
    vector<int> prev(MAX_NODES, -1);
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
    inline void dijkstra(bool store_path = false) {
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
                    if (store_path) {
                        prev.at(y) = x;
                    }
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
    vector<int> get_path(int t) {
        vector<int> path;
        for(; t!=-1; t=prev.at(t))
            path.push_back(t);
        reverse(path.begin(),path.end());
        return path;
    }

}

int main() {

    while (true) {
        scanf("%d %d", &r, &c);
        if (r == 0 && c == 0) break;
        getchar();
        A.resize(r, vector<char>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                scanf("%c", &A.at(i).at(j));
            }
            getchar();
        }
        // build the graph
        char temp;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                // left
                try {
                    temp = A.at(i).at(j - 1);
                    SSSP::add_edge(convert(i, j), convert(i, j - 1),
                                   A.at(i).at(j) - '0');
                } catch (...) {}
                // right
                try {
                    temp = A.at(i).at(j + 1);
                    SSSP::add_edge(convert(i, j), convert(i, j + 1),
                                   A.at(i).at(j) - '0');
                } catch (...) {}
                // up
                try {
                    temp = A.at(i - 1).at(j);
                    SSSP::add_edge(convert(i, j), convert(i - 1, j),
                                   A.at(i).at(j) - '0');
                } catch (...) {}
                // down
                try {
                    temp = A.at(i + 1).at(j);
                    SSSP::add_edge(convert(i, j), convert(i + 1, j),
                                   A.at(i).at(j) - '0');
                } catch (...) {}
                // left-diagonal
                try {
                    temp = A.at(i + 1).at(j - 1);
                    SSSP::add_edge(convert(i, j), convert(i + 1, j - 1),
                                   A.at(i).at(j) - '0');
                } catch (...) {}
                try {
                    temp = A.at(i - 1).at(j - 1);
                    SSSP::add_edge(convert(i, j), convert(i - 1, j - 1),
                                   A.at(i).at(j) - '0');
                } catch (...) {}
                // right-diagonal
                try {
                    temp = A.at(i + 1).at(j + 1);
                    SSSP::add_edge(convert(i, j), convert(i + 1, j + 1),
                                   A.at(i).at(j) - '0');
                } catch (...) {}
                try {
                    temp = A.at(i - 1).at(j + 1);
                    SSSP::add_edge(convert(i, j), convert(i - 1, j + 1),
                                   A.at(i).at(j) - '0');
                } catch (...) {}
            }
        }
        int min_strength = numeric_limits<int>::max();
        // Get the minimum strength
        for (int i = 0; i < c; ++i) {
            SSSP::s = convert(0, i);
            SSSP::reset();
            SSSP::dijkstra();
            for (int j = 0; j < c; ++j) {
                min_strength = min(
                        min_strength,
                        SSSP::dis.at(convert(r - 1, j)) +
                        static_cast<int>(A.at(r - 1).at(j)));
            }
        }
        int origin_i{};
        int origin_j{};
        int dest_i{};
        int dest_j{};
        bool flag;
        for (int i = 0; i < c; ++i) {
            SSSP::s = convert(0, i);
            SSSP::reset();
            SSSP::dijkstra();
            flag = false;
            for (int j = 0; j < c; ++j) {
                if (SSSP::dis.at(convert(r - 1, j)) +
                    static_cast<int>(A.at(r - 1).at(j)) == min_strength) {
                    origin_i = 0;
                    origin_j = i;
                    dest_i = r - 1;
                    dest_j = j;
                    flag = true;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        SSSP::s = convert(origin_i, origin_j);
        SSSP::reset();
        SSSP::dijkstra(true);
        vector<int> path = SSSP::get_path(convert(dest_i, dest_j));

        // output
        for (const int &i : path) {
            auto p = convert(i);
            A.at(p.first).at(p.second) = ' ';
        }
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                printf("%c", A.at(i).at(j));
            }
            printf("\n");
        }
        printf("\n");

        // reset
        SSSP::counter = 0;

        vector<int>().swap(SSSP::prev);
        SSSP::prev.resize(SSSP::MAX_NODES, -1);

        vector<SSSP::Edge>().swap(SSSP::E);
        SSSP::E.resize(SSSP::MAX_EDGES);

        vector<int>().swap(SSSP::head);
        SSSP::head.resize(SSSP::MAX_NODES);

        vector<vector<char> >().swap(A);
    }

    return 0;
}
