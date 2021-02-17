#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#ifdef __SIZEOF_INT128__
using int128 = __int128_t;
using uint128 = __uint128_t;

inline
string print_int128(int128 a) {
    if (!a) {
        return "0";
    }
    string s;
    while (a) {
        s = char(llabs((long long)(a % 10)) + '0') + s;
        if (a < 0 && a > -10) {
            s = '-' + s;
        }
        a /= 10;
    }
    return s;
}

inline
int128 stoint128(const string &s) {
    int128 a = 0, sgn = 1;
    for (const char &ch : s) {
        if (ch == '-') sgn *= -1;
        else a = a * 10 + sgn * (ch - '0');
    }
    return a;
}
#endif

#if defined(__SIZEOF_FLOAT128__) && defined(__linux__)
using float128 = __float128;
#endif

template<typename T>
using RBTree = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using Trie = trie<T, null_type, less<>, pat_trie_tag, trie_prefix_search_node_update>;

auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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

// DSU: Union_Find_Set
// Complexity: O (a(n)) per operation. Note: O (log n) if one of
// union-by-size or path compression is omitted
// a(n) is the inverse Ackermann function
namespace DSU {
    // father[x]: the father of x
    // Size[x]:  the size of tree/disjoint set whose ancestor is 'x'
    vector<int> father;
    vector<int> Size;
    int number_of_sets;      // the number of disjoint sets

    // iniitalization
    inline
    void init(int n) {
        // reset
        vector<int>().swap(father);
        vector<int>().swap(Size);
        // initialize: 5 is an offset just in case
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
        number_of_sets = n;
    }

    // find the ancestor of i with path compression
    inline
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }

    // merge x and y
    inline
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] >
            Size[y]) {  // Make sure the tree with less nodes combines to the tree with more nodes
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
        --number_of_sets;
    }

    // check if x and y are in the same set
    inline
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
    }

    // check the size of set where 'x' is
    inline
    int check_set_size(int x) {
        return Size[find(x)];
    }

    // check the number of disjoint sets
    inline
    int number_of_disjoint_sets() {
        return number_of_sets;
    }
}

// Modified DSU, supports move p from its set to the set contains q
// Reference: UVA11987
namespace DSU_Modified {
    vector<int> father;
    vector<int> Size;

    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(2 * n + 5);
        Size.resize(2 * n + 5);
        for (int i = 1; i <= n; ++i) {
            father.at(i) = i + n;
            father.at(i + n) = father.at(i);
            Size.at(i + n) = 1;
        }
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
    }

    // move x_ from its set to the set contains y_
    void move_to(int x_, int y_) {
        int x = find(x_);
        int y = find(y_);
        if (x == y) {
            return;
        }
        --Size[x];
        ++Size[y];
        father[x_] = y;
    }

    bool is_same_group(int x, int y) {
        return find(x) == find(y);
    }
}

/*
Catalan[0] = 1, Catalan[2] = 1
Catalan[n] = (4n-2)/(n+1) * Catalan[n-1]
Catalan[n] % p
= ( (4n-2)/(n+1) * Catalan[n-1] ) % p
= ( (4n-2) * Catalan[n-1] ) % p * inv[n+1] % p
*/
namespace Catalan {
    constexpr ll MOD = 1000000007;
    constexpr ll MAXN = 1005;
    ll inv[MAXN + 5];
    ll catalan[MAXN + 5];

    void init() {
        // Obtain inverse of MOD from 1 to MAXN
        inv[1] = 1;
        for (ll i = 2; i <= MAXN; ++i) {
            inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
        }
        // Obtain Catalan[n] % MOD
        catalan[0] = 1;
        catalan[1] = 1;
        for (ll i = 2; i <= MAXN; ++i) {
            catalan[i] =
                    ((4 * i - 2) * catalan[i - 1] % MOD * inv[i + 1] % MOD) %
                    MOD;
        }
    }

    ll query(ll n) {
        return catalan[n];
    }
}

// The collection of methods and data structures are used to obtain an MST of a
// undirected-graph using Kruskal's algorithm with Disjoint Set
// Usage: vector<Edge> A(n), .... , MST_Kruskal::kruskal(A, n);
namespace MST_Kruskal {
    struct custom_hash {
        static uint64_t splitmix64(uint64_t x) {
            // http://xorshift.di.unimi.it/splitmix64.c
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
        }

        // For a pair of integers
        size_t operator()(pair<uint64_t, uint64_t> x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x.first + FIXED_RANDOM) ^
                   (splitmix64(x.second + FIXED_RANDOM) >> 1);
        }
    };

    struct Edge {
        int u, v;
        int w;

        explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}

        Edge() = default;
    };

    inline
    vector<Edge> kruskal(const vector<Edge> &E, int number_of_nodes) {
        // initialize a DSU
        DSU::init(number_of_nodes);
        // We use a hash-map to store the minimal weight between a pair of nodes
        unordered_map<pair<int, int>, int, custom_hash> unmap;
        pair<int, int> temp_pair;
        decltype(unmap)::iterator temp_iter;
        for (const auto &[u, v, w] : E) {
            if (u > v) {
                temp_pair.first = v;
                temp_pair.second = u;
            } else {
                temp_pair.first = u;
                temp_pair.second = v;
            }
            temp_iter = unmap.find(temp_pair);
            if (temp_iter == unmap.end()) {
                unmap[temp_pair] = w;
            } else {
                temp_iter->second = min(w, temp_iter->second);
            }
        }
        vector<Edge> E_filter(unmap.size());
        int index = 0;
        for (const auto &[nodes, w] : unmap) {
            E_filter.at(index).u = nodes.first;
            E_filter.at(index).v = nodes.second;
            E_filter.at(index).w = w;
            ++index;
        }
        // sort by the edge's weight in increasing order
        sort(E_filter.begin(), E_filter.end(),
             [](const Edge &lhs, const Edge &rhs) {
                 return (lhs.w < rhs.w);
             });

        vector<Edge> minimum_spanning_tree;
        // int cost = 0;    // to calculate the total weight of the MST
        for (const auto &[u, v, w] : E_filter) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                minimum_spanning_tree.emplace_back(Edge(u, v, w));
                // cost += w;
            }
        }
        return minimum_spanning_tree;
    }
}


// The collection of methods and data structures are used to obtain an MST of a
// undirected-graph using Prim's algorithm with a priority queue optimized
// O(mlogn)
namespace MST_Prim {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int> > > adj; // adjacency list
    vector<int> dis;
    vector<bool> vis;
    int number_of_nodes;

    void reset() {
        number_of_nodes = 0;
        vector<int>().swap(dis);
        vector<bool>().swap(vis);
        vector<vector<pair<int, int> > >().swap(adj);
    }

    void init(int n) {
        number_of_nodes = n;
        dis.resize(n + 5, INF);
        adj.resize(n + 5);
        vis.resize(n + 5, false);
    }

    void add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
        adj.at(v).emplace_back(make_pair(u, w));
    }

    // Return false if the MST does not exist
    bool prim(ll &sum_of_weights) {
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        dis.at(1) = 0;  // the MST starts from node id: 1
        pq.push({dis.at(1), 1}); // add {dist.at(node_id), node_id} to pq
        int counter = 0;
        int u, w;
        while (!pq.empty() && counter < number_of_nodes) {
            w = pq.top().first;
            u = pq.top().second;
            pq.pop();
            if (vis.at(u)) {
                continue;
            }
            ++counter;
            sum_of_weights += w;
            vis.at(u) = true;
            for (const auto &[to, weight] : adj.at(u)) {
                if (dis.at(to) > weight) {
                    dis.at(to) = weight;
                    pq.push({dis.at(to), to});
                }
            }
        }
        return counter == number_of_nodes;
    }
}

