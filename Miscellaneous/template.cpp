#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;

template <typename T>
using RBTree = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using Trie = trie<T, null_type, less<>, pat_trie_tag, trie_prefix_search_node_update>;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
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
    // Size[x]:  the rank, rank is the size of the tree whose root is x
    vector<int> father;
    vector<int> Size;
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
        x = find(x); y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {  // Make sure the tree with less nodes combines to the tree with more nodes
            swap(x, y);
        }
        father[x] = y;
        Size[y] += Size[x];
    }
    // check if x and y are in the same set
    inline
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
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
    constexpr ll MAXN =1005;
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
            catalan[i] = ((4*i-2)*catalan[i-1] % MOD * inv[i+1] % MOD) % MOD;
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

// Merge two std::priority_queue efficiently (combine the heap with less nodes to the heap with more nodes)
template<typename T>  // O(n)
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

    vector<vector<int> > adj_matrix; // adjacency matrix
    int number_of_nodes;

    inline
    void init(int n) {
        // reset
        vector<vector<int> >().swap(adj_matrix);
        number_of_nodes = n;
        adj_matrix.resize(number_of_nodes, vector<int>(number_of_nodes, INF));
        for (int i = 0; i < number_of_nodes; ++i) {
            adj_matrix.at(i).at(i) = 0;
        }
    }

    inline
    void floyd_warshall() {
        for (int k = 0; k < number_of_nodes; ++k) {
            for (int i = 0; i < number_of_nodes; ++i) {
                for (int j = 0; j < number_of_nodes; ++j) {
                    if (adj_matrix.at(i).at(k) < INF &&
                        adj_matrix.at(k).at(j) < INF) {
                        adj_matrix.at(i).at(j) = min(adj_matrix.at(i).at(j),
                                                     adj_matrix.at(i).at(k) +
                                                     adj_matrix.at(k).at(j));
                    }
                }
            }
        }
        for (int i = 0; i < number_of_nodes; ++i) {
            for (int j = 0; j < number_of_nodes; ++j) {
                for (int t = 0; t < number_of_nodes; ++t) {
                    if (adj_matrix.at(i).at(t) < INF &&
                        adj_matrix.at(t).at(t) < 0 &&
                        adj_matrix.at(t).at(j) < INF) {
                        adj_matrix.at(i).at(j) = -INF;
                    }
                }
            }
        }
    }

    // Query the shortest distance from node u to node v
    inline
    int dist(const int &u, const int &v) {
        return adj_matrix.at(u).at(
                v);  // INF: cant reach -INF: in a negative cycle
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
        for (int i = 0; i < N; ++i) {
            reach[i].reset();
        }
    }
};

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
auto LCS = [](const auto & A, const auto & B) {

    int len_A = static_cast<int>(A.size());
    int len_B = static_cast<int>(B.size());
    if (len_A == 0 || len_B == 0) {
        return 0;
    }
    vector<vector<int> > dp(len_A, vector<int>(len_B));
    for (int a = 0; a < len_A; a++) {
        for (int b = 0; b < len_B; b++) {
            if (a) dp[a][b] = max(dp[a][b], dp[a-1][b]);
            if (b) dp[a][b] = max(dp[a][b], dp[a][b-1]);
            if (A[a] == B[b])
                dp[a][b] = max(dp[a][b], ((a && b) ? dp[a-1][b-1] : 0) + 1);
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

// matrixMul % m: O(n^3)
template<typename T>
inline static
std::vector<std::vector<T> >
matrixMul(const std::vector<std::vector<T> > &A,
          const std::vector<std::vector<T> > &B, const T &mod) {

    // Case 1:
    if (A.empty() || B.empty() || A.at(0).empty() || B.at(0).empty() ||
        A.at(0).size() != B.size()) {
        throw std::out_of_range("");
    }

    // Case 2:
    std::vector<std::vector<T> > C(A.size(), std::vector<T>(B.at(0).size()));
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != B.at(0).size(); ++j) {
            for (size_t k = 0; k != A.at(0).size(); ++k) {
                C.at(i).at(j) =
                        C.at(i).at(j) + A.at(i).at(k) * B.at(k).at(j) % mod;
            }
            C.at(i).at(j) %= mod;
        }
    }
    return C;
}

// Quick power of matrix with modulo: O(n^3 * log(power))
template<typename T>
inline static
std::vector<std::vector<T> >
quickMatrixPower(std::vector<std::vector<T> > A, T power, T m) {

    // Case 1:
    if (A.empty() || A.front().empty() || A.size() != A.front().size()) {
        throw std::out_of_range("");
    }

    // Case 2:
    // A = A % m
    for (size_t i = 0; i != A.size(); ++i) {
        for (size_t j = 0; j != A.at(0).size(); ++j) {
            A.at(i).at(j) %= m;
        }
    }
    // Initialize res as an identity matrix;
    std::vector<std::vector<T> > res(A.size(), std::vector<T>(A.size()));
    T initialValue{1};
    for (size_t i = 0; i != res.size(); ++i) {
        res.at(i).at(i) = initialValue;
    }
    // log(n)
    while (power > 0) {
        if (power & 1) {
            res = matrixMul(res, A, m);
        }
        A = matrixMul(A, A, m);
        power >>= 1;
    }
    return res;
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

// A better version
inline static
ll modpow(ll a, ll p, ll M) {
    if (M == 1) return 0;
    ll r;
    for (r = 1, a %= M; p; a = (a * a) % M, p >>= 1) if (p % 2) r = (r * a) % M;
    return r;
}

// O(1) modulo mul
inline static
ll modmul(ll a, ll b, ll m) {
    a = (a % m + m) % m;
    b = (b % m + m) % m;
    return ((a * b - static_cast<ll>(static_cast<long double>(a) / m * b) * m) %
            m + m) % m;
}

// a % p = a - floor(a / p) * p
// For a^b % p:
// If p is prime: a^b % p = a^(b % (p-1)) % p
// Otherwise: a^b % p = a^(b % phi(p) + phi(p)) % p

// A way to hash fixed length array
constexpr int MAXLENGTH = 26;
struct myHashFunc {
    std::size_t operator()(const array<int, MAXLENGTH>& A) const {
        std::size_t h = 0;
        for (const auto &i : A) {
            h ^= std::hash<int>{}(i)  + 0x9e3779b9 + (h << 6) + (h >> 2);
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
    template <typename T, typename ... Args>
    auto Array(std::size_t n, Args && ... args) {
        if constexpr (1 == sizeof ... (args)) {
            return std::vector<T>(n, args ...);
        }
        else {
            return std::vector(n, Array<T>(args...));
        }
    }
}

// max and min with unknown number of arguments(at least 2)
// Usage: cout << my_max(1, 1, 2, 3, 1);
template<typename T>
inline constexpr static
T my_max(const T& x, const T& y) {
    return (x > y) ? x : y;
}
template<typename T, typename ... Args>
inline constexpr static
T my_max(const T& x, const Args& ... args) {
    return my_max(x, my_max(args...));
}
template<typename T>
inline constexpr static
T my_min(const T& x, const T& y) {
    return (x < y) ? x : y;
}
template<typename T, typename ... Args>
inline constexpr static
T my_min(const T& x, const Args& ... args) {
    return my_min(x, my_min(args...));
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
    uint64_t i = *(uint64_t *)&y;
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
// index of a strongly connected component (SCC) also starts from 1 Reference:
// https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm#The_algorithm_in_pseudocode
namespace SCC_Tarjan {

    // adjacency list of the graph
    unordered_map<int, unordered_set<int> > G;

    int number_of_nodes; // number of nodes in the graph
    int number_of_scc;            // number of strongly connected components
    int current_timestamp;     // current timestamp
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
    inline
    void reset() {
        G.clear();
        stack<int>().swap(s);
        vector<bool>().swap(vis);
        vector<int>().swap(dfs_rank);
        vector<int>().swap(low_link);
        vector<int>().swap(scc);
        vector<int>().swap(size_of_scc);
    }

    // Initialize all global variables in the namespace
    inline
    void init(int n) {
        number_of_nodes = n;
        number_of_scc = 0;
        current_timestamp = 1;  // NOTICE: starts from 1 if the node id starts from 1
        // Give some flexibility of size of our containers since
        // the node id/SCC id may not strictly start from 1
        int offset = 5;
        vis.resize(number_of_nodes + offset, false);
        dfs_rank.resize(number_of_nodes + offset, 0);
        low_link.resize(number_of_nodes + offset, 0);
        scc.resize(number_of_nodes + offset, 0);
        size_of_scc.resize(number_of_nodes + offset, 0);
    }

    inline
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
    Toposort_Kahn::G[6].insert(3);   ++Toposort_Kahn::in_degree.at(3);
    Toposort_Kahn::G[6].insert(1);   ++Toposort_Kahn::in_degree.at(1);
    Toposort_Kahn::G[5].insert(1);   ++Toposort_Kahn::in_degree.at(1);
    Toposort_Kahn::G[5].insert(2);   ++Toposort_Kahn::in_degree.at(2);
    Toposort_Kahn::G[3].insert(4);   ++Toposort_Kahn::in_degree.at(4);
    Toposort_Kahn::G[4].insert(2);   ++Toposort_Kahn::in_degree.at(2);
}


void test_for_toposort() {
    construct_the_graph();
    assert(Toposort_Kahn::kahn());
    Toposort_Kahn::reset();
    construct_the_graph();
    assert(Toposort_Kahn::kahn_with_lexicographically_smallest());
    vector<int> result = {5,6,1,3,4,2};
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
        pq = std::priority_queue<Node>();
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
        pq.push(Node(0, source));
        while (!pq.empty()) {
            Node temp_node = pq.top();
            pq.pop();
            int x = temp_node.position;
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
        pq = decltype(pq)();
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
        pq.push(make_pair(0, source));
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
                } else if (dis.at(e.u) < INF && dis.at(e.v) > dis.at(e.u) + e.w) {
                    dis.at(e.v) = -INF;
                }
            }
        }
    }
}

// An implementation of Shortest Path Faster Algorithm (Bellman-Ford's algorithm with queue optimized)
namespace SSSP_SPFA {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<int> dis;

    inline void
    reset() {
        vector<vector<pair<int, int> > >().swap(adj);
        vector<int>().swap(dis);
        number_of_nodes = 0;
        source = 0;
    }

    inline void
    init(int n, int s) {
        vector<vector<pair<int, int> > >().swap(adj);
        source = s;
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5, INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    inline void
    add_edge(int u, int v, int w) {
        adj.at(u).emplace_back(make_pair(v, w));
    }

    // O(mn)
    inline bool
    spfa() {
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
                if (dis.at(v) > dis.at(u) + w) {
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

// An implementation of Shortest Path Faster Algorithm (dfs optimized)
namespace SSSP_SPFA_DFS {
    constexpr int INF = 0x3f3f3f3f;
    constexpr int MAX_NODES = 2005;
    vector<vector<pair<int, int> > > adj; // The adjacency list of the graph
    int source;
    int number_of_nodes;
    vector<int> dis;
    bitset<MAX_NODES> vis;

    inline void
    reset() {
        vector<vector<pair<int, int> > >().swap(adj);
        vector<int>().swap(dis);
        number_of_nodes = 0;
        source = 0;
        vis.reset();
    }

    inline void
    init(int n, int s) {
        vector<vector<pair<int, int> > >().swap(adj);
        source = s;
        number_of_nodes = n;
        dis.resize(number_of_nodes + 5, INF);
        adj.resize(number_of_nodes + 5);
        dis.at(source) = 0;
    }

    inline bool
    spfa_dfs(int u) {
        vis[u] = true;
        for (const auto &[v, w] : adj.at(u)) {
            if (dis.at(v) > dis.at(u) + w) {
                dis.at(v) = dis.at(u) + w;
                if (vis[v] || spfa_dfs(v)) {
                    return true; // return true if a negative cycle exists
                }
            }
        }
        vis[u] = false;
        return false;
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

int main() {

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    return 0;
}
