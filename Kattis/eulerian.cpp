// https://open.kattis.com/problems/eulerian

#include <bits/extc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n+5);
        iota(father.begin(),father.end(),0);
        Size.resize(n+5, 1);
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (Size[x] > Size[y]) swap(x, y);
        Size[y] += Size[x];
        father[x] = y;
    }
}

namespace SCC_Tarjan {

    // adjacency list of the graph
    vector<vector<int> > AL;
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
        decltype(AL)().swap(AL);
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
        AL.resize(number_of_nodes + 5);
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
        for (const auto &v : AL[u]) {
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

    void run(int n) {
        for (int i = 1; i <= n; ++i) {
            if (!dfs_rank.at(i)) {
                Tarjan(i);
            }
        }
    }
}

int n, m, u, v;
vector<int> inDeg, outDeg;

bool hasEulerCircuit() {
    SCC_Tarjan::run(n);
    if (SCC_Tarjan::number_of_scc != 1) {
        return false;
    }
    for (int i = 1; i <= n; ++i) {
        if (inDeg[i] != outDeg[i]) {
            return false;
        }
    }
    return true;
}

bool hasEulerPath(int &v1, int &v2) {
    unordered_set<int> groups;
    for (int i = 1; i <= n; ++i) {
        groups.insert(DSU::find(i));
        if (groups.size() > 1) {
            return false;
        }
    }
    if (groups.size() != 1) {
        return false;
    }
    int counter1 = 0, counter2 = 0;
    for (int i = 1; i <= n; ++i) {
        if (inDeg[i] - outDeg[i] == 1) {
            ++counter1;
            if (counter1 > 1) {
                return false;
            }
            v1 = i;
        }
        else if (outDeg[i] - inDeg[i] == 1) {
            ++counter2;
            if (counter2 > 1) {
                return false;
            }
            v2 = i;
        }
        else if (inDeg[i] == outDeg[i]) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {
    IO::read(n, m);
    DSU::init(n);
    SCC_Tarjan::init(n);
    inDeg.resize(n+1);
    outDeg.resize(n+1);
    for (int i = 0; i < m; ++i) {
        IO::read(u,v);
        ++outDeg[u];
        ++inDeg[v];
        DSU::merge(u,v);
        SCC_Tarjan::AL[u].emplace_back(v);
    }
    if (hasEulerCircuit()) {
        puts("anywhere");
        return 0;
    }
    int v1, v2;
    if (hasEulerPath(v1, v2)) {
        IO::write(v2);
        putchar_unlocked(' ');
        IO::writeln(v1);
        return 0;
    }
    puts("no");

    return 0;
}
