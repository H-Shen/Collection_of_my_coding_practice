#include <bits/extc++.h>

using namespace std;

namespace IO {
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

// Assume that the node id starts from 1 and the index of a strongly connected component also starts from 1
namespace SCC {

    int number_of_nodes;  // number of nodes in the graph
    unordered_map<int, unordered_set<int> > G;  // the adjacent list of the graph
    stack<int> s; // A stack is used to store all nodes that may form a strongly connected component
    vector<bool> visited; // visited.at(id) flags if the node id is in the stack
    vector<int> dfs_rank; // dfs_rank.at(id) numbers the nodes consecutively in the order in which they are discovered by DFS
    vector<int> lowlink; // lowlink.at(id) represents the smallest node id of any node known to be reachable from id through id's DFS subtree, including id itself
    vector<int> scc; // scc.at(id) is the index of the strongly connected component that the node id belongs to
    vector<int> size_of_scc; // size_of_scc.at(id) is the size of the strongly connected component whose index is id
    int number_of_scc; // number of strongly connected components
    int current_timestamp;

    // Initialize all global variables in the namespace
    void init(int n) {
        number_of_nodes = n;
        number_of_scc = 0;
        current_timestamp = 1;
        // Give some flexibility of size of our containers since
        // the node id/SCC id may not strictly start from 1, since the
        // number of nodes in the assignment will not exceed 10001,
        // the space complexity will not be a bottle-neck
        int offset = 5;
        visited.resize(number_of_nodes + offset, false);
        dfs_rank.resize(number_of_nodes + offset, 0);
        lowlink.resize(number_of_nodes + offset, 0);
        scc.resize(number_of_nodes + offset, 0);
        size_of_scc.resize(number_of_nodes + offset, 0);
        G.clear();
    }

    void Tarjan(int u) {    // u: the node id being processed
        dfs_rank.at(u) = current_timestamp;
        lowlink.at(u) = current_timestamp;
        ++current_timestamp;
        s.push(u);
        visited.at(u) = true;
        for (const auto &v : G[u]) {
            if (!dfs_rank[v]) {
                Tarjan(v);
                lowlink.at(u) = min(lowlink.at(u), lowlink.at(v));
            } else if (visited.at(v)) {
                lowlink.at(u) = min(lowlink.at(u), dfs_rank.at(v));
            }
        }
        if (lowlink.at(u) == dfs_rank.at(u)) {
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


int main() {

    int n, m, u, v;
    IO::read(n, m);
    SCC::init(n);
    while (m--) {
        IO::read(u, v);
        SCC::G[u].insert(v);
    }
    // Run Tarjan's SCC algorithm
    for (int i = 1; i <= n; ++i) {
        // Process node i if the node i has not been visited
        if (!SCC::dfs_rank.at(i)) {
            SCC::Tarjan(i);
        }
    }
    // Count the number of SCCs where each SCC contains more than 1 node
    int counter = 0;
    for (int i = 1; i <= SCC::number_of_scc; ++i) {
        if (SCC::size_of_scc.at(i) > 1) {
            ++counter;
        }
    }
    IO::writeln(counter);

    return 0;
}
