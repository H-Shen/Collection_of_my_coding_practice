int n;
vector<int> inDegree, outDegree;
vector<deque<int>> adj;

// 求欧拉通路或欧拉回路
vector<int> Hierholzer(int startVertex) {
    stack<int> path;
    vector<int> circuit;
    int curr = startVertex;
    path.push(curr);
    while (!path.empty()) {
        if (!adj[curr].empty()) {
            path.push(curr);
            int next = adj[curr].front();
            adj[curr].pop_front();
            curr = next;
        }
        else {
            circuit.emplace_back(curr);
            curr = path.top();
            path.pop();
        }
    }
    reverse(circuit.begin(),circuit.end());
    return circuit;
}

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int length = (int)pairs.size();
        // 离散化
        vector<int> vec(2*length);
        for (int i = 0, j = 0; i < length; ++i) {
            vec[j++] = pairs[i][0];
            vec[j++] = pairs[i][1];
        }
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        n = (int)vec.size();
        vector<int>().swap(inDegree);
        inDegree.resize(n);
        vector<int>().swap(outDegree);
        outDegree.resize(n);
        vector<deque<int>>().swap(adj);
        adj.resize(n);
        // 建图
        int u,v;
        for (int i = 0; i < length; ++i) {
            u = (int)(lower_bound(vec.begin(),vec.end(),pairs[i][0]) - vec.begin());
            v = (int)(lower_bound(vec.begin(),vec.end(),pairs[i][1]) - vec.begin());
            adj[u].emplace_back(v);
            ++outDegree[u];
            ++inDegree[v];
        }
        // 找startVertex
        int startVertex = 0;
        for (int i = 0; i < n; ++i) {
            if (outDegree[i] - inDegree[i] == 1) {
                startVertex = i;
                break;
            }
        }
        auto path = Hierholzer(startVertex);
        vector<vector<int>> ans;
        length = (int)path.size();
        for (int i = 0; i < length-1; ++i) {
            u = vec[path[i]];
            v = vec[path[i+1]];
            ans.emplace_back(vector<int>{u,v});
        }
        return ans;
    }
};