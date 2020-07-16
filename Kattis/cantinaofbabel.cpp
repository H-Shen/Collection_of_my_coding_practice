// https://open.kattis.com/problems/cantinaofbabel
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAX_NODES = 105;

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
    std::stack<int> s;   // A stack is used to store all nodes that may form a
    // strongly connected component
    std::vector<bool>
            visited; // visited.at(id) flags if the node id is in the stack
    std::vector<int> dfs_rank; // dfs_rank.at(id) numbers the nodes consecutively in
    // the order in which they are discovered by DFS
    std::vector<int> low_link; // low_link.at(id) represents the smallest node id of
    // any node known to be reachable from id through
    // id's DFS subtree, including id itself
    std::vector<int> scc;      // scc.at(id) is the index of the strongly connected
    // component that the node id belongs to
    std::vector<int> size_of_scc; // size_of_scc.at(id) is the size of the strongly
    // connected component whose index is id

    // Initialize all global variables in the namespace
    inline
    void init(int n) {
        number_of_nodes = n;
        number_of_scc = 0;
        current_timestamp = 1;
        // Give some flexibility of size of our containers since
        // the node id/SCC id may not strictly start from 1
        int offset = 5;
        visited.resize(number_of_nodes + offset, false);
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
        visited.at(u) = true;
        for (const auto &v : G[u]) {
            if (!dfs_rank[v]) {
                Tarjan(v);
                low_link.at(u) = std::min(low_link.at(u), low_link.at(v));
            } else if (visited.at(v)) {
                low_link.at(u) = std::min(low_link.at(u), dfs_rank.at(v));
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
                visited.at(top_id) = false;
            }
            // Paint u
            s.pop();
            scc.at(u) = number_of_scc;
            ++size_of_scc.at(number_of_scc);
            visited.at(u) = false;
        }
    }
}

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

struct Node {
    string can_speak;
    unordered_set<string> can_understand;
};
vector<Node> nodes(MAX_NODES);

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    string s;
    cin >> n;
    cin.get();
    for (int i = 1; i <= n; ++i) {
        getline(cin, s);
        auto p = splitByChar(s, ' ');
        nodes.at(i).can_speak = p.at(1);
        if (p.size() > 2) {
            for (size_t j = 2; j != p.size(); ++j) {
                nodes.at(i).can_understand.insert(p.at(j));
            }
        }
        // All characters understand the language they speak
        nodes.at(i).can_understand.insert(nodes.at(i).can_speak);
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                if (nodes.at(j).can_understand.find(nodes.at(i).can_speak) !=
                    nodes.at(j).can_understand.end()) {
                    G[i].insert(j);
                }
            }
        }
    }
    SCC::init(n);
    for (int i = 1; i <= n; ++i) {
        if (!SCC::dfs_rank.at(i)) {
            SCC::Tarjan(i);
        }
    }
    int max_nodes_in_a_scc = -1;
    for (int i = 1; i <= SCC::number_of_scc; ++i) {
        max_nodes_in_a_scc = max(max_nodes_in_a_scc, SCC::size_of_scc.at(i));
    }
    cout << n - max_nodes_in_a_scc << '\n';


    return 0;
}
