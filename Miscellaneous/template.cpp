#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
using ll = long long;

template <typename T>
using RBTree = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using Trie = trie<T, null_type, less<>, pat_trie_tag, trie_prefix_search_node_update>;

// DSU: Union_Find_Set
// Complexity: O (a(n)) per operation. Note: O (log n) if one of
// union-by-size or path compression is omitted
// a(n) is reverse Ackermann function
namespace DSU {
    // father[x]: the father of x
    // Size[x]:  the rank, rank is the size of the tree whose root is x
    vector<int> father;
    vector<int> Size;
    // iniitalization
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
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    // merge x and y
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
    // check if x and y are in the same Set
    bool is_same_group(int i, int j) {
        return find(i) == find(j);
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

// The collection of methods and data structures for Kruskal's algorithm
// Usage: vector<Edge> A(n), .... , Kruskal::init(A, n);
namespace Kruskal {
    struct Edge {
        int u, v;
        int w;
        Edge(int u, int v, int w) : u(u), v(v), w(w) {}
        Edge() = default;
    };
    bool cmp0(const Edge &lhs, const Edge &rhs) {
        return (lhs.w < rhs.w);
    }
    struct my_hash_func {
        size_t operator ()(const pair<int, int> &obj) const {
            return hash<int>()(obj.first) ^ hash<int>()(obj.second);
        }
    };
    vector<Edge> init(const vector<Edge> &E, int number_of_nodes) {
        // init a DSU
        DSU::init(number_of_nodes);
        // We use a hashmap to store the minimal weight between a pair of nodes
        unordered_map<pair<int, int>, int, my_hash_func> temp_unmap;
        pair<int, int> temp_pair;
        for (const auto &[u, v, w] : E) {
            if (u > v) {
                temp_pair.first = v;
                temp_pair.second = u;
            } else {
                temp_pair.first = u;
                temp_pair.second = v;
            }
            if (temp_unmap.find(temp_pair) == temp_unmap.end()) {
                temp_unmap[temp_pair] = w;
            } else {
                temp_unmap[temp_pair] = min(w, temp_unmap[temp_pair]);
            }
        }
        vector<Edge> E_filter(temp_unmap.size());
        int index = 0;
        for (const auto &[nodes, w] : temp_unmap) {
            E_filter.at(index).u = nodes.first;
            E_filter.at(index).v = nodes.second;
            E_filter.at(index).w = w;
            ++index;
        }
        sort(E_filter.begin(), E_filter.end(), cmp0);
        vector<Edge> MST;
        // int cost = 0;
        for (const auto &[u, v, w] : E_filter) {
            if (!DSU::is_same_group(u, v)) {
                DSU::merge(u, v);
                MST.emplace_back(Edge(u, v, w));
                // cost += w;
            }
        }
        return MST;
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
// Floyd_Warshall Algorithm O(n^3)
namespace Floyd {
    constexpr int INF = 0x3f3f3f3f;
    constexpr int MAXN = 155;
    int d[MAXN][MAXN];
    void init(int n) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = INF;
            }
        }
        for (int i = 0; i < n; ++i) {
            d[i][i] = 0;
        }
    }
    void process(int n) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (d[i][k] < INF && d[k][j] < INF) {
                        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int t = 0; t < n; ++t) {
                    if (d[i][t] < INF && d[t][t] < 0 && d[t][j] < INF)
                        d[i][j] = -INF;
                }
            }
        }
    }
    int query(int u, int v) {
        return d[u][v];  // INF: cant reach -INF: in a negative cycle
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
namespace SCC {

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
        current_timestamp = 0;
        // Give some flexibility of size of our containers since
        // the node id/SCC id may not strictly start from 1, since the
        // number of nodes in the assignment will not exceed 10001,
        // the space complexity will not be a bottle-neck
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
namespace Toposort {
    // adjacency list of the graph
    unordered_map<int, unordered_set<int, custom_hash>, custom_hash> G;
    int number_of_nodes;    // assume that the node id starts from 1
    // the number of incoming edges of each node, should be calculated during
    // the construction of the graph, not forget that the node id starts from 1
    vector<int> in_degree;
    vector<int> result; // store the result after toposort
    void reset() {
        G.clear();
        vector<int>().swap(in_degree);
        number_of_nodes = 0;
        vector<int>().swap(result);
    }

    void init(int n) {
        number_of_nodes = n;
        in_degree.resize(n + 5);
    }

    // Main logic of Kahn's algorithm: O(|V|+|E|), return true if it does not
    // have a cycle, otherwise false
    bool Kahn() {
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
    bool Kahn_with_lexicographically_smallest() {
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
    Toposort::init(6);
    Toposort::G[6].insert(3);   ++Toposort::in_degree.at(3);
    Toposort::G[6].insert(1);   ++Toposort::in_degree.at(1);
    Toposort::G[5].insert(1);   ++Toposort::in_degree.at(1);
    Toposort::G[5].insert(2);   ++Toposort::in_degree.at(2);
    Toposort::G[3].insert(4);   ++Toposort::in_degree.at(4);
    Toposort::G[4].insert(2);   ++Toposort::in_degree.at(2);
}


void test_for_toposort() {
    construct_the_graph();
    assert(Toposort::Kahn());
    Toposort::reset();
    construct_the_graph();
    assert(Toposort::Kahn_with_lexicographically_smallest());
    vector<int> result = {5,6,1,3,4,2};
    assert(Toposort::result == result);
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

    //freopen("/home/ugd/haohu.shen/cpsc/in", "r", stdin);

    return 0;
}
