#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

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

int main() {

    int n, m, u, v, type;
    IO::read(n, m);
    while (m--) {
        IO::read(u, v, type);
        G[u].insert(v);
        if (type == 2) {
            G[v].insert(u);
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
    unordered_set<int, custom_hash> scc_with_max_nodes;
    for (int i = 1; i <= SCC::number_of_scc; ++i) {
        if (SCC::size_of_scc.at(i) == max_nodes_in_a_scc) {
            scc_with_max_nodes.insert(i);
        }
    }
    unordered_map<int, vector<int>, custom_hash> unmap;
    for (int i = 1; i <= n; ++i) {
        if (scc_with_max_nodes.find(SCC::scc.at(i)) != scc_with_max_nodes.end()) {
            unmap[SCC::scc.at(i)].emplace_back(i);
        }
    }
    vector<vector<int> > output;
    for (const auto &[k, v] : unmap) {
        if (!v.empty()) {
            output.emplace_back(v);
        }
    }
    for (auto &i : output) {
        sort(i.begin(), i.end());
    }
    sort(output.begin(), output.end(), [](const auto &l, const auto &r){
        return l.front() < r.front();
    });
    bool first_item = true;
    IO::writeln(max_nodes_in_a_scc);
    for (const auto &i : output.front()) {
        if (first_item) {
            first_item = false;
        } else {
            putchar_unlocked(' ');
        }
        IO::write(i);
    }
    putchar_unlocked('\n');

    return 0;
}