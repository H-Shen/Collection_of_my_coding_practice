// An example of Johnson's algorithm 
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int NON_EXIST = 1000000000;

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

namespace APSP_Johnson {

    constexpr int INF = 0x3f3f3f3f;
    constexpr int MAX_NODES = 3005;
    
    struct Edge {
        int u, v;
        int w;
        explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };

    // Data members of the graph G
    int number_of_nodes;
    vector<Edge> edges;
    int source;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph

    // An implementation of Shortest Path Faster Algorithm (Bellman-Ford's algorithm with queue optimized)
    namespace SSSP_SPFA {
        
        bitset<MAX_NODES> in_queue;
        vector<int> dis;

        // O(mn)
        inline bool
        spfa() {
            vector<int> cnt(number_of_nodes + 5);
            queue<int> q;
            q.push(source);
            in_queue[source] = true;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                in_queue[u] = false;
                for (const auto &[v, w] : adj.at(u)) {
                    if (dis.at(v) > dis.at(u) + w) {
                        dis.at(v) = dis.at(u) + w;
                        if (!in_queue[v]) {
                            q.push(v);
                            in_queue[v] = true;
                            ++cnt.at(v);
                            if (cnt.at(v) > number_of_nodes) {
                                return false;   // a negative cycle exists
                            }
                        }
                    }
                }
            }
            return true;
        }
    }

    // The implementation of Dijkstra using adjacency list (based on the index)
    namespace SSSP_Dijkstra {
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
            pq = std::priority_queue<Node>();
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

    vector<vector<int> > d; // d[i][j] indicates the distance of shortest path from i to j after running Johnson's algorithm
    inline bool
    johnson() {
        // construct the graph G_prime
        source = 0;
        for (int v = 1; v <= number_of_nodes; ++v) {
            edges.emplace_back(Edge(source, v, 0));
        }
        // convert edges of G_prime into 'adj'
        adj.resize(number_of_nodes + 5);
        for (const auto &e : edges) {
            adj.at(e.u).emplace_back(make_pair(e.v, e.w));
        }
        // init spfa
        SSSP_SPFA::dis.resize(number_of_nodes + 5, INF);
        SSSP_SPFA::dis.at(source) = 0;
        // run spfa
        if (!SSSP_SPFA::spfa()) {
            // graph G contains a negative cycle
            return false;
        }
        // update all edges in G
        for (auto &e : edges) {
            e.w += SSSP_SPFA::dis.at(e.u) - SSSP_SPFA::dis.at(e.v);
        }
        // initialize 'd'
        d.resize(number_of_nodes + 5,
                 vector<int>(number_of_nodes + 5));
        // initialize Dijkstra
        SSSP_Dijkstra::init(number_of_nodes, static_cast<int>(edges.size()));
        // add edges
        for (const auto &e : edges) {
            SSSP_Dijkstra::add_edge(e.u, e.v, e.w);
        }
        for (int u = 1; u <= number_of_nodes; ++u) {
            // run Dijkstra from each node
            SSSP_Dijkstra::source = u;
            SSSP_Dijkstra::dijkstra();
            for (int v = 1; v <= number_of_nodes; ++v) {
                if (SSSP_Dijkstra::dis.at(v) == INF) {
                    d.at(u).at(v) = NON_EXIST;
                } else {
                    d.at(u).at(v) =
                            SSSP_Dijkstra::dis.at(v) + SSSP_SPFA::dis.at(v) -
                            SSSP_SPFA::dis.at(u);
                }
            }
            // reset dijkstra
            SSSP_Dijkstra::reset();
        }
        return true;
    }
}


int main(int argc, char *argv[]) {

    int n, m, u, v, w;
    IO::read(n, m);

    // Construct the graph G
    APSP_Johnson::number_of_nodes = n;
    for (int i = 0; i < m; ++i) {
        IO::read(u, v, w);
        APSP_Johnson::edges.emplace_back(APSP_Johnson::Edge(u, v, w));
    }

    // Run Johnson
    if (!APSP_Johnson::johnson()) {
        IO::writeln(-1);
    } else {
        ll sum;
        for (int i = 1; i <= n; ++i) {
            sum = 0;
            for (int j = 1; j <= n; ++j) {
                sum += static_cast<ll>(APSP_Johnson::d.at(i).at(j)) * j;
            }
            IO::writeln(sum);
        }
    }
    return 0;
}
