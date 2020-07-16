// https://open.kattis.com/problems/runningmom
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAX_CITIES = 10005;
constexpr int MAXN = 40;
char city_a[MAXN];
char city_b[MAXN];
char city[MAXN];

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
};

// adjacency list of the graph
unordered_map<int, unordered_set<int, custom_hash>, custom_hash> G;

namespace SCC {

    int number_of_nodes; // number of nodes in the graph
    int number_of_scc;            // number of strongly connected components
    int current_timestamp;     // current timestamp
    stack<int> s;   // A stack is used to store all nodes that may form city_a
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
        current_timestamp = 1;
        // Give some flexibility of size of our containers since
        // the node id/SCC id may not strictly start from 1, since the
        // number of nodes in the assignment will not exceed 10001,
        // the space complexity will not be city_a bottle-neck
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

unordered_map<string, int> node_2_id;
unordered_map<int, string, custom_hash> node_2_id_rev;
int node_id_counter = 1;

unordered_set<int, custom_hash> safe_SCC;
unordered_set<int, custom_hash> safe_cities;

bool vis[MAX_CITIES];
bool is_safe;
void dfs(int city_id) {
    if (vis[city_id]) {
        return;
    }
    vis[city_id] = true;
    if (safe_cities.find(city_id) != safe_cities.end()) {
        is_safe = true;
        return;
    }
    if (G.find(city_id) == G.end()) {
        return;
    }
    for (const int &adj_city_id : G[city_id]) {
        if (!vis[adj_city_id]) {
            dfs(adj_city_id);
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s %s", city_a, city_b);
        if (node_2_id.find(city_a) == node_2_id.end()) {
            node_2_id[city_a] = node_id_counter;
            node_2_id_rev[node_id_counter] = city_a;
            ++node_id_counter;
        }
        if (node_2_id.find(city_b) == node_2_id.end()) {
            node_2_id[city_b] = node_id_counter;
            node_2_id_rev[node_id_counter] = city_b;
            ++node_id_counter;
        }
        // add an edge
        G[node_2_id[city_a]].insert(node_2_id[city_b]);
    }
    SCC::init(node_id_counter);
    for (int i = 1; i < node_id_counter; ++i) {
        if (!SCC::dfs_rank.at(i)) {
            SCC::Tarjan(i);
        }
    }

    for (int i = 1; i <= SCC::number_of_scc; ++i) {
        if (SCC::size_of_scc.at(i) > 1) {
            safe_SCC.insert(i);
        }
    }
    for (int i = 1; i < node_id_counter; ++i) {
        if (safe_SCC.find(SCC::scc.at(i)) != safe_SCC.end()) {
            safe_cities.insert(i);
        }
    }

    while (~scanf("%s", city)) {
        int temp_city_id = node_2_id[city];
        is_safe = false;
        memset(vis, false, sizeof(vis));
        dfs(temp_city_id);
        if (is_safe) {
            safe_cities.insert(temp_city_id);
            printf("%s safe\n", city);
        } else {
            printf("%s trapped\n", city);
        }
    }

    return 0;
}
