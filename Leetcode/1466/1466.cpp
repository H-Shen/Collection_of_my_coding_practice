struct myHashFunc {
    size_t operator()(const pair<int,int> &o) const {
        return hash<int>()(o.first)^hash<int>()(o.second);
    }  
};
class Solution {
public:
    vector<vector<int> > AL;
    unordered_set<pair<int,int>, myHashFunc > unset;
    void dfs(int u, int father_of_u) {
        unset.insert({u,father_of_u});
        for (const auto &v : AL[u]) {
            if (v != father_of_u) {
                dfs(v, u);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int> >().swap(AL);
        unset.clear();
        AL.resize(n);
        for (const auto &i : connections) {
            AL[i[0]].emplace_back(i[1]);
            AL[i[1]].emplace_back(i[0]);
        }
        dfs(0,-1);
        int counter = 0;
        for (const auto &i : connections) {
            if (unset.find({i[0],i[1]}) == unset.end()) {
                ++counter;
            }
        }
        return counter;
    }
};