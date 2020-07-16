// https://open.kattis.com/problems/loopycabdrivers
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 30;
char a[MAXN];
char b[MAXN];

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

namespace SCC {

    // adjacency list of the graph
    unordered_map<int, unordered_set<int, custom_hash>, custom_hash> G;

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
        current_timestamp = 1;
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

unordered_map<string, int> node_2_id;
unordered_map<int, string, custom_hash> node_2_id_rev;
int node_id_counter = 1;

int main() {

    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s %s", a, b);
        if (node_2_id.find(a) == node_2_id.end()) {
            node_2_id[a] = node_id_counter;
            node_2_id_rev[node_id_counter] = a;
            ++node_id_counter;
        }
        if (node_2_id.find(b) == node_2_id.end()) {
            node_2_id[b] = node_id_counter;
            node_2_id_rev[node_id_counter] = b;
            ++node_id_counter;
        }
        // add an edge
        SCC::G[node_2_id[a]].insert(node_2_id[b]);
    }
    SCC::init(node_id_counter);
    for (int i = 1; i < node_id_counter; ++i) {
        if (!SCC::dfs_rank.at(i)) {
            SCC::Tarjan(i);
        }
    }
    unordered_set<int, custom_hash> all_SCCs_with_size_of_one;
    unordered_map<int, vector<int>, custom_hash> all_SCCs_with_size_larger_than_one;
    for (int i = 1; i <= SCC::number_of_scc; ++i) {
        if (SCC::size_of_scc.at(i) == 1) {
            all_SCCs_with_size_of_one.insert(i);
        } else if (SCC::size_of_scc.at(i) > 1) {
            all_SCCs_with_size_larger_than_one[i];
        }
    }
    for (int i = 1; i < node_id_counter; ++i) {
        if (all_SCCs_with_size_larger_than_one.find(SCC::scc.at(i)) !=
            all_SCCs_with_size_larger_than_one.end()) {
            all_SCCs_with_size_larger_than_one[SCC::scc.at(i)].emplace_back(i);
        }
    }
    vector<string> avoid;
    for (int i = 1; i < node_id_counter; ++i) {
        if (all_SCCs_with_size_of_one.find(SCC::scc.at(i)) !=
            all_SCCs_with_size_of_one.end()) {
            avoid.emplace_back(node_2_id_rev[i]);
        }
    }
    // output
    vector<vector<string> > group_can_be_visited;
    for (const auto &[k, v] : all_SCCs_with_size_larger_than_one) {
        vector<string> temp_vec;
        for (const auto &store_id : v) {
            temp_vec.emplace_back(node_2_id_rev[store_id]);
        }
        if (!temp_vec.empty()) {
            group_can_be_visited.emplace_back(temp_vec);
        }
    }
    // sort each group
    for (auto &i : group_can_be_visited) {
        sort(i.begin(), i.end());
    }
    // sort the whole array
    sort(group_can_be_visited.begin(), group_can_be_visited.end(),
         [](const auto &lhs, const auto &rhs) {
             return (lhs.front() < rhs.front());
         });
    // output
    for (const auto &i : group_can_be_visited) {
        printf("okay");
        for (const auto &j : i) {
            printf(" %s", j.c_str());
        }
        printf("\n");
    }
    if (!avoid.empty()) {
        printf("avoid");
        sort(avoid.begin(), avoid.end());
        for (const auto &i : avoid) {
            printf(" %s", i.c_str());
        }
        printf("\n");
    }

    return 0;
}
