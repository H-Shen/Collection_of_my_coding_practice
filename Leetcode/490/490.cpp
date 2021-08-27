class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // bfs
        int n = (int)maze.size();
        int m = (int)maze.front().size();
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        queue<pair<int,int> > q;
        q.push({start[0], start[1]});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.first == destination[0] && cur.second == destination[1]) {
                return true;
            }
            vis[cur.first][cur.second] = true;
            // four directions
            int i = cur.first;
            int j = cur.second;
            // up
            int new_i = i;
            int new_j = j;
            while (new_i >= 0 && new_i < n && maze[new_i][new_j] != 1) {
                --new_i;
            }
            ++new_i;
            if (!vis[new_i][new_j]) {
                q.push({new_i,new_j});
            }
            // down
            new_i = i;
            new_j = j;
            while (new_i >= 0 && new_i < n && maze[new_i][new_j] != 1) {
                ++new_i;
            }
            --new_i;
            if (!vis[new_i][new_j]) {
                q.push({new_i,new_j});
            }
            // left
            new_i = i;
            new_j = j;
            while (new_j >= 0 && new_j < m && maze[new_i][new_j] != 1) {
                --new_j;
            }
            ++new_j;
            if (!vis[new_i][new_j]) {
                q.push({new_i,new_j});
            }
            // right
            new_i = i;
            new_j = j;
            while (new_j >= 0 && new_j < m && maze[new_i][new_j] != 1) {
                ++new_j;
            }
            --new_j;
            if (!vis[new_i][new_j]) {
                q.push({new_i,new_j});
            }
        }
        return false;
    }
};