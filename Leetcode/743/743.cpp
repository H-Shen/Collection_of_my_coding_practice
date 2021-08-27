constexpr int INF = 0x3f3f3f3f;

inline vector<int>
dijkstra(int source, int n, const vector<vector<pair<int, int> > > &adj) {
    vector<int> dis(n + 5, INF);
    dis.at(source) = 0;
    std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
    pq.push(make_pair(dis.at(source), source));
    while (!pq.empty()) {
        int d_v = pq.top().first;
        int v = pq.top().second;
        pq.pop();
        if (d_v != dis.at(v)) {
            continue;
        }
        for (const auto &[to, weight] : adj.at(v)) {
            if (dis.at(to) > dis.at(v) + weight) {
                dis.at(to) = dis.at(v) + weight;
                pq.push(make_pair(dis.at(to), to));
            }
        }
    }
    return dis;
}

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int> > > adj(N + 5);
        int u, v, w;
        for (const auto &e : times) {
            u = e.at(0);
            v = e.at(1);
            w = e.at(2);
            adj.at(u).push_back({v, w});
        }
        auto dis = dijkstra(K, N, adj);
        int result = -1;
        for (auto iter = dis.begin() + 1; iter != dis.begin() + N + 1; ++iter) {
            if (*iter == INF) {
                return -1;
            }
            result = max(result, *iter);
        }
        return result;
    }
};