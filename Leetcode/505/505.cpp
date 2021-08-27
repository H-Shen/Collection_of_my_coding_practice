class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // bfs
        constexpr int INF = 0x3f3f3f3f;
        int n = (int)maze.size();
        int m = (int)maze.front().size();
        vector<vector<int> > dist(n, vector<int>(m, INF));
        queue<pair<int,int> > q;
        q.push({start[0], start[1]});
        dist[start[0]][start[1]] = 0;
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            // four directions
            int i = cur.first;
            int j = cur.second;
            int step;
            // up
            int new_i = i;
            int new_j = j;
            step = 0;
            while (new_i >= 0 && new_i < n && maze[new_i][new_j] != 1) {
                --new_i;
                ++step;
            }
            ++new_i;
            if (step > 0) {
                --step;
            }
            if (dist[new_i][new_j] > dist[i][j] + step) {
                q.push({new_i,new_j});
                dist[new_i][new_j] = dist[i][j] + step;
            }
            // down
            new_i = i;
            new_j = j;
            step = 0;
            while (new_i >= 0 && new_i < n && maze[new_i][new_j] != 1) {
                ++new_i;
                ++step;
            }
            --new_i;
            if (step > 0) {
                --step;
            }
            if (dist[new_i][new_j] > dist[i][j] + step) {
                q.push({new_i,new_j});
                dist[new_i][new_j] = dist[i][j] + step;
            }
            // left
            new_i = i;
            new_j = j;
            step = 0;
            while (new_j >= 0 && new_j < m && maze[new_i][new_j] != 1) {
                --new_j;
                ++step;
            }
            ++new_j;
            if (step > 0) {
                --step;
            }
            if (dist[new_i][new_j] > dist[i][j] + step) {
                q.push({new_i,new_j});
                dist[new_i][new_j] = dist[i][j] + step;
            }
            // right
            new_i = i;
            new_j = j;
            step = 0;
            while (new_j >= 0 && new_j < m && maze[new_i][new_j] != 1) {
                ++new_j;
                ++step;
            }
            --new_j;
            if (step > 0) {
                --step;
            }
            if (dist[new_i][new_j] > dist[i][j] + step) {
                q.push({new_i,new_j});
                dist[new_i][new_j] = dist[i][j] + step;
            }
        }
        if (dist[destination[0]][destination[1]] == INF) {
            return -1;
        }
        return dist[destination[0]][destination[1]];
    }
};