// the Prim's algorithm with adjacency matrix
namespace MST_Prim_ {
    constexpr int INF = 0x3f3f3f3f;
    constexpr int MAXN = 1005;
    struct Edge {
        int w = INF;
        int to = -1;
    };
    vector<vector<int> > adj; // adjacency matrix
    bool prim(int &total_weight) {
        total_weight = 0;
        bitset<MAXN> vis;
        int n = (int)adj.size();
        vector<Edge> minE(n);
        minE.at(0).w = 0;
        for (int i = 0; i < n; ++i) {
            int v = -1;
            for (int j = 0; j < n; ++j) {
                if (!vis[j] && (v == -1 || minE.at(j).w < minE.at(v).w)) {
                    v = j;
                }
            }
            if (minE.at(v).w == INF) {
                return false;   // No MST exists
            }
            vis[v] = true;
            total_weight += minE.at(v).w;
            for (int to = 0; to < n; ++to) {
                if (adj.at(v).at(to) < minE.at(to).w) {
                    minE.at(to) = {adj.at(v).at(to), v};
                }
            }
        }
        return true;
    }
}

// Negative all weights + Kruskal for Minimum Spanning Tree
namespace MaximumSpanningTree {
    struct Edge {
        int u, v, w, neg_w;
        explicit Edge(int u, int v, int w) : u(u), v(v), w(w), neg_w(-w) {}
        Edge() = default;
    };
    inline
    vector<Edge> kruskal(vector<Edge> &E) {
        sort(E.begin(), E.end(), [](const Edge &l, const Edge &r) {
            return (l.neg_w < r.neg_w);
        });
        vector<Edge> result;
        for (const auto &e : E) {
            if (!DSU::is_same_group(e.u, e.v)) {
                DSU::merge(e.u, e.v);
                result.emplace_back(e);
            }
        }
        return result;
    }
}

// Merge two std::priority_queue efficiently (combine the heap with less nodes to the heap with more nodes)
template<typename T>
// O(n)
void merge_pq(std::priority_queue<T> &dest, std::priority_queue<T> &src) {
    if (dest.size() < src.size()) {
        swap(dest, src);
    }
    while (!src.empty()) {
        dest.push(src.top());
        src.pop();
    }
}

// An implementation of Floyd_Warshall Algorithm O(n^3) for finding
// all pairs of shortest path in a graph
namespace APSP_Floyd_Warshall {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int> > am; // adjacency matrix
    vector<vector<int> > prev; // prev[i][j] is the previous vertex of j
    int n;
    void init(int number_of_nodes, bool store_path = false) {
        // reset
        vector<vector<int> >().swap(am);
        n = number_of_nodes;
        am.resize(n, vector<int>(n, INF));
        for (int i = 0; i < n; ++i) {
            am[i][i] = 0;   // true on most cases
        }
        if (store_path) {
            prev.resize(n, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                prev[i][i] = i;   // true on most cases
            }
        }
    }
    void floyd_warshall(bool store_path = false) { // order: k, i, j
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (am[i][k] < INF && am[k][j] < INF) {
                        if (am[i][j] > am[i][k] + am[k][j]) {
                            am[i][j] = am[i][k] + am[k][j];
                            if (store_path) {
                                prev[i][j] = prev[k][j];
                            }
                        }
                    }
        // No need for graph with edges of non-negative weights
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int t = 0; t < n; ++t)
                    if (am[i][t] < INF && am[t][t] < 0 && am[t][j] < INF)
                        am[i][j] = -INF;
    }
    // Query the shortest distance from u to v
    // INF: cant reach -INF: in a negative cycle
    int dist(const int &u, const int &v) {
        return am[u][v];
    }
    // Print the path from u to v
    void print_path(const int &u, const int &v) {
        if (dist(u, v) == INF) {
            cout << "\nthe final path does not exist\n";
            return;
        }
        if (u != v) {
            print_path(u, prev[u][v]);
        }
        cout << v << ' ';
    }
    // Usage
    int main() {
        int number_of_nodes, m, u, v, s, d;
        cin >> number_of_nodes >> m;
        init(number_of_nodes, true);
        while (m--) {
            cin >> u >> v;
            am[u][v] = 1;
            prev[u][v] = u;
            am[v][u] = 1;
            prev[v][u] = v;
        }
        cin >> s >> d;
        floyd_warshall(true);
        print_path(s, d);
        return 0;
    }
}

// An implementation of Floyd Warshall Algorithm to obtain the transitive closure of a directed-graph in O(N^3)
inline vector<vector<bool> >
floyd_warshall(int n, const vector<vector<bool> > &adjacency_matrix) {
    vector<vector<bool> > reach(n, vector<bool>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // If there is an edge between i and j, that is, adjacency_matrix[i][j] is true, then we make its weight as 1 in 'reach'
            if (adjacency_matrix.at(i).at(j)) {
                reach.at(i).at(j) = true;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // If vertex k is on a path from i to j,
                // then make sure that the value of reach[i][j] is true
                reach.at(i).at(j) = reach.at(i).at(j) ||
                                    (reach.at(i).at(k) && reach.at(k).at(j));
            }
        }
    }
    return reach;
}

// An implementation of Floyd Warshall Algorithm to obtain the transitive closure of a directed-graph in O(N^3 / w) with bitset optimized
template<size_t N>
struct TransitiveClosure {
    bitset<N> reach[N];

    void floyd_warshall(int n) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                if (reach[i][k]) {
                    reach[i] |= reach[k];    // reach[i] = reach[i] | reach[k];
                }
            }
        }
    }

    void reset() {
        for (size_t i = 0; i < N; ++i) {
            reach[i].reset();
        }
    }
};

// Find minimum weight cycle in an undirected graph using Floyd
namespace MinimumWeightCycleUndirectedGraph {
    
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int> > adj_matrix;
    int number_of_nodes;

    void init(int n) {
        number_of_nodes = n;
        adj_matrix.resize(number_of_nodes + 5,
                          vector<int>(number_of_nodes + 5, INF));
        for (int i = 1; i <= number_of_nodes; ++i) {
            adj_matrix.at(i).at(i) = 0;
        }
    }

    void add_edge(int u, int v, int w) {
        adj_matrix.at(u).at(v) = w;
        adj_matrix.at(v).at(u) = w;
    }

    // Obtain the summation of weights in the minimum weight cycle,
    // return false if no such cycle exists
    bool floyd(ll &answer) {
        vector<vector<int> > dis(adj_matrix);
        answer = INF;
        for (int k = 1; k <= number_of_nodes; ++k) {
            for (int i = 1; i < k; ++i) {
                for (int j = 1; j < i; ++j) {
                    answer = min(answer, dis.at(i).at(j) * 1LL +
                                         adj_matrix.at(i).at(k) +
                                         adj_matrix.at(k).at(j));
                }
            }
            for (int i = 1; i <= number_of_nodes; ++i) {
                for (int j = 1; j <= number_of_nodes; ++j) {
                    dis.at(i).at(j) = min(dis.at(i).at(j),
                                          dis.at(i).at(k) + dis.at(k).at(j));
                }
            }
        }
        return answer < INF;
    }
}

// Find minimum weight cycle in a directed graph using Dijkstra with flag
namespace MinimumWeightCycleDirectedGraph {

    constexpr int INF = 0x3f3f3f3f;
    constexpr int MAXN = 505;   // max nodes in the graph

    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int number_of_nodes;
    bitset<MAXN> vis;

