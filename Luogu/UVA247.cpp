#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace SCC_Tarjan {

    // adjacency list of the graph
    vector<vector<int> > G;

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
        decltype(G)().swap(G);
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
        G.resize(number_of_nodes + offset);
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

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, id, u, v;
    string u_str, v_str;
    int kase = 1;
    bool firstItem;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        unordered_map<string, int> name2id;
        vector<string> id2name = {""};
        SCC_Tarjan::init(n);
        id = 1;
        while (m--) {
            cin >> u_str;
            if (name2id.find(u_str) != name2id.end()) {
                u = name2id[u_str];
            } else {
                name2id[u_str] = id;
                id2name.emplace_back(u_str);
                u = id;
                ++id;
            }
            cin >> v_str;
            if (name2id.find(v_str) != name2id.end()) {
                v = name2id[v_str];
            } else {
                name2id[v_str] = id;
                id2name.emplace_back(v_str);
                v = id;
                ++id;
            }
            SCC_Tarjan::G.at(u).emplace_back(v);
        }
        // Run Tarjan
        for (int i = 1; i <= n; ++i) {
            if (!SCC_Tarjan::dfs_rank.at(i)) {
                SCC_Tarjan::Tarjan(i);
            }
        }
        unordered_map<int, unordered_set<string> > SCCs;
        for (int i = 1; i <= n; ++i) {
            SCCs[SCC_Tarjan::scc.at(i)].insert(id2name.at(i));
        }
        // output
        cout << "Calling circles for data set " << kase << ':' << '\n';
        ++kase;
        for (const auto &i : SCCs) {
            firstItem = true;
            for (const auto &j : i.second) {
                if (firstItem) {
                    firstItem = false;
                } else {
                    cout << ", ";
                }
                cout << j;
            }
            cout << '\n';
        }
        // reset
        SCC_Tarjan::reset();
    }
    return 0;
}