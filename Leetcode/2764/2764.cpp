class Solution {
public:
    bool isPreorder(vector<vector<int>>& nodes) {
        int root = -1;
        unordered_map<int,vector<int>> adj;
        for (const auto &i : nodes) {
            if (i[1] == -1) {
                root = i[0];
            }
            else {
                adj[i[1]].emplace_back(i[0]);
            }
        }
        vector<int> vec;
        function<void(int)> preorder = [&](int u) {
            vec.emplace_back(u);
            if (adj[u].size() > 1) {
                preorder(adj[u][0]);
                preorder(adj[u][1]);
            }
            else if (adj[u].size() == 1) {
                preorder(adj[u][0]);
            }
        };
        preorder(root);
        vector<int> temp;
        for (const auto &i : nodes) {
            temp.emplace_back(i[0]);
        }
        return temp == vec;
    }
};