    inline void
    init(int n) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(v, w);
    }

    inline vector<int>
    dijkstra(int source) {
        vis.reset();
        bool flag = true;
        vector<int> dis(number_of_nodes + 5, INF);
        dis.at(source) = 0;
        std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            int v = pq.top().second;
            pq.pop();
            if (vis[v]) {
                continue;
            }
            vis[v] = true;
            for (const auto &[to, w] : adj.at(v)) {
                if (dis.at(to) > dis.at(v) + w) {
                    dis.at(to) = dis.at(v) + w;
                    if (!vis[to]) {
                        pq.push(make_pair(dis.at(to), to));
                    }
                }
            }
            // reset the start point
            if (flag) {
                vis[source] = false;
                dis.at(source) = INF;
                flag = false;
            }
        }
        return dis;
    }

    // Usage:
    int main() {
        int n = 400;    // suppose in this case we have 400 nodes
        init(n);
        // ... After the construction of the graph, node id starts from 1
        int minimalCycle = INF;
        for (int i = 1; i <= n; ++i) {
            auto dis = dijkstra(i);
            minimalCycle = dis.at(i);
        }
        if (minimalCycle == INF) {
            cout << "No cycle found!" << '\n';
        } else {
            cout << minimalCycle << '\n';
        }
        return 0;
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
            pq.push(Node(dis.at(source), source));
            while (!pq.empty()) {
                Node temp_node = pq.top();
                pq.pop();
                int x = temp_node.position;
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
                    d.at(u).at(v) = INF;
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

// An example that does graph traversal with BFS from 's'
namespace BFS_Example {
    constexpr int INF = 0x3f3f3f3f;
    constexpr int WEIGHT = 1;
    vector<vector<int> > adj;   // adjacency list
    int s;
    vector<int> prev; // an auxiliary container to store the path
    vector<bool> vis; // flag if any node is visited
    vector<int> dis; // dis.at(n) = the distance of shortest path from 's' to n
    void init(int number_of_nodes, bool store_path = false) {
        dis.resize(number_of_nodes + 5, INF);
        if (store_path) {
            prev.resize(number_of_nodes + 5, -1);
        }
    }

    void bfs(bool store_path = false) {
        queue<int> q;
        q.push(s);
        vis.at(s) = true;
        dis.at(s) = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const auto &to : adj.at(u)) {
                if (!vis.at(to)) {
                    q.push(to);
                    vis.at(to) = true;
                    dis.at(to) = dis.at(u) + WEIGHT;
                    if (store_path) {
                        prev.at(to) = u;
                    }
                }
            }
        }
    }

    vector<int> get_path(int destination) {
        vector<int> result;
        for (int i = destination; i != -1; i = prev.at(i)) {
            result.emplace_back(i);
        }
        reverse(result.begin(), result.end());
        return result;
    }
}

// Implementation of next_combination, duplicated values will be shown once
template<typename Itr>
inline static
bool next_combination(const Itr &first, Itr k, const Itr &last) {
    if ((first == last) || (first == k) || (last == k))
        return false;
    Itr iter1 = first, iter2 = last;
    ++iter1;
    if (last == iter1) return false;
    iter1 = k;
    --iter2;
    while (first != iter1) {
        if (*--iter1 < *iter2) {
            Itr j = k;
            while (!(*iter1 < *j)) ++j;
            std::iter_swap(iter1, j);
            ++iter1;
            ++j;
            iter2 = k;
            std::rotate(iter1, j, last);
            while (last != j) ++j, ++iter2;
            std::rotate(k, iter2, last);
            return true;
        }
    }
    std::rotate(first, k, last);
    return false;
}

void next_combination_usage() {

    // Usage: next_combination on vector<int>
    vector<int> A = {5, 1, 3, 6, 2, 4};
    sort(A.begin(), A.end()); // Must sort first

    // The length of the array in the combination
    for (int comb_size = 1; comb_size <= 3; ++comb_size) {
        do {
            for (int i = 0; i < comb_size; i++) {
                cout << A[i] << ' ';
            }
            cout << endl;
        } while (next_combination(A.begin(), A.begin() + comb_size, A.end()));
    }

    // Usage: next_combination on string
    string s = "ashdioK";
    sort(s.begin(), s.end());

    size_t comb_size = 5;
    do {
        cout << string(s.begin(), s.begin() + comb_size) << endl;
    } while (next_combination(s.begin(), s.begin() + comb_size, s.end()));
}

// Longest Common Subsequence: O(A.size()*B.size())
// assert( LCS("abcde", "bcef") == 3 );
auto LCS = [](const auto &A, const auto &B) {

    int len_A = static_cast<int>(A.size());
    int len_B = static_cast<int>(B.size());
    if (len_A == 0 || len_B == 0) {
        return 0;
    }
    vector<vector<int> > dp(len_A, vector<int>(len_B));
    for (int a = 0; a < len_A; a++) {
        for (int b = 0; b < len_B; b++) {
            if (a) dp[a][b] = max(dp[a][b], dp[a - 1][b]);
            if (b) dp[a][b] = max(dp[a][b], dp[a][b - 1]);
            if (A[a] == B[b])
                dp[a][b] = max(dp[a][b], ((a && b) ? dp[a - 1][b - 1] : 0) + 1);
        }
    }
    int ret = dp[len_A - 1][len_B - 1];
    return ret;
};

int LevenshteinDistance(const string &a, const string &b) {

    int a_length = static_cast<int>(a.size());
    int b_length = static_cast<int>(b.size());

    if (a_length == 0) return b_length;
    if (b_length == 0) return a_length;

    vector<vector<int> > dp(a_length + 1, vector<int>(b_length + 1));

    for (int i = 0; i <= a_length; ++i) {
        dp.at(i).at(0) = i;
    }
    for (int j = 0; j <= b_length; ++j) {
        dp.at(0).at(j) = j;
    }
    int cost;
    for (int i = 1; i <= a_length; ++i) {
        for (int j = 1; j <= b_length; ++j) {
            if (a.at(i - 1) == b.at(j - 1)) {
                cost = 0;
            } else {
                cost = 1;
            }
            dp.at(i).at(j) = min(
                    dp.at(i - 1).at(j) + 1,
                    min(dp.at(i).at(j - 1) + 1, dp.at(i - 1).at(j - 1) + cost)
            );
        }
    }
    return dp.at(a_length).at(b_length);
}

// Generate the prime table from 1 to MAXN
// Usage: Sieve primes from 1 to 1005: EulerPrimeSieve::init();
// Usage: Check if N is a prime: !EulerPrimeSieve::isNotPrime[N];
// Usage: Check the kth prime: EulerPrimeSieve::prime[k - 1];
//
// Reduce num_prime to the number of primes if the space is not enough.
namespace EulerPrimeSieve {

    const int MAXN = 1005;
    int prime[MAXN] = {0};
    int num_prime = 0;
    bool isNotPrime[MAXN] = {true, true};

    // Generate the prime table from 1 to MAXN
    inline static
    void init() {
        for (int i = 2; i < MAXN; i++) {
            if (!isNotPrime[i])
                prime[num_prime++] = i;
            for (int j = 0; j < num_prime && i * prime[j] < MAXN; j++) {
                isNotPrime[i * prime[j]] = true;
                if (!(i % prime[j]))
                    break;
            }
        }
    }
}

// Only check if n < MAXN is a prime
namespace EulerPrimeSieve_ {
    constexpr int MAXN = 100005;
    bitset<MAXN> isNotPrime;
    inline static
    void init() {
        isNotPrime[0] = true;
        isNotPrime[1] = true;
        for (int i = 2; i < MAXN; i++) {
            if (!isNotPrime[i]) {
                if (i > MAXN / i) {
                    continue;
                }
                for (int j = i * i; j < MAXN; j += i) {
                    isNotPrime[j] = true;
                }
            }
        }
    }
}

