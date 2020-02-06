// https://open.kattis.com/problems/primepath
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAX_NODES = 5010;
constexpr int MAX_EDGES = 10010;
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


vector<int> primeList;

void sieve() {
    bool is_prime;
    for (int i = 1000; i <= 9999; ++i) {
        is_prime = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            primeList.emplace_back(i);
        }
    }
}

unordered_map<int, int> primes;

void pre() {
    int length = static_cast<int>(primeList.size());
    for (int i = 0; i < length; ++i) {
        primes[primeList.at(i)] = i + 1;
    }
}

vector<int> convert(int num) {
    vector<int> ret;
    string str = to_string(num);
    string s_copy(str);
    for (char i = '1'; i <= '9'; ++i) {
        str.at(0) = i;
        if (str != s_copy && primes.find(stoi(str)) != primes.end()) {
            ret.emplace_back(stoi(str));
        }
    }
    str = s_copy;
    for (char i = '0'; i <= '9'; ++i) {
        str.at(1) = i;
        if (str != s_copy && primes.find(stoi(str)) != primes.end()) {
            ret.emplace_back(stoi(str));
        }
    }
    str = s_copy;
    for (char i = '0'; i <= '9'; ++i) {
        str.at(2) = i;
        if (str != s_copy && primes.find(stoi(str)) != primes.end()) {
            ret.emplace_back(stoi(str));
        }
    }
    str = s_copy;
    for (char i = '0'; i <= '9'; ++i) {
        str.at(3) = i;
        if (str != s_copy && primes.find(stoi(str)) != primes.end()) {
            ret.emplace_back(stoi(str));
        }
    }
    return ret;
}

int solve(int x, int y) {

    x = primes[x];
    y = primes[y];
    s = x;
    dijkstra();
    int ret = dis.at(y);

    // reset
    for (int i = 1; i <= node_number; ++i) {
        dis[i] = INF;
    }
    vector<bool>().swap(vis);
    vis.resize(MAX_NODES);
    Q = std::priority_queue<Node>();

    return ret;
}

int main() {

    // Get all primes
    sieve();

    // Indexing all primes
    pre();

    // Get all edges for all adjacent primes
    unordered_map<string, pair<int, int> > unmap;
    for (const auto &i : primes) {
        auto p = convert(i.first);
        for (const auto &j : p) {
            int a = i.second;
            int b = primes[j];
            if (a > b) {
                swap(a, b);
            }
            unmap[to_string(a) + ' ' + to_string(b)] = make_pair(a, b);
        }
    }

    // Initialization
    node_number = static_cast<int>(primeList.size());
    for (int i = 1; i <= node_number; ++i) {
        dis[i] = INF;
    }

    for (const auto &[k, v] : unmap) {
        add_edge(v.first, v.second, 1);
        add_edge(v.second, v.first, 1);
    }

    int kase;
    int prime_a;
    int prime_b;
    int min_cost;
    scanf("%d", &kase);
    while (kase--) {
        scanf("%d %d", &prime_a, &prime_b);
        if (prime_a == prime_b) {
            printf("0\n");
            continue;
        }
        min_cost = solve(prime_a, prime_b);
        if (min_cost == 0 || min_cost == INF) {
            printf("Impossible\n");
        } else {
            printf("%d\n", min_cost);
        }
    }

    return 0;
}
