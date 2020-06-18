// https://open.kattis.com/problems/managingpackaging
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
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

unordered_map<string, int> string_2_node_id;
unordered_map<int, string, custom_hash> string_2_node_id_rev;
int node_id_counter = 1;

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
    auto cmp = [](const int &lhs, const int &rhs) {
        return string_2_node_id_rev[lhs] > string_2_node_id_rev[rhs];
    };

    // Main logic of Kahn's algorithm but the output should be lexicographically
    // smallest among all possible results after toposort: O(|V|log|V|+|E|)
    bool Kahn_with_lexicographically_smallest() {
        std::priority_queue<int, vector<int>, decltype(cmp)> q(cmp);
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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, u, v;
    string s;
    bool first_case = true;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cin.get();
        for (int i = 0; i < n; ++i) {
            getline(cin, s);
            auto package_list = splitByChar(s, ' ');
            // add u
            if (string_2_node_id.find(package_list.front()) ==
                string_2_node_id.end()) {
                string_2_node_id[package_list.front()] = node_id_counter;
                string_2_node_id_rev[node_id_counter] = package_list.front();
                ++node_id_counter;
            }
            u = string_2_node_id[package_list.front()];
            // add v and (v, u)
            if (package_list.size() > 1) {
                for (size_t j = 1; j != package_list.size(); ++j) {
                    if (string_2_node_id.find(package_list.at(j)) ==
                        string_2_node_id.end()) {
                        string_2_node_id[package_list.at(j)] = node_id_counter;
                        string_2_node_id_rev[node_id_counter] = package_list.at(
                                j);
                        ++node_id_counter;
                    }
                    v = string_2_node_id[package_list.at(j)];
                    Toposort::G[v].insert(u);
                }
            }
        }
        // calculate in-degree of each node
        Toposort::init(node_id_counter - 1);
        for (const auto &[v, adj_v_list] : Toposort::G) {
            for (const auto &adj_v : adj_v_list) {
                ++Toposort::in_degree.at(adj_v);
            }
        }
        // Run toposort and output
        if (first_case) {
            first_case = false;
        } else {
            cout << ' ' << '\n';
        }
        if (Toposort::Kahn_with_lexicographically_smallest()) {
            for (const auto &j : Toposort::result) {
                cout << string_2_node_id_rev[j] << '\n';
            }
        } else {
            cout << "cannot be ordered" << '\n';
        }
        // Reset
        Toposort::reset();
        string_2_node_id_rev.clear();
        string_2_node_id.clear();
        node_id_counter = 1;
    }


    return 0;
}