// Calculate a^n (n >= 0) in O(lgn) without recursion
inline static
ll quickPower(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

inline static
bool isPrime(ll n) {
    if (n <= 1) {
        return false;
    }
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Calculate (a^n) % m (n >= 0, m > 0) in O(lgn) without recursion
inline static
ll quickPower(ll a, ll n, ll m) {

    // Corner case:
    if (m == 1) {
        return 0;
    }

    // If m is a prime, then (a^n) % m = a^(n % (m - 1)) % m (Fermat's little theorem)
    if (isPrime(m)) {
        n = n % (m - 1);
    }

    a %= m;
    long long res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

// O(1) modulo mul
ll multmod(ll a, ll b, ll m) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return ((a * b - static_cast<ll>(static_cast<ld>(a) / m * b) * m) %
            m + m) % m;
}

// O(logb), better version
ll powmod(ll a, ll b, ll m) {
    if (m == 1) return 0;
    ll r;
    for (r = 1, a %= m; b; a = multmod(a, a, m), b >>= 1)
        if (b % 2) r = multmod(r, a, m);
    return r;
}

// a % p = a - floor(a / p) * p
// For a^b % p:
// If p is prime: a^b % p = a^(b % (p-1)) % p
// Otherwise: a^b % p = a^(b % phi(p) + phi(p)) % p

// A way to hash fixed length array
constexpr int MAXLENGTH = 26;

struct myHashFunc {
    std::size_t operator()(const array<int, MAXLENGTH> &A) const {
        std::size_t h = 0;
        for (const auto &i : A) {
            h ^= std::hash<int>{}(i) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

// Use gp_hash_table + custom hash function to accelerate
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

    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

gp_hash_table<int, pair<int, int>, custom_hash> my_hash_table;

// Usage:
// auto dp = MultiDimensionArray::Array<int>(5, 4, 12);
// auto dp__ = MultiDimensionArray::Array<double>(4, 5, 1, 1.0);
namespace MultiDimensionArray {
    template<typename T, typename ... Args>
    auto Array(std::size_t n, Args &&... args) {
        if constexpr (1 == sizeof ... (args)) {
            return std::vector<T>(n, args ...);
        } else {
            return std::vector(n, Array<T>(args...));
        }
    }
}

// max and min in double type with unknown number of arguments(at least 2)
constexpr double EPS = 1e-6;
inline constexpr static
int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}
template <typename T = double>
inline const static
T & doubleMax(const T &a) {
    return a;
}
template<typename T = double>
inline const static
T & doubleMax(const T &l, const T &r) {
    return sgn(l - r) >= 0 ? l : r;
}
template<typename T = double, typename ... Args>
inline const static
T & doubleMax(const T &l, const Args &... args) {
    return doubleMax(l, doubleMax(args ...));
}
template <typename T = double>
inline const static
T & doubleMin(const T &a) {
    return a;
}
template<typename T = double>
inline const static
T & doubleMin(const T &l, const T &r) {
    return sgn(l - r) >= 0 ? r : l;
}
template<typename T = double, typename ... Args>
inline const static
T & doubleMin(const T &l, const Args &... args) {
    return doubleMin(l, doubleMin(args ...));
}

// Reference:
// https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
// http://www.lomont.org/papers/2003/InvSqrt.pdf
//
// FAST INVERSE SQUARE ROOT in long double
inline static
double inv_sqrt64(double n) {
    double x2 = n * 0.5;
    double y = n;
    uint64_t i = *(uint64_t *) &y;
    i = 0x5fe6eb50c7b537a9 - (i >> 1);
    y = *(double *) &i;

    // add more Newton iterations if you wanna improve the accuracy
    y = y * (1.5 - (x2 * y * y));
    y = y * (1.5 - (x2 * y * y));
    //y = y * (1.5 - (x2 * y * y));
    //y = y * (1.5 - (x2 * y * y));
    return y;
}

// A collection of containers and procedures that implements Tarjan's strongly
// connected components algorithm. Assume that the node id starts from 1 and the
// index of a strongly connected component (SCC) also starts from 1
namespace SCC_Tarjan {

    // adjacency list of the graph
    vector<vector<int> > G;
    // number of nodes in the graph
    int number_of_nodes;
    // number of strongly connected components
    int number_of_scc;
    int current_timestamp;
    stack<int> s;   // A stack is used to store all nodes that may form a
    // strongly connected component
    vector<bool>
            vis; // vis.at(id) flags if the node id is in the stack
    vector<int> dfs_rank; // dfs_rank.at(id) numbers the nodes consecutively in
    // the order in which they are discovered by DFS
    vector<int> low_link; // low_link.at(id) represents the smallest node id of
    // any node known to be reachable from id through
    // id's DFS subtree, including id itself
    vector<int> scc;      // scc.at(id) is the index of the strongly connected
    // component that the node id belongs to
    vector<int> size_of_scc; // size_of_scc.at(id) is the size of the strongly
    // connected component whose index is id

    // reset all containers
    void reset() {
        decltype(G)().swap(G);
        stack<int>().swap(s);
        vector<bool>().swap(vis);
        vector<int>().swap(dfs_rank);
        vector<int>().swap(low_link);
        vector<int>().swap(scc);
        vector<int>().swap(size_of_scc);
    }

    // Initialize all global variables in the namespace
    void init(int n) {
        number_of_nodes = n;
        number_of_scc = 0;
        // NOTICE: starts from 1 if the node id starts from 1
        current_timestamp = 1;
        G.resize(number_of_nodes + 5);
        vis.resize(number_of_nodes + 5, false);
        dfs_rank.resize(number_of_nodes + 5, 0);
        low_link.resize(number_of_nodes + 5, 0);
        scc.resize(number_of_nodes + 5, 0);
        size_of_scc.resize(number_of_nodes + 5, 0);
    }

    void Tarjan(int u) { // u: the node id being processed
        dfs_rank.at(u) = current_timestamp;
        low_link.at(u) = current_timestamp;
        ++current_timestamp;
        s.push(u);
        vis.at(u) = true;
        for (const auto &v : G[u]) {
            if (!dfs_rank[v]) {
                Tarjan(v);
                low_link.at(u) = min(low_link.at(u), low_link.at(v));
            } else if (vis.at(v)) {
                low_link.at(u) = min(low_link.at(u), dfs_rank.at(v));
            }
        }
        if (low_link.at(u) == dfs_rank.at(u)) {
            ++number_of_scc;
            while (s.top() != u) {
                int top_id = s.top();
                // Paint top_id
                s.pop();
                scc.at(top_id) = number_of_scc;
                ++size_of_scc.at(number_of_scc);
                vis.at(top_id) = false;
            }
            // Paint u
            s.pop();
            scc.at(u) = number_of_scc;
            ++size_of_scc.at(number_of_scc);
            vis.at(u) = false;
        }
    }

    // Usage:
    int main() {
        int n, m, u, v;
        cin >> n >> m;
        init(n);
        while (m--) {
            cin >> u >> v;
            G[u].emplace_back(v);
        }
        // Run Tarjan's SCC algorithm
        for (int i = 1; i <= n; ++i) {
            // Process node i if the node i has not been visited
            if (!dfs_rank.at(i)) {
                Tarjan(i);
            }
        }
        return 0;
    }
}

// A collection of containers and procedures that implements the topological
// sort using Kahn's algorithm
namespace Toposort_Kahn {
    // adjacency list of the graph
    unordered_map<int, unordered_set<int, custom_hash>, custom_hash> G;
    int number_of_nodes;    // assume that the node id starts from 1
    // the number of incoming edges of each node, should be calculated during
    // the construction of the graph, not forget that the node id starts from 1
    vector<int> in_degree;
    vector<int> result; // store the result after toposort

    inline
    void reset() {
        G.clear();
        vector<int>().swap(in_degree);
        number_of_nodes = 0;
        vector<int>().swap(result);
    }

    inline
    void init(int n) {
        number_of_nodes = n;
        in_degree.resize(n + 5);
    }

    // Main logic of Kahn's algorithm: O(|V|+|E|), return true if it does not
    // have a cycle, otherwise false
    inline
    bool kahn() {
        queue<int> q;
        for (int i = 1; i <= number_of_nodes; ++i) {
            if (in_degree.at(i) == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.emplace_back(u);
            for (const auto &adj_v : G[u]) {
                --in_degree.at(adj_v);
                if (in_degree.at(adj_v) == 0) {
                    q.push(adj_v);
                }
            }
        }
        return (static_cast<int>(result.size()) == number_of_nodes);
    }

    // Main logic of Kahn's algorithm but the output should be lexicographically
    // smallest among all possible results after toposort: O(|V|log|V|+|E|)
    inline
    bool kahn_with_lexicographically_smallest() {
        std::priority_queue<int, vector<int>, greater<> > q;
        for (int i = 1; i <= number_of_nodes; ++i) {
            if (in_degree.at(i) == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            result.emplace_back(u);
            for (const auto &adj_v : G[u]) {
                --in_degree.at(adj_v);
                if (in_degree.at(adj_v) == 0) {
                    q.push(adj_v);
                }
            }
        }
        return (static_cast<int>(result.size()) == number_of_nodes);
    }
}

void construct_the_graph() {
    Toposort_Kahn::init(6);
    Toposort_Kahn::G[6].insert(3);
    ++Toposort_Kahn::in_degree.at(3);
    Toposort_Kahn::G[6].insert(1);
    ++Toposort_Kahn::in_degree.at(1);
    Toposort_Kahn::G[5].insert(1);
    ++Toposort_Kahn::in_degree.at(1);
    Toposort_Kahn::G[5].insert(2);
    ++Toposort_Kahn::in_degree.at(2);
    Toposort_Kahn::G[3].insert(4);
    ++Toposort_Kahn::in_degree.at(4);
    Toposort_Kahn::G[4].insert(2);
    ++Toposort_Kahn::in_degree.at(2);
}


void test_for_toposort() {
    construct_the_graph();
    assert(Toposort_Kahn::kahn());
    Toposort_Kahn::reset();
    construct_the_graph();
    assert(Toposort_Kahn::kahn_with_lexicographically_smallest());
    vector<int> result = {5, 6, 1, 3, 4, 2};
    assert(Toposort_Kahn::result == result);
}

// A collection of containers and procedures that implements the topological
// sort using DFS
namespace Toposort_Dfs {
    // adjacency list of the graph
    unordered_map<int, unordered_set<int, custom_hash>, custom_hash> G;
    vector<bool> vis;
    vector<int> result;

    inline
    void dfs(int u) {
        vis.at(u) = true;
        for (const auto &v : G[u]) {
            if (!vis.at(v)) {
                dfs(v);
            }
        }
        result.emplace_back(u);
    }

    inline
    bool init(int number_of_nodes) {
        // reset
        vector<bool>().swap(vis);
        vector<int>().swap(result);
        vis.resize(number_of_nodes, false);
        // start DFS from 0
        for (int i = 0; i < number_of_nodes; ++i) {
            if (!vis.at(i)) {
                dfs(i);
            }
        }
        reverse(result.begin(), result.end());
        return (static_cast<int>(result.size()) == number_of_nodes);
    }
}

void construct_the_graph_() {
    Toposort_Dfs::G[5].insert(2);
    Toposort_Dfs::G[5].insert(0);
    Toposort_Dfs::G[4].insert(0);
    Toposort_Dfs::G[4].insert(1);
    Toposort_Dfs::G[2].insert(3);
    Toposort_Dfs::G[3].insert(1);
}

void test_for_toposort_by_dfs() {
    construct_the_graph_();
    assert(Toposort_Dfs::init(6));
}

// The implementation of Dijkstra using adjacency list (based on the index)
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
    vector<bool> vis;
    int source;         // the node id of the source
    vector<int> prev;   // an auxiliary container to store the path

    // __gnu_pbds::priority_queue<Node, less<>, pairing_heap_tag> pq; // Alternative option if you want to use pairing heap
    std::priority_queue<Node> pq;

    inline void
    init(int n, int e, bool store_path = false) {
        number_of_nodes = n;
        number_of_edges = e;
        // initialize the containers
        E.resize(number_of_edges + 5);
        head.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
        vis.resize(number_of_nodes + 5);
        if (store_path) {
            prev.resize(number_of_nodes, -1);
        }
    }

    inline void
    reset(bool store_path = false) {
        fill(dis.begin(), dis.end(), INF);
        fill(vis.begin(), vis.end(), false);
        std::priority_queue<Node>().swap(pq);
        if (store_path) {
            fill(prev.begin(), prev.end(), -1);
        }
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
    dijkstra(bool store_path = false) {
        dis.at(source) = 0;
        pq.push(Node(dis.at(source), source));
        while (!pq.empty()) {
            Node temp_node = pq.top();
            pq.pop();
            int x = temp_node.position;
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
                        pq.push(Node(dis.at(y), y));
                    }
                }
            }
        }
    }

    inline vector<int>
    get_path(int destination) {
        vector<int> path;
        for (; destination != -1; destination = prev.at(destination)) {
            path.emplace_back(destination);
        }
        reverse(path.begin(), path.end());
        return path;
    }
}

// The implementation of Dijkstra using adjacency list
namespace SSSP_Dijkstra_1 {

    constexpr int INF = 0x3f3f3f3f; //  A weight indicates two nodes have no paths between them
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int number_of_nodes;

    vector<int> dis;    // dis.at(n) = the shortest distance from source to n
    int source;         // the node id of the source
    vector<int> prev;   // an auxiliary container to store the path
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;

    inline void
    init(int n, bool store_path = false) {
        number_of_nodes = n;
        // initialize the containers
        adj.resize(number_of_nodes + 5);
        dis.resize(number_of_nodes + 5, INF);
        if (store_path) {
            prev.resize(number_of_nodes, -1);
        }
    }

    inline void
    reset(bool store_path = false) {
        fill(dis.begin(), dis.end(), INF);
        decltype(pq)().swap(pq);
        if (store_path) {
            fill(prev.begin(), prev.end(), -1);
        }
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    inline void
    dijkstra(bool store_path = false) {
        dis.at(source) = 0;
        pq.push(make_pair(dis.at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(v)) {
                continue;
            }
            for (const auto &[to, weight] : adj.at(v)) {
                if (dis.at(to) > dis.at(v) + weight) {
                    dis.at(to) = dis.at(v) + weight;
                    if (store_path) {
                        prev.at(to) = v;
                    }
                    pq.push(make_pair(dis.at(to), to));
                }
            }
        }
    }

    inline vector<int>
    get_path(int destination) {
        vector<int> path;
        for (; destination != -1; destination = prev.at(destination)) {
            path.emplace_back(destination);
        }
        reverse(path.begin(), path.end());
        return path;
    }
}

// An implementation of Bellman-Ford's algorithm
namespace SSSP_Bellman_Ford {
    constexpr int INF = 0x3f3f3f3f;

    struct Edge {
        int u, v;
        int w;

        explicit Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    };

    // After running the algorithm, dis[t] = INF indicates there is no path
    // from source to t, dis[t] = -INF indicates if there are arbitrarily
    // short paths from source to t
    vector<int> dis;
    vector<Edge> edges;
    int number_of_nodes;
    int source;

    inline void
    reset() {
        vector<int>().swap(dis);
        vector<Edge>().swap(edges);
        number_of_nodes = 0;
        source = 0;
    }

    inline void
    init(int n, int s) {
        number_of_nodes = n;
        source = s;
        dis.resize(n + 5, INF);
        dis.at(source) = 0;
    }

    inline void
    relax(const Edge &e) {
        if (dis.at(e.v) > dis.at(e.u) + e.w) {
            dis.at(e.v) = dis.at(e.u) + e.w;
        }
    }

    // The main logic of the algorithm
    inline void
    bellman_ford() {
        for (int i = 1; i <= number_of_nodes - 1; ++i) {
            for (const auto &e : edges) {
                if (dis.at(e.u) < INF) {
                    relax(e);
                }
            }
        }
        for (int i = 1; i <= number_of_nodes - 1; ++i) {
            for (auto &e : edges) {
                if (dis.at(e.u) == -INF) {
                    dis.at(e.v) = -INF;
                } else if (dis.at(e.u) < INF &&
                           dis.at(e.v) > dis.at(e.u) + e.w) {
                    dis.at(e.v) = -INF;
                }
            }
        }
    }
}

// An implementation of Shortest Path Faster Algorithm (Bellman-Ford's algorithm with queue optimized)
// If you want to query the longest path from a single source, change INF to -INF and change the condition of relaxing from > to <
namespace SSSP_SPFA {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<int> dis;

    inline void
    reset() {
        decltype(adj)().swap(adj);
        vector<int>().swap(dis);
        number_of_nodes = 0;
        source = 0;
    }

    inline void
    init(int n, int s) {
        source = s;
        number_of_nodes = n;
        adj.resize(number_of_nodes + 5);
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    // O(mn)
    inline bool
    spfa() {

        dis.resize(number_of_nodes + 5, INF);
        dis.at(source) = 0;
        vector<int> cnt(number_of_nodes + 5);
        vector<bool> in_queue(number_of_nodes + 5, false);
        queue<int> q;
        q.push(source);
        in_queue.at(source) = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            in_queue.at(u) = false;
            for (const auto &[v, w] : adj.at(u)) {
                if (dis.at(u) + w < dis.at(v)) {
                    dis.at(v) = dis.at(u) + w;
                    if (!in_queue.at(v)) {
                        q.push(v);
                        in_queue.at(v) = true;
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

// Construction of a random antimagic-square from 1 to N * N
vector<vector<int> > antimagic_square(int n) {
    vector<vector<int> > res(n, vector<int>(n));
    int end_value = n * n - n + 1;
    int current_value = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            res.at(i).at(j) = current_value;
            ++current_value;
        }
        res.at(i).at(n - 1) = end_value;
        ++end_value;
    }
    return res;
}

// Pre-calculate the sum of factors of each number from 1 to n
vector<int> sum_of_factors(int n) {
    int length = n + 5;
    vector<int> result(length);  // result[k] = sum of factors of k
    for (int i = 1; i < length; ++i) {
        for (int j = 1; i * j < length; ++j) {
            result.at(i * j) += i;  // add the factor i
        }
    }
    return result;
}

struct SparseTable {
    vector<vector<ll> > spt;
    vector<ll> Log2;
    int n, logn;
    explicit SparseTable(int n) : n(n) {
        Log2.resize(n + 5);
        Log2.at(1) = 0;
        Log2.at(2) = 1;
        for (int i = 3; i < n + 5; ++i)
            Log2.at(i) = Log2.at(i >> 1) + 1;
        logn = floor(log2(n) + 2);
        spt.resize(n + 5, vector<ll>(logn));
    }
    void input() {
        for (int i = 1; i <= n; ++i) {
            cin >> spt.at(i).at(0);
        }
    }
    // 也可以求区间和 区间或 区间gcd 区间最小 
    // 只需修改spt.at(i).at(j - 1)和spt.at(i + (1 << (j - 1))).at(j - 1)的二元运算符即可
    void init() {
        for (int j = 1; j <= logn; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
                spt.at(i).at(j) = max(spt.at(i).at(j - 1),
                                      spt.at(i + (1 << (j - 1))).at(j - 1));
            }
        }
    }
    ll query(int l, int r) {
        int s = Log2.at(r - l + 1);
        ll ans = max(spt.at(l).at(s), spt.at(r - (1 << s) + 1).at(s));
        return ans;
    }
};

// Generate fixed-size array in compile-time
template<int N>
struct FibStruct {
    array<unsigned int, N> A;
    constexpr FibStruct() : A() {
        A.at(0) = 0;
        A.at(1) = 1;
        for (int i = 2; i < N; ++i) {
            A.at(i) = A.at(i - 1) + A.at(i - 2);
        }
    }
};
constexpr int MAXN = 30;
constexpr FibStruct<MAXN> s = FibStruct<MAXN>();
static_assert(s.A.at(MAXN - 1) == 514229);


// Twice DFS to query the diameter of a tree with different weight on each edge : O(n) 
namespace TreeDiameter {
    vector<vector<pii> > adj;
    vector<int> d;
    int c = 0;

    void dfs(int u) {
        int v, w;
        for (const auto &i : adj.at(u)) {
            v = i.first;
            w = i.second;
            if (d.at(v) == 0) {
                d.at(v) = d.at(u) + w;
                if (d.at(v) > d.at(c)) {
                    c = v;
                }
                dfs(v);
            }
        }
    }

    int diameter() {
        d.at(0) = 1;    // node id starts from 0
        dfs(0);
        fill(d.begin(), d.end(), 0);
        d.at(c) = 1;
        dfs(c);
        return d.at(c) - 1;
    }

    void init(int n) {
        adj.resize(n + 5);
        d.resize(n + 5);
    }
}
struct Interval {
    int start;
    int end;
};
int solve(int n, vector<Interval>& Tree_edge, vector<int>& Edge_value) {
    // write code here
    TreeDiameter::init(n);
    int u, v, w;
    for (int i = 0; i < n - 1; ++i) {
        u = Tree_edge.at(i).start;
        v = Tree_edge.at(i).end;
        w = Edge_value.at(i);
        TreeDiameter::adj.at(u).emplace_back(make_pair(v, w));
        TreeDiameter::adj.at(v).emplace_back(make_pair(u, w));
    }
    return TreeDiameter::diameter();
}

// Fib(2k) = Fib(k) * (2Fib(k+1) - Fib(k))
// Fib(2k+1) = Fib(k+1) * Fib(k+1) + F(k) * F(k)
template <typename T>
constexpr pair<T, T> fibInLog(int n) {
    assert(n >= 0);
    if (n == 0) {
        return {0, 1};
    }
    auto p = fibInLog<T>(n / 2);
    auto a = p.first * (2 * p.second - p.first);
    auto b = p.first * p.first + p.second * p.second;
    if (n % 2 != 0) {
        return {b, a + b};
    }
    return {a, b};
}
static_assert(fibInLog<ll>(80).first == 23416728348467685);

// Get the minimal rotation of the string
// Booth's algorithm : O(s.size())
int minimalRotation(string s) {
    s += s; // Concatenate string to it self to avoid modular arithmetic
    int length = (int)s.size();
    vector<int> f(length, -1);    // Failure function
    int k = 0;  // Least rotation of string found so far
    for (int j = 1, i; j < length; ++j) {
        char sj = s.at(j);
        i = f.at(j - k - 1);
        while (i != -1 && sj != s.at(k + i + 1)) {
            if (sj < s.at(k + i + 1)) {
                k = j - i - 1;
            }
            i = f.at(i);
        }
        if (sj != s.at(k + i + 1)) {
            if (sj < s.at(k)) {
                k = j;
            }
            f.at(j - k) = -1;
        } else {
            f.at(j - k) = i + 1;
        }
    }
    return k;
}
// Check if two strings are rotated
bool rotateString(string A, string B) {
    if (A.size() != B.size()) return false;
    rotate(A.begin(), A.begin() + minimalRotation(A), A.end());
    rotate(B.begin(), B.begin() + minimalRotation(B), B.end());
    return A == B;
}

// Stable Matching Problem
// Gale Shapley's algorithm
// O(mw)
namespace SMP {
    vector<queue<int> > m_pref;
    vector<vector<int> > w_pref;
    vector<int> engaged;    // w to m
    queue<int> free_man;
    vector<bool> is_woman_free;

    void reset() {
        vector<queue<int> >().swap(m_pref);
        vector<vector<int> >().swap(w_pref);
        vector<int>().swap(engaged);
        queue<int>().swap(free_man);
        vector<bool>().swap(is_woman_free);
    }

    void init(int n) {
        m_pref.resize(n + 1);   // man/woman's id starts from 1
        w_pref.resize(n + 1, vector<int>(n + 1));
        engaged.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            free_man.push(i);
        }
        is_woman_free.resize(n + 1, true);
    }

    void GaleShapley() {
        while (!free_man.empty()) {
            int m = free_man.front();
            if (m_pref.at(m).empty()) {
                free_man.pop();
                continue;
            }
            int w = m_pref.at(
                    m).front();   // first woman on m's list to whom m has not yet proposed
            if (is_woman_free.at(w)) {
                engaged.at(w) = m;
                m_pref.at(m).pop();
                free_man.pop();
                is_woman_free.at(w) = false;
            } else {
                int m_ = engaged.at(w);
                if (w_pref.at(w).at(m) >
                    w_pref.at(w).at(m_)) { // w prefers m to m_
                    free_man.push(m_);
                    engaged.at(w) = m;
                    free_man.pop();
                }
                m_pref.at(m).pop();
            }
        }
    }

    // n women, n men
    // men invite women
    // preferences of men to women will be given first, then the preferences of women to men
    // print the result of men to women
    int main() {
        int n, val;
        IO::read(n);
        SMP::init(n);
        // men
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                IO::read(val);
                SMP::m_pref.at(i).push(val);
            }
        }
        // women
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                IO::read(val);
                SMP::w_pref.at(i).at(val) =
                        n + 1 - j;   // notice here
            }
        }
        SMP::GaleShapley();
        // print result: m to w
        vector<pair<int, int> > result(n);
        for (int i = 1; i <= n; ++i) {
            result.at(i - 1).first = i;
            result.at(i - 1).second = SMP::engaged.at(i);
            swap(result.at(i - 1).first, result.at(i - 1).second);
        }
        sort(result.begin(), result.end());
        IO::write(result.at(0).second);
        for (int i = 1; i < n; ++i) {
            putchar_unlocked(' ');
            IO::write(result.at(i).second);
        }
        putchar_unlocked('\n');
        return 0;
    }
}

// Lucas's theorem
namespace Lucas {
    vector<ll> fac;
    // preprocess
    inline
    void init(ll p) {
        // reset
        vector<ll>().swap(fac);
        fac.emplace_back(1);
        for (ll i = 1; i <= p; ++i) {
            fac.emplace_back(fac.back() * i % p);
        }
    }
    inline static
    ll modpow(ll a, ll p, ll M) {
        if (M == 1) return 0;
        ll r;
        for (r = 1, a %= M; p; a = (a * a) % M, p >>= 1)
            if (p % 2)
                r = (r * a) % M;
        return r;
    }
    inline static
    ll C(ll n, ll m, ll p) {
        if (m > n) {
            return 0;
        }
        return fac[n] * modpow(fac[m] * fac[n - m], p - 2, p) % p;
    }
    // C(n, m) % p
    inline static
    ll Lucas(ll n, ll m, ll p) {
        if (m == 0) return 1;
        return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
    }
    // Given n, m, p such that p is a prime, calculate C(n+m,n) mod p
    int main() {
        int t;
        IO::read(t);
        ll n, m, p;
        while (t--) {
            IO::read(n, m, p);
            Lucas::init(p);
            IO::writeln(Lucas::Lucas(n + m, n, p));
        }
        return 0;
    }
}

// Lowest Common Ancestor - Tarjan's off-line algorithm
// O(n + m) for m queries
namespace LCA0 {
    vector<vector<int> > adj;
    vector<int> ancestor;
    vector<bool> vis;
    vector<vector<int> > queries;
    unordered_map<pii, int, custom_hash> unmap;
    void Tarjan(int u) {
        vis.at(u) = true;
        ancestor.at(u) = u;
        for (const auto &v : adj.at(u)) {
            if (!vis.at(v)) {
                Tarjan(v);
                DSU::merge(u, v);
                ancestor.at(DSU::find(u)) = u;
            }
        }
        for (const auto v : queries.at(u)) {
            if (vis.at(v)) {
                unmap[{u, v}] = ancestor.at(DSU::find(v));
                unmap[{v, u}] = ancestor.at(DSU::find(v));
            }
        }
    }
    void init(int n) {
        DSU::init(n);
        ancestor.resize(n + 5);
        vis.resize(n + 5, false);
        adj.resize(n + 5);
        queries.resize(n + 5);
    }
    // Usage:
    // n nodes, (n - 1) edges, the root is s, m queries,
    // for each query, u and v are given, print lca of u and v
    int main() {
        int n, m, s, u, v;
        IO::read(n, m, s);
        LCA0::init(n);
        for (int i = 1; i <= n - 1; ++i) {
            IO::read(u, v);
            LCA0::adj.at(u).emplace_back(v);
            LCA0::adj.at(v).emplace_back(u);
        }
        vector<pair<int, int> > query_list;
        for (int i = 1; i <= m; ++i) {
            IO::read(u, v);
            query_list.emplace_back(make_pair(u, v));
            LCA0::queries.at(u).emplace_back(v);
            LCA0::queries.at(v).emplace_back(u);
        }
        LCA0::Tarjan(s);    // Run Tarjan from root
        // output
        for (const auto &[u, v] : query_list) {
            IO::writeln(LCA0::unmap[{u, v}]);
        }
        return 0;
    }
}

// Obtain LCA by binary lifting, Preprocess O(nlogn), each query costs O(logn).
namespace LCA1 {
    int n, l;
    vector<vector<int>> adj;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    // Assume node id starts from 0
    void preprocess(int number_of_nodes) {
        n = number_of_nodes;
        tin.resize(n);
        tout.resize(n);
        adj.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.resize(n, vector<int>(l + 1));
    }
    void init(int root) { dfs(root, root); }
}

// Factorization of an integer using Miller Rabin Prime Check + Pollard Rho
namespace Factorization {

    constexpr int MAX_PRIME_FACTORS = 1000;
    ll factor[MAX_PRIME_FACTORS];    // Save the result of the factorization
    int tol;    // Count of prime factors

    // O(1)
    ll multmod(ll a, ll b, ll m) {
        a = (a % m + m) % m;
        b = (b % m + m) % m;
        return ((a * b - (ll) ((ld) a / m * b) * m) % m + m) % m;
    }

    // O(logb)
    ll powmod(ll a, ll b, ll m) {
        if (m == 1) return 0;
        ll r;
        for (r = 1, a %= m; b; a = multmod(a, a, m), b >>= 1)
            if (b % 2) r = multmod(r, a, m);
        return r;
    }

    // Runtime: O(logalogb)
    ll bingcd(ll a, ll b) {
        if (a < 0 || b < 0) return bingcd(abs(a), abs(b));
        if (!a || !b) return a | b;
        unsigned shift = __builtin_ctz(a | b);
        a >>= __builtin_ctz(a);
        do {
            b >>= __builtin_ctz(b);
            if (a > b) swap(a, b);
            b -= a;
        } while (b);
        return a << shift;
    }

    bool miller_rabin_subroutine(ll a, ll n, ll x, ll t) {
        ll result = powmod(a, x, n);
        ll last = result;
        for (int i = 1; i <= t; i++) {
            result = multmod(result, result, n);
            if (result == 1 && last != 1 && last != n - 1)
                return true;
            last = result;
        }
        return result != 1;
    }

    // O(Rlognlognlogn)
    bool miller_rabin(ll n) {
        constexpr int R = 5;   // rounds
        if (n < 2) return false;
        if (n == 2) return true;
        if ((n & 1) == 0) return false;
        ll x = n - 1, t = 0;
        ll a;
        while ((x & 1) == 0) {
            x >>= 1;
            ++t;
        }
        for (int i = 0; i < R; ++i) {
            a = rand() % (n - 1) + 1;
            if (miller_rabin_subroutine(a, n, x, t)) return false;
        }
        return true;
    }

    // Base on Brent's implementation, O(sqrt(p)) such that p is a small prime factor of n
    ll pollard_rho(ll n) {
        if (n % 2 == 0) return 2;
        if (n % 3 == 0) return 3;
        ll w = 0, a = 0, val = 1, g;
        ll c = rand() % (n - 1) + 1;
        for (ll k = 2;; k <<= 1, a = w, val = 1) {
            for (ll i = 1; i <= k; ++i) {
                w = (multmod(w, w, n) + c) % n;
                val = multmod(val, abs(w - a), n);
                if (! (i & 127)) {
                    g = bingcd(val, n);
                    if (g > 1) return g;
                }
            }
            g = bingcd(val, n);
            if (g > 1) return g;
        }
    }

    void find_prime_factors(ll n) {
        if (miller_rabin(n)) {
            factor[tol++] = n;
            return;
        }
        ll p = n;
        while (p >= n) p = pollard_rho(n);
        find_prime_factors(p);
        find_prime_factors(n / p);
    }
}

// Given a string s of length n, consisting only of lowercase English letters,
// find the number of different substrings in this string
int count_unique_substrings(string const &s) {

    /** This part can be done in compile-time **/
    int n = s.size();
    const int p = 31;
    const int m = 1e9 + 9;
    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }
    /*********************************/

    vector<ll> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i + 1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<ll> hs;
        for (int i = 0; i <= n - l; i++) {
            ll cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n - i - 1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}

// Given two strings - a pattern s and a text t, determine if the pattern
// appears in the text and if it does, enumerate all its occurrences in
// O(|s|+|t|) time
vector<int> rabin_karp(string const &s, string const &t) {

    /** Can be done in compile-time **/
    const int p = 31;
    const int m = 1e9 + 9;
    int S = s.size(), T = t.size();
    vector<long long> p_pow(max(S, T));
    p_pow[0] = 1;
    for (int i = 1; i < (int) p_pow.size(); i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;
    /*********************************/

    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m;
    long long h_s = 0;
    for (int i = 0; i < S; i++)
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i + S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            occurrences.push_back(i);
    }
    return occurrences;
}

// Check whether an undirected graph is bipartite
// Principle: a graph is bipartite if and only if it is two-colorable (0/1)
namespace BipartiteCheck {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int> > adj;
    vector<int> color;
    int n;
    void init(int number_of_nodes) {
        n = number_of_nodes;
        vector<int>().swap(color);
        color.resize(n + 5, INF);
    }
    // bfs from every node id, which will cover different CCs
    bool bfs() {
        queue<int> q;
        for (int s = 0; s < n; ++s) {
            if (color.at(s) == INF) {
                color.at(s) = 0;
                q.push(s);
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (const auto &v : adj.at(u)) {
                    if (color.at(v) == INF) {
                        // if color[u] = 1, then color[v] = 0
                        // if color[u] = 0, then color[v] = 1
                        color.at(v) = 1 - color.at(u);
                        q.push(v);
                    } else if (color.at(v) == color.at(u)) {
                        // Coloring conflict found, exit
                        return false;
                    }
                }
            }
        }
        return true;
    }
    // Another version that bfs from 's', which means we only consider if the CC that contains 's' is bipartite
    bool bfs(int s) {
        bool isBipartite = true;
        queue<int> q;
        color.at(s) = 0;
        q.push(s);
        while (!q.empty() && isBipartite) {
            int u = q.front();
            q.pop();
            for (const auto &v : adj.at(u)) {
                if (color.at(v) == INF) {
                    // if color[u] = 1, then color[v] = 0
                    // if color[u] = 0, then color[v] = 1
                    color.at(v) = 1 - color.at(u);
                    q.push(v);
                } else if (color.at(v) == color.at(u)) {
                    // Coloring conflict found
                    isBipartite = false;
                    break;
                }
            }
        }
        return isBipartite;
    }
}

// Find cut vertices and bridges in an undirected graph in O(m+n)
namespace CutVertexAndBridges {

    int n; // number of nodes
    vector<vector<int>> adj; // adjacency list of graph
    vector<bool> visited;
    vector<bool> isCutVertex;
    vector<pair<int, int> > bridges;
    vector<int> tin, low;
    int timer;

    void reset() {
        decltype(adj)().swap(adj);
        decltype(visited)().swap(visited);
        decltype(isCutVertex)().swap(isCutVertex);
        decltype(bridges)().swap(bridges);
        decltype(tin)().swap(tin);
        decltype(low)().swap(low);
    }

    void init(int number_of_nodes) {
        n = number_of_nodes;
        adj.resize(n + 5);
        visited.resize(n + 5, false);
        isCutVertex.resize(n + 5, false);
        tin.resize(n + 5);
        low.resize(n + 5);
    }

    void dfs(int u, int p = -1) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;
        for (const auto v : adj[u]) {
            if (v == p) continue;
            if (visited[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    if (u > v) {
                        bridges.emplace_back(v, u);
                    } else {
                        bridges.emplace_back(u, v);
                    }
                }
                if (low[v] >= tin[u] && p != -1)
                    isCutVertex[u] = true;
                ++children;
            }
        }
        if (p == -1 && children > 1)
            isCutVertex[u] = true;
    }

    void findCutVerticesAndBridges() {
        timer = 0;
        visited.resize(n, false);
        tin.resize(n, -1);
        low.resize(n, -1);
        isCutVertex.resize(n, false);
        vector<pair<int, int> >().swap(bridges);
        // Assume node id starts from 0
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) dfs(i);
        }
    }
}

