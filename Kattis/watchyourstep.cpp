// https://open.kattis.com/problems/watchyourstep

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }
    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }
    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}


// A collection of containers and procedures that implements Tarjan's strongly
// connected components algorithm. Assume that the node id starts from 1 and the
// index of a strongly connected component (SCC) also starts from 1
namespace SCC_Tarjan {

    // adjacency list of the graph
    vector<vector<int> > G;
    // number of nodes in the graph
    int number_of_nodes;
    // number of strongly connected components
    int number_of_scc;
    int current_timestamp;
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
    void init(int n) {
        number_of_nodes = n;
        number_of_scc = 0;
        // NOTICE: starts from 1 if the node id starts from 1
        current_timestamp = 1;
        G.resize(number_of_nodes + 5);
        vis.resize(number_of_nodes + 5, false);
        dfs_rank.resize(number_of_nodes + 5, 0);
        low_link.resize(number_of_nodes + 5, 0);
        scc.resize(number_of_nodes + 5, 0);
        size_of_scc.resize(number_of_nodes + 5, 0);
    }

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

vector<int> in_degree;
vector<int> result; // store the result after toposort

bool kahn(const vector<vector<int> > &G, int number_of_nodes) {
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

int main() {

    int n, u, v, val;
    int edges = 0;
    IO::read(n);
    SCC_Tarjan::init(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            IO::read(val);
            if (val == 1) {
                SCC_Tarjan::G.at(i + 1).emplace_back(j + 1);
                ++edges;
            }
        }
    }
    // Run Tarjan's SCC algorithm
    for (int i = 1; i <= n; ++i) {
        // Process node i if the node i has not been visited
        if (!SCC_Tarjan::dfs_rank.at(i)) {
            SCC_Tarjan::Tarjan(i);
        }
    }
    if (SCC_Tarjan::number_of_scc == 1) {
        IO::writeln(n*(n-1) - edges);
        return 0;
    }
    // Contract
    vector<vector<int> > adj_after_contract(SCC_Tarjan::number_of_scc + 1);
    in_degree.resize(SCC_Tarjan::number_of_scc + 1);
    for (int i = 1; i <= n; ++i) {
        for (const int &j : SCC_Tarjan::G.at(i)) {
            u = SCC_Tarjan::scc.at(i);
            v = SCC_Tarjan::scc.at(j);
            if (u != v) {
                adj_after_contract.at(u).emplace_back(v);
                ++in_degree.at(v);
            }
        }
    }
    kahn(adj_after_contract, SCC_Tarjan::number_of_scc);
    vector<ll> N;
    for (const auto &i : result) {
        N.emplace_back(SCC_Tarjan::size_of_scc.at(i));
    }
    ll res = 0;
    for(int i = 0; i < (int)N.size(); ++i) {
        res += N[i] * (N[i] - 1);
        for(int j = i + 1; j < (int)N.size(); ++j) {
            res += N[i] * N[j];
        }
    }
    IO::writeln(res - (ll)edges);

    return 0;
}
