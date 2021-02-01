// https://open.kattis.com/problems/reversingroads

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
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

namespace SCC_Tarjan {

    unordered_map<int, unordered_set<int> > G;
    int number_of_nodes;
    int number_of_scc;
    int current_timestamp;
    stack<int> s;
    vector<bool> vis;
    vector<int> dfs_rank;
    vector<int> low_link;
    vector<int> scc;
    vector<int> size_of_scc;

    // reset all containers
    void reset() {
        stack<int>().swap(s);
        fill(vis.begin(), vis.end(), false);
        fill(dfs_rank.begin(), dfs_rank.end(), 0);
        fill(low_link.begin(), low_link.end(), 0);
        fill(scc.begin(), scc.end(), 0);
        fill(size_of_scc.begin(), size_of_scc.end(), 0);
        current_timestamp = 1;
        number_of_scc = 0;
    }

    // Initialize all global variables in the namespace
    void init(int n) {

        G.clear();
        stack<int>().swap(s);
        vector<bool>().swap(vis);
        vector<int>().swap(dfs_rank);
        vector<int>().swap(low_link);
        vector<int>().swap(scc);
        vector<int>().swap(size_of_scc);
        number_of_nodes = n;
        number_of_scc = 0;
        // NOTICE: starts from 1 if the node id starts from 1
        current_timestamp = 1;

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

vector<pair<int, int> > edges;
int n, m, u, v;
int kase = 1;

int main() {

    while (IO::can_read(n, m)) {
        SCC_Tarjan::init(n);
        decltype(edges)().swap(edges);
        edges.resize(m);
        for (int i = 0; i < m; ++i) {
            IO::read(u, v);
            ++u;
            ++v;
            edges.at(i).first = u;
            edges.at(i).second = v;
            SCC_Tarjan::G[u].insert(v);
        }
        // Run Tarjan's SCC algorithm
        for (int i = 1; i <= n; ++i) {
            // Process node i if the node i has not been visited
            if (!SCC_Tarjan::dfs_rank.at(i)) {
                SCC_Tarjan::Tarjan(i);
            }
        }
        if (SCC_Tarjan::number_of_scc == 1) {
            printf("Case %d: valid\n", kase);
            ++kase;
            continue;
        }
        bool have_ans = false;
        for (int i = 0; i < m; ++i) {
            u = edges.at(i).first;
            v = edges.at(i).second;
            SCC_Tarjan::G[u].erase(v);
            SCC_Tarjan::G[v].insert(u);
            // Rerun Tarjan
            SCC_Tarjan::reset();
            for (int j = 1; j <= n; ++j) {
                // Process node i if the node i has not been visited
                if (!SCC_Tarjan::dfs_rank.at(j)) {
                    SCC_Tarjan::Tarjan(j);
                }
            }
            if (SCC_Tarjan::number_of_scc == 1) {
                --u;
                --v;
                printf("Case %d: %d %d\n", kase, u, v);
                ++kase;
                have_ans = true;
                break;
            }
            // restore
            SCC_Tarjan::G[v].erase(u);
            SCC_Tarjan::G[u].insert(v);
        }
        if (!have_ans) {
            printf("Case %d: Invalid\n", kase);
            ++kase;
        }
    }
    return 0;
}