namespace PrefixSum2D {
    vector<vector<ll> > pre;
    int n, m;

    void init(const vector<vector<ll> > &A) {

        if (A.empty() || A.front().empty()) return;
        n = (int) A.size();
        m = (int) A.front().size();
        decltype(pre)().swap(pre);
        pre.resize(n, vector<ll>(m));

        pre[0][0] = A[0][0];
        for (int i = 1; i < m; ++i)
            pre[0][i] = pre[0][i - 1] + A[0][i];
        for (int i = 1; i < n; ++i)
            pre[i][0] = pre[i - 1][0] + A[i - 1][0];
        for (int i = 1; i < n; ++i)
            for (int j = 1; j < m; ++j)
                pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + A[i][j];
    }

    ll rangeSum(int r0, int c0, int r1, int c1) {
        if (r0 == 0 && c0 == 0) return pre[r1][c1];
        else if (r0 == 0 && c0 != 0) return pre[r1][c1] - pre[r1][c0 - 1];
        else if (r0 != 0 && c0 == 0) return pre[r1][c1] - pre[r0 - 1][c1];
        return pre[r1][c1] - pre[r0 - 1][c1] - pre[r1][c0 - 1] + pre[r0 - 1][c0 - 1];
    }
}

// Prefix sum of edges' weights on a rooted tree
namespace PrefixSumTree0 {
    vector<ll> pre;
    vector<bool> vis;
    vector<vector<pair<int, ll> > > adj;
    void init(int n) {
        adj.resize(n);
        pre.resize(n);
        vis.resize(n, false);
    }
    void dfs(int u, ll currSum) {
        for (const auto &[v, w] : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                pre[v] = currSum + w;
                dfs(v, pre[v]);
            }
        }
    }
    // Query the distance from u to v:
    // ll dist(int u, int v) { return pre[u] + pre[v] - 2*pre[lca(u, v)]; }
    // Usage
    int main() {
        int n, root, m, u, v, q; ll w;
        cin >> n >> root >> m;
        init(n);
        while (m--) {
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        vis[root] = true;
        dfs(root, 0);
        while (q--) {
            cin >> u >> v;
            // cout << dist(u, v) << '\n';
        }
        return 0;
    }
}

