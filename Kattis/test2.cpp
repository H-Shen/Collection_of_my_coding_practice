// https://open.kattis.com/problems/test2
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
                std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<int, unordered_set<int, custom_hash>, custom_hash> G;

// A collection of containers and procedures that implements Tarjan's strongly
// connected components algorithm. Assume that the node id starts from 1 and the
// index of a strongly connected component (SCC) also starts from 1 Reference:
// https://en.wikipedia.org/wiki/Tarjan%27s_strongly_connected_components_algorithm#The_algorithm_in_pseudocode
namespace SCC {

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

    inline
    void reset() {
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

char s[2];
array<char, 7> temp_array;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    bool first_case = true;
    bool first_item;
    int n;
    while (true) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }
        G.clear();
        unordered_map<char, int> node_to_id;
        unordered_map<int, char> node_to_id_rev;
        int node_id_counter = 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", s);
            temp_array[1] = s[0];
            scanf("%s", s);
            temp_array[2] = s[0];
            scanf("%s", s);
            temp_array[3] = s[0];
            scanf("%s", s);
            temp_array[4] = s[0];
            scanf("%s", s);
            temp_array[5] = s[0];
            scanf("%s", s);
            temp_array[6] = s[0];
            for (int j = 1; j <= 5; ++j) {
                if (node_to_id.find(temp_array[j]) == node_to_id.end()) {
                    node_to_id[temp_array[j]] = node_id_counter;
                    node_to_id_rev[node_id_counter] = temp_array[j];
                    ++node_id_counter;
                }
            }
            // add edges
            for (int j = 1; j <= 5; ++j) {
                if (temp_array[j] != temp_array[6]) {
                    G[node_to_id[temp_array[6]]].insert(
                            node_to_id[temp_array[j]]);
                }
            }
        }
        // obtain it SCCs
        SCC::reset();
        SCC::init(node_id_counter);
        for (int j = 1; j < node_id_counter; ++j) {
            if (!SCC::dfs_rank.at(j)) {
                SCC::Tarjan(j);
            }
        }
        // arrange the unmap
        unordered_map<int, vector<char> > unmap;
        for (int j = 1; j < node_id_counter; ++j) {
            unmap[SCC::scc.at(j)].emplace_back(node_to_id_rev[j]);
        }
        // add to output
        vector<vector<char> > output;
        for (const auto &[k, v] : unmap) {
            if (!v.empty()) {
                output.emplace_back(v);
            }
        }
        // sort each SCC
        for (auto &j : output) {
            sort(j.begin(), j.end());
        }
        // sort output
        sort(output.begin(), output.end(),
             [](const auto &lhs, const auto &rhs) {
                 return (lhs.front() < rhs.front());
             });

        // output
        if (first_case) {
            first_case = false;
        } else {
            cout << '\n';
        }
        for (const auto &j : output) {
            first_item = true;
            for (const auto &k : j) {
                if (first_item) {
                    first_item = false;
                } else {
                    cout << ' ';
                }
                cout << k;
            }
            cout << '\n';
        }
    }
    return 0;
}
