using ll = long long;

struct Maxflow {
    static constexpr ll INF = 4e18;
    using edge = tuple<int, ll, ll>;
    int n;
    vector<edge> el;
    vector<vector<int> > adj;
    vector<int> d, last;
    vector<pair<int, int> > p;    
    bool bfs(int s, int t) {
        d.assign(n, -1); d[s] = 0;
        queue<int> q({s});
        p.assign(n, {-1, -1});
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (auto &idx : adj[u]) {                  
                auto &[v, cap, flow] = el[idx];          
                if ((cap-flow > 0) && (d[v] == -1))      
                    d[v] = d[u]+1, q.push(v), p[v] = {u, idx};
            }
        }
        return d[t] != -1;
    }

    ll send_one_flow(int s, int t, ll f = INF) {
        if (s == t) return f;                        
        auto &[u, idx] = p[t];
        auto &cap = get<1>(el[idx]), &flow = get<2>(el[idx]);
        ll pushed = send_one_flow(s, u, min(f, cap-flow));
        flow += pushed;
        auto &rflow = get<2>(el[idx ^ 1]);             
        rflow -= pushed;                             
        return pushed;
    }

    ll dfs(int u, int t, ll f = INF) {
        if ((u == t) || (f == 0)) return f;
        for (int &i = last[u]; i < (int)adj[u].size(); ++i) {
            auto &[v, cap, flow] = el[adj[u][i]];
            if (d[v] != d[u]+1) continue;    
            if (ll pushed = dfs(v, t, min(f, cap - flow))) {
                flow += pushed;
                auto &rflow = get<2>(el[adj[u][i] ^ 1]);   
                rflow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    Maxflow() = default;
    Maxflow(int number_of_nodes) : n(number_of_nodes) {
        adj.resize(n);
    }
    void add_edge(int u, int v, ll w, bool directed = true) {
        if (u == v) return;                          
        el.emplace_back(v, w, 0);                   
        adj[u].push_back(el.size() - 1);               
        el.emplace_back(u, directed ? 0 : w, 0);     
        adj[v].push_back(el.size() - 1);                
    }
    ll edmonds_karp(int s, int t) {
        ll mf = 0;                                   
        while (bfs(s, t)) {                          
            ll f = send_one_flow(s, t);             
            if (f == 0) break;                       
            mf += f;                                 
        }
        return mf;
    }
    ll dinic(int s, int t) {
        ll mf = 0;                                   
        while (bfs(s, t)) {                        
            last.assign(n, 0);                         
            while (ll f = dfs(s, t))
                mf += f;
        }
        return mf;
    }
};


class Solution {
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        constexpr int MAXN = 205;
        // 将二分图最大匹配转换为最大流问题
        int n = (int)grid.size();
        int m = (int)grid[0].size();
        int left_id = 1;
        bitset<MAXN> leftVis, rightVis;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    leftVis[i] = true;
                    rightVis[j] = true;
                }
            }
        }
        unordered_map<int,int> left2id,right2id;
        int id = 1;
        for (int i = 0; i < MAXN; ++i) {
            if (leftVis[i]) {
                left2id[i] = id;
                ++id;
            }
        }
        for (int i = 0; i < MAXN; ++i) {
            if (rightVis[i]) {
                right2id[i] = id;
                ++id;
            }
        }
        int s = 0;
        int leftNodes = (int)left2id.size();
        int rightNodes = (int)right2id.size();
        int t = leftNodes + rightNodes + 1;
        Maxflow M(leftNodes + rightNodes + 2);
        // left
        for (auto&[i,j] : left2id) {
            M.add_edge(s,j,1);
        }
        // middle 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    M.add_edge(left2id[i],right2id[j],1);
                }
            }
        }
        // right
        for (auto&[i,j] : right2id) {
            M.add_edge(j,t,1);
        }
        // run dinic
        return M.dinic(s,t);
    }
};