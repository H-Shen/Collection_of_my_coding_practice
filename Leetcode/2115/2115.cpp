class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> str2id;
        unordered_map<int, string> id2recipe;
        int id = 0;
        for (auto&i : recipes) {
            if (str2id.find(i) == str2id.end()) {
                str2id[i] = id;
                id2recipe[id] = i;
                ++id;
            }
        }
        for (auto&i : ingredients) {
            for (auto&j : i) {
                if (str2id.find(j) == str2id.end()) {
                    str2id[j] = id;
                    ++id;
                }
            }
        }
        for (auto&i : supplies) {
            if (str2id.find(i) == str2id.end()) {
                str2id[i] = id;
                ++id;
            }
        }
        // Create the graph
        vector<vector<int>> adj(id);
        vector<int> inDegree(id);
        int n = (int)recipes.size();
        for (int i = 0; i < n; ++i) {
            int v = str2id[recipes[i]];
            for (auto&j : ingredients[i]) {
                int u = str2id[j];
                adj[u].emplace_back(v);
                ++inDegree[v];
            }
        }
        // Toposort, add all supplies as nodes without out degrees
        queue<int> q;
        for (auto&i : supplies) {
            q.push(str2id[i]);
        }
        vector<int> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            ans.emplace_back(u);
            for (int&v : adj[u]) {
                --inDegree[v];
                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        vector<string> res;
        for (auto&i : ans) {
            if (id2recipe.find(i) != id2recipe.end()) {
                res.emplace_back(id2recipe[i]);
            }
        }
        return res;
    }
};