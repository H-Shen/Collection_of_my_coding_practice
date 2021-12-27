vector<deque<int>> adj;
vector<int> inDeg, outDeg;

vector<int> Hierholzer(int startVertex) {
    stack<int> path;
    vector<int> circuit;
    int current = startVertex;
    path.push(current);
    while (!path.empty()) {
        if (!adj[current].empty()) {
            path.push(current);
            int next = adj[current].front();
            adj[current].pop_front();
            current = next;
        }
        else {
            circuit.emplace_back(current);
            current = path.top();
            path.pop();
        }
    }
    reverse(circuit.begin(),circuit.end());
    return circuit;
}

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,int> str2id;
        vector<string> id2str;
        int id = 0;
        for (auto&i : tickets) {
            for (auto&j : i) {
                if (str2id.find(j) == str2id.end()) {
                    str2id[j] = id;
                    id2str.emplace_back(j);
                    ++id;
                }
            }
        }
        vector<deque<int>>().swap(adj);
        adj.resize(id);
        vector<int>().swap(inDeg);
        inDeg.resize(id);
        vector<int>().swap(outDeg);
        outDeg.resize(id);
        int u,v;
        for (auto&i : tickets) {
            u = str2id[i[0]];
            v = str2id[i[1]];
            adj[u].emplace_back(v);
            ++outDeg[u];
            ++inDeg[v];
        }
        auto cmp = [&](const int &l, const int &r){
            return id2str[l] < id2str[r];
        };
        for (auto&i : adj) {
            sort(i.begin(),i.end(),cmp);
        }
        vector<string> ans;
        int startVertex = str2id["JFK"];
        auto path = Hierholzer(startVertex);
        for (auto&i : path) {
            ans.emplace_back(id2str[i]);
        }
        return ans;
    }
};