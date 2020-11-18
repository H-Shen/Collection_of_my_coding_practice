namespace SSSP {
    constexpr int INF = 0x3f3f3f3f;
    vector<vector<int> > prev;
    vector<vector<int> > dis;
    
    void reset() {
        decltype(prev)().swap(prev);
        decltype(dis)().swap(dis);
    }
    
    void dijkstra(int n, int source, vector<unordered_map<int, double> > &adj) {
        if (prev.at(source).empty()) {
            prev.at(source).resize(n + 5, -1);  
        }
        if (dis.at(source).empty()) {
            dis.at(source).resize(n + 5, INF);
        }
        dis.at(source).at(source) = 0;
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<> > pq;
        pq.push(make_pair(dis.at(source).at(source), source));
        while (!pq.empty()) {
            int d_v = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if (d_v != dis.at(source).at(v)) {
                continue;
            }
            for (const auto &[to, weight] : adj.at(v)) {
                if (dis.at(source).at(to) > dis.at(source).at(v) + 1) {
                    dis.at(source).at(to) = dis.at(source).at(v) + 1;
                    prev.at(source).at(to) = v;
                    pq.push(make_pair(dis.at(source).at(to), to));
                }
            }
        }
    }

    
    vector<int> get_path(int source, int destination) {
        vector<int> path;
        for (; destination != -1; destination = prev.at(source).at(destination)) {
            path.emplace_back(destination);
        }
        reverse(path.begin(), path.end());
        return path;
    }
}

class Solution {
    vector<unordered_map<int, double> > adj;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // reset
        SSSP::reset();
        decltype(adj)().swap(adj);
        // give each node an unique id
        unordered_map<string, int> node2id;
        int id = 0;
        for (const auto &i : equations) {
            for (const auto &j : i) {
                if (node2id.find(j) == node2id.end()) {
                    node2id[j] = id;
                    ++id;
                }
            }
        }
        // create the graph
        adj.resize(id + 5);
        SSSP::prev.resize(id + 5);
        SSSP::dis.resize(id + 5);
        int u, v;
        double w;
        for (size_t i = 0; i != equations.size(); ++i) {
            u = node2id[equations.at(i).at(0)];
            v = node2id[equations.at(i).at(1)];
            w = values.at(i);
            adj.at(u).insert({v, w});
            adj.at(v).insert({u, 1.0 / w});
        }
        // query
        vector<double> result;
        vector<int> path;
        for (const auto &i : queries) {
            if (node2id.find(i.at(0)) == node2id.end()) {
                result.emplace_back(-1.0);
                continue;
            } else {
                u = node2id[i.at(0)];
            }
            if (node2id.find(i.at(1)) == node2id.end()) {
                result.emplace_back(-1.0);
                continue;
            } else {
                v = node2id[i.at(1)];
            }
            SSSP::dijkstra(id, u, adj);
            if (SSSP::dis.at(u).at(v) == SSSP::INF) {
                result.emplace_back(-1.0);
            } else {
                if (u == v) {
                    result.emplace_back(1.0);
                } else {
                    path = SSSP::get_path(u, v);
                    double answer = 1.0;
                    int a, b;
                    for (size_t j = 1; j != path.size(); ++j) {
                        a = path.at(j - 1);
                        b = path.at(j);
                        answer *= adj.at(a)[b];
                    }
                    result.emplace_back(answer);
                }
            }
        }
        return result;
    }
};