// Prefix sum of nodes' weights on a rooted tree
namespace PrefixSumTree1 {
    vector<ll> pre;
    vector<bool> vis;
    vector<vector<int> > adj;
    vector<ll> weight;
    vector<int> father;

    void init(int n) {
        pre.resize(n);
        vis.resize(n, false);
        adj.resize(n);
        weight.resize(n);
        father.resize(n);
    }

    void dfs(int u, ll currSum) {
        pre[u] = currSum + weight[u];
        for (const auto &v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dfs(v, pre[u]);
                father[v] = u;
            }
        }
    }

    // Query the distance from u to v:
//    ll dist(int u, int v) { 
//        int Lca = lca(u, v);
//        // Case 1: lca is root
//        if (father[Lca] == -1) {
//            return pre[u] + pre[v] - pre[Lca];
//        }
//        // Case 2: otherwise
//        return pre[u] + pre[v] - pre[Lca] - pre[father[Lca]];
//    }
    // Usage
    int main() {
        int n, root, m, u, v, q;
        cin >> n >> root >> m;
        init(n);
        for (auto &i : weight) cin >> i;
        while (m--) {
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        vis[root] = true;
        father[root] = -1;
        dfs(root, 0);
        while (q--) {
            cin >> u >> v;
            // cout << dist(u, v) << '\n';
        }
        return 0;
    }
}

int main() {

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    return 0;
}

// How to check if and only if an edge E is on the shortest 
// path from u to v in an undirected graph:
//
// 1. Get dis1.at(i) = the shortest path from u to i by Dij
// 2. Get dis2.at(i) = the shortest path from v to i by Dij
// 3. For each edge E:(a, b) -> w,
// dis1.at(a) + w + dis2.at(b) = shortest path from u to v
// OR
// dis2.at(a) + w + dis1.at(b) = shortest path from u to v
// <=> the E:(a, b) -> w is on the shortest path from u to v
