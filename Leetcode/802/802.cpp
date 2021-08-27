namespace Topo {
    vector<vector<int> > AL;
    vector<int> inDegree;
    int n;
    void init(int n_) {
        n = n_;
        decltype(AL)().swap(AL);
        decltype(inDegree)().swap(inDegree);
        AL.resize(n);
        inDegree.resize(n);
    }
    void kahn() {
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (const auto &v : AL[u]) {
                --inDegree[v];
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
}
class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = (int)graph.size();
        Topo::init(n);
        for (int i = 0; i < n; ++i) {
            for (const auto &j : graph[i]) {
                Topo::AL[j].emplace_back(i);    // rev graph
                ++Topo::inDegree[i];
            }
        }
        Topo::kahn();
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (Topo::inDegree[i] == 0) {
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};