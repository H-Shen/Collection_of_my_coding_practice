namespace SCC_Tarjan {
    
    vector<vector<int> > G;
    int number_of_nodes;
    int number_of_scc;
    int current_timestamp;
    stack<int> s;
    vector<bool> vis;
    vector<int> dfs_rank;
    vector<int> low_link;
    vector<int> scc;
    vector<int> size_of_scc;

    void reset() {
        decltype(G)().swap(G);
        stack<int>().swap(s);
        vector<bool>().swap(vis);
        vector<int>().swap(dfs_rank);
        vector<int>().swap(low_link);
        vector<int>().swap(scc);
        vector<int>().swap(size_of_scc);
    }

    void init(int n) {
        number_of_nodes = n;
        number_of_scc = 0;
        current_timestamp = 1;
        G.resize(number_of_nodes + 5);
        vis.resize(number_of_nodes + 5, false);
        dfs_rank.resize(number_of_nodes + 5, 0);
        low_link.resize(number_of_nodes + 5, 0);
        scc.resize(number_of_nodes + 5, 0);
        size_of_scc.resize(number_of_nodes + 5, 0);
    }

    void Tarjan(int u) {
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
                s.pop();
                scc.at(top_id) = number_of_scc;
                ++size_of_scc.at(number_of_scc);
                vis.at(top_id) = false;
            }
            s.pop();
            scc.at(u) = number_of_scc;
            ++size_of_scc.at(number_of_scc);
            vis.at(u) = false;
        }
    }
}

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        SCC_Tarjan::reset();
        int n = (int)edges.size();
        SCC_Tarjan::init(n);
        int u,v;
        for (int i = 0; i < n; ++i) {
            u = i+1;
            v = edges[i];
            if (v != -1) {
                ++v;
                SCC_Tarjan::G[u].emplace_back(v);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!SCC_Tarjan::dfs_rank[i]) {
                SCC_Tarjan::Tarjan(i);
            }
        }
        int ans = -1;
        for (int i = 1; i <= SCC_Tarjan::number_of_scc; ++i) {
            if (SCC_Tarjan::size_of_scc[i] > 1) {
                ans = max(ans, SCC_Tarjan::size_of_scc[i]);
            }
        }
        return ans;
    }
};