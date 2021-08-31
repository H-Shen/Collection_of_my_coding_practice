class Solution {
public:
    vector<vector<int>> AL;
    int n;
    vector<int> dist;
    void dijkstra(int src) {
        constexpr int INF = 0x3f3f3f3f;
        fill(dist.begin(),dist.end(),INF);
        dist[src] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<> > pq;
        pq.push({dist[src], src});
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int d_u = p.first;
            int u = p.second;
            if (d_u != dist[u]) {
                continue;
            }
            for (const auto &v : AL[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    pq.push({dist[v],v});
                }
            }
        }
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<vector<int>>().swap(AL);
        n = (int)friends.size();
        AL.resize(n);
        for (int u = 0; u < n; ++u) {
            for (const auto &v : friends[u]) {
                AL[u].emplace_back(v);
                AL[v].emplace_back(u);
            }
        }
        vector<int>().swap(dist);
        dist.resize(n);
        dijkstra(id);
        unordered_map<string,int> freq;
        for (int i = 0; i < n; ++i) {
            if (dist[i] == level) {
                for (const auto &j : watchedVideos[i]) {
                    ++freq[j];
                }
            }
        }
        vector<pair<string,int>> vec(freq.begin(),freq.end());
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            if (l.second == r.second) {
                return l.first < r.first;
            }
            return l.second < r.second;
        });
        vector<string> ans(vec.size());
        for (size_t i = 0; i != ans.size(); ++i) {
            ans[i] = vec[i].first;
        }
        return ans;
    }
};