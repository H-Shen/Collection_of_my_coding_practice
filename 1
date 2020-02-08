// https://open.kattis.com/problems/spiral
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
template <typename T>
using RBTree = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using Trie = trie<T, null_type, less<>, pat_trie_tag, trie_prefix_search_node_update>;

// Usage: int a, b, c; read<int>(a, b, c);
template <typename T>
inline
void read(T& t) {
    int n = 0; int c = getchar(); t = 0;
    while (!isdigit(c)) n |= c == '-', c = getchar();
    while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
    if (n) t = -t;
}
template <typename T, typename... Args>
inline
void read(T& t, Args&... args) {
    read(t); read(args...);
}
// Usage: int a = 1231; writeln(a);
template <typename T>
inline void write(T x) {
    if (x < 0) x = -x, putchar('-');
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void writeln(T x) {
    write(x);
    puts("");
}

constexpr int MAXN = 121;
vector<vector<int> > A;

namespace Sieve_Primes {

    const int N = 14645;
    int* prime = nullptr; // int prime[N];
    int* isNotPrime = nullptr;  // int isNotPrime[N] = {1, 1};
    int num_prime = 0;

    inline static
    void init() {
        // allocate
        prime = new int[N]();
        isNotPrime = new int[N]();
        isNotPrime[0] = 1;
        isNotPrime[1] = 1;
        // calculate
        for (int i = 2; i < N; i++) {
            if (!isNotPrime[i]) {
                prime[num_prime++] = i;
            }
            for (int j = 0; j < num_prime && i * prime[j] < N; j++) {
                isNotPrime[i * prime[j]] = 1;
                if (!(i % prime[j])) {
                    break;
                }
            }
        }
        // de-allocate
        delete[] prime;
        prime = nullptr;
    }
    inline static
    bool is_prime(int n) {
        return !isNotPrime[n];
    }
}

namespace SSSP {

    constexpr int MAX_NODES = 15000;
    constexpr int MAX_EDGES = 60000;
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

    struct Node {
        int distance;
        int position;

        explicit Node(int distance, int pos) : distance(distance), position(pos) {}

        bool operator<(const Node &x) const {
            return (x.distance < distance);
        }
    };

    vector<Edge> E(MAX_EDGES);
    vector<int> head(MAX_NODES);
    int counter;
    int node_number;

    vector<int> dis(MAX_NODES);
    vector<bool> vis(MAX_NODES);
    int s;

    inline static
    void add_edge(int u, int v, int d) {
        ++counter;
        E.at(counter).distance = d;
        E.at(counter).to = v;
        E.at(counter).next = head.at(u);
        head.at(u) = counter;
    }

    std::priority_queue<Node> Q;

    inline static
    void dijkstra() {
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

    unordered_map<int, int> element2index;
    inline void initialize() {

        // update element2index
        int counter = 1;    // start from 1
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                element2index[A.at(i).at(j)] = counter;
                ++counter;
            }
        }

        // obtain all edges
        int temp, current;
        for (int i = 0; i < MAXN; ++i) {
            for (int j = 0; j < MAXN; ++j) {
                current = A.at(i).at(j);
                try {
                    temp = A.at(i + 1).at(j);
                    if (!Sieve_Primes::is_prime(temp)) {
                        add_edge(element2index[current], element2index[temp], 1);
                    }
                } catch (...) {}
                try {
                    temp = A.at(i - 1).at(j);
                    if (!Sieve_Primes::is_prime(temp)) {
                        add_edge(element2index[current], element2index[temp], 1);
                    }
                } catch (...) {}
                try {
                    temp = A.at(i).at(j + 1);
                    if (!Sieve_Primes::is_prime(temp)) {
                        add_edge(element2index[current], element2index[temp], 1);
                    }
                } catch (...) {}
                try {
                    temp = A.at(i).at(j - 1);
                    if (!Sieve_Primes::is_prime(temp)) {
                        add_edge(element2index[current], element2index[temp], 1);
                    }
                } catch (...) {}
            }
        }

        // Other settings
        node_number = MAX_NODES;
        for (int i = 1; i < node_number; ++i) {
            dis.at(i) = INF;
        }
    }

    inline static
    int query(int x, int y) {

        x = element2index[x];
        y = element2index[y];
        s = x;
        dijkstra();
        int ret = dis.at(y);

        // reset
        for (int i = 1; i < node_number; ++i) {
            dis.at(i) = INF;
        }
        vector<bool>().swap(vis);
        vis.resize(MAX_NODES);
        Q = std::priority_queue<Node>();

        if (ret == 0 || ret == INF) {
            return -1;
        }
        return ret;
    }
}

void create_matrix() {
    int n = MAXN;  // n is odd
    A.resize(n, vector<int>(n, -1));
    int m = (n + 1) / 2;
    // left
    int max_element = (2*m - 1)*(2*m - 1);
    int counter = max_element;
    for (int j = n - 1; j >= 0; --j) {
        A.at(n - 1).at(j) = counter;
        --counter;
    }
    // up
    for (int i = n - 2; i >= 0; --i) {
        A.at(i).at(0) = counter;
        --counter;
    }
    // right
    for (int j = 1; j < n; ++j) {
        A.at(0).at(j) = counter;
        --counter;
    }
    // down
    for (int i = 1; i < n - 1; ++i) {
        A.at(i).at(n - 1) = counter;
        --counter;
    }
    int current_i = n - 2;
    int current_j = n - 1;
    while (true) {
        // left
        --current_j;
        while (A.at(current_i).at(current_j) == -1) {
            A.at(current_i).at(current_j) = counter;
            --counter;
            --current_j;
        }
        ++current_j;
        if (counter == 0) {
            break;
        }
        // up
        --current_i;
        while (A.at(current_i).at(current_j) == -1) {
            A.at(current_i).at(current_j) = counter;
            --counter;
            --current_i;
        }
        ++current_i;
        if (counter == 0) {
            break;
        }
        // right
        ++current_j;
        while (A.at(current_i).at(current_j) == -1) {
            A.at(current_i).at(current_j) = counter;
            --counter;
            ++current_j;
        }
        --current_j;
        if (counter == 0) {
            break;
        }
        // down
        ++current_i;
        while (A.at(current_i).at(current_j) == -1) {
            A.at(current_i).at(current_j) = counter;
            --counter;
            ++current_i;
        }
        --current_i;
        if (counter == 0) {
            break;
        }
    }
}


int main() {

    Sieve_Primes::init();
    create_matrix();
    SSSP::initialize();

    int kase = 1;
    int i, j, min_dist;
    while(~scanf("%d %d", &i, &j)) {
        printf("Case %d: ", kase);
        ++kase;
        if (i == j) {
            printf("0\n");
            continue;
        }
        min_dist = SSSP::query(i, j);
        if (min_dist == -1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", min_dist);
        }
    }
    return 0;
}
