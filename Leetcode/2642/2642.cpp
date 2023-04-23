using ll = long long;

constexpr int MAXN = 105;
constexpr ll INF = 0x3f3f3f3f3f3f;

class Graph {
private:
    vector<vector<pair<int,ll>>> adj;
    int nodes;
    ll dist[MAXN];
public:
    Graph(int n, vector<vector<int>>& edges) {
        nodes = n;
        adj.resize(n);
        int u,v;
        ll w;
        for (const auto&i : edges) {
            u = i[0];
            v = i[1];
            w = i[2];
            adj[u].emplace_back(v,w);
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        ll w = edge[2];
        adj[u].emplace_back(v,w);
    }
    
    int shortestPath(int node1, int node2) {
        for (int i = 0; i < nodes; ++i) {
            dist[i] = INF;
        }
        dist[node1] = 0;
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
        pq.emplace(dist[node1], node1);
        pair<ll,int> temp;
        int u;
        ll d_u;
        while (!pq.empty()) {
            temp = pq.top();
            pq.pop();
            d_u = temp.first;
            u = temp.second;
            if (d_u != dist[u]) {
                continue;
            }
            for (const auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v],v);
                }
            }
        }
        if (dist[node2] == INF) {
            return -1;
        }
        return (int)dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */