class Solution {
public:
    vector<bool> vis;
    void dfs(int u, const vector<vector<int>>& adj) {
        if (vis.at(u)) return;
        vis.at(u) = true;
        for (const auto &v : adj.at(u)) {
            dfs(v, adj);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = (int)rooms.size();
        vis.resize(n, false);
        dfs(0, rooms);
        for (const auto &i : vis) {
            if (!i) return false;
        }
        return true;
    }
};