class Solution {
public:
    vector<vector<int> > adj;   // adj of the dag
    vector<int> Dijkstra(int source, int n, vector<int>& informTime) {
        constexpr int INF = 0x3f3f3f3f;
        vector<int> dist(n, INF);
        dist.at(source) = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        pq.push({dist.at(source), source});
        while (!pq.empty()) {
            int dist_to_u = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (dist_to_u != dist.at(u)) {
                continue;
            }
            for (const auto &v : adj.at(u)) {
                int weight = informTime.at(u);
                if (dist.at(v) > dist.at(u) + weight) {
                    dist.at(v) = dist.at(u) + weight;
                    pq.push({dist.at(v), v});
                }
            }
        }
        return dist;
    }    
    

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        adj.resize(n);
        for (int i = 0; i < n; ++i) {
            if (manager[i] != -1) {
                adj[manager[i]].emplace_back(i);
            }
        }
        auto dist = Dijkstra(headID, n, informTime);
        return *max_element(dist.begin(), dist.end());
    }
};