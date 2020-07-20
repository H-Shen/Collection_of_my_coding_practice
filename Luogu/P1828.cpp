#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAX_NODES = 805;

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

// The implementation of Dijkstra using adjacency list
namespace SSSP_Dijkstra_0 {
    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    struct Edge {
        int to, distance, next;
        bool operator==(const Edge &other) const {
            return to == other.to && distance == other.distance &&
                   next == other.next;
        }
    };

    struct Node {
        int distance, position;
        explicit Node(int distance, int position) : distance(distance),
                                                    position(position) {}
        bool operator<(const Node &other) const {
            return (other.distance < distance);
        }
    };

    // Containers to store the graph
    vector<Edge> E;
    vector<int> head;
    int counter;
    int number_of_nodes;
    int number_of_edges;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    bitset<MAX_NODES> vis;
    int source;         // the node id of the source
    std::priority_queue<Node> pq;

    inline void
    init(int n, int e) {
        number_of_nodes = n;
        number_of_edges = e;
        // initialize the containers
        E.resize(number_of_edges + 5);
        head.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
    }

    inline void
    reset() {
        fill(dis.begin(), dis.end(), INF);
        vis.reset();
        std::priority_queue<Node>().swap(pq);
    }

    inline void
    add_edge(int u, int v, int w) {
        ++counter;
        E.at(counter).distance = w;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }

    inline void
    dijkstra() {
        dis.at(source) = 0;
        pq.push(Node(0, source));
        while (!pq.empty()) {
            Node temp_node = pq.top();
            pq.pop();
            int x = temp_node.position;
            // Base case
            if (vis[x]) {
                continue;
            }
            vis[x] = true;
            for (int i = head.at(x); i; i = E.at(i).next) {
                int y = E.at(i).to;
                if (dis.at(y) > dis.at(x) + E.at(i).distance) {
                    dis.at(y) = dis.at(x) + E.at(i).distance;
                    if (!vis[y]) {
                        pq.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }
}

vector<int> positions_of_cows;
vector<vector<int> > d; // d[i][j] = the shortest distance from farm i to farm j

int main(int argc, char *argv[]) {

    int n, p, c, u, v, w;
    IO::read(n, p, c);
    SSSP_Dijkstra_0::init(p, c << 1);
    positions_of_cows.resize(n);
    d.resize(p + 1, vector<int>(p + 1));
    for (auto &i : positions_of_cows) {
        IO::read(i);
    }
    for (int i = 0; i < c; ++i) {
        IO::read(u, v, w);
        SSSP_Dijkstra_0::add_edge(u, v, w);
        SSSP_Dijkstra_0::add_edge(v, u, w);
    }
    for (int i = 1; i <= p; ++i) {
        SSSP_Dijkstra_0::source = i;
        SSSP_Dijkstra_0::dijkstra();
        for (int j = 1; j <= p; ++j) {
            d.at(i).at(j) = SSSP_Dijkstra_0::dis.at(j);
        }
        SSSP_Dijkstra_0::reset();
    }
    // Enumerate the result farm from 1 to p
    int min_total_dist = numeric_limits<int>::max();
    int total_dist;
    bool have_ans;
    for (int i = 1; i <= p; ++i) {
        have_ans = true;
        total_dist = 0;
        // Make sure every cow can access farm i
        for (const auto &j : positions_of_cows) {
            if (d.at(j).at(i) == SSSP_Dijkstra_0::INF) {
                have_ans = false;
                break;
            }
            total_dist += d.at(j).at(i);
        }
        if (have_ans) {
            min_total_dist = min(min_total_dist, total_dist);
        }
    }
    IO::writeln(min_total_dist);
    return 0;
}