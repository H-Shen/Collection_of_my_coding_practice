class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        constexpr int STEPS = 4;
        constexpr int INF = 0x3f3f3f3f;
        constexpr int MAXN = 105;
        const int dx[] = {0,0,-1,1};
        const int dy[] = {-1,1,0,0};
        int n = (int)maze.size();
        int m = (int)maze[0].size();
        // obtain all exits
        bitset<MAXN> exits[MAXN];
        for (int i = 0; i < n; ++i) {
            if (maze[i][0] == '.' && !(i == entrance[0] && 0 == entrance[1]) ) {
                exits[i][0] = true;
            }
            if (maze[i][m-1] == '.' && !(i == entrance[0] && m-1 == entrance[1]) ) {
                exits[i][m-1] = true;
            }
        }
        for (int j = 0; j < m; ++j) {
            if (maze[0][j] == '.' && !(0 == entrance[0] && j == entrance[1]) ) {
                exits[0][j] = true;
            }
            if (maze[n-1][j] == '.' && !(n-1 == entrance[0] && j == entrance[1]) ) {
                exits[n-1][j] = true;
            }
        }
        vector<vector<int> > dist(n, vector<int>(m, INF));
        dist[entrance[0]][entrance[1]] = 0;
        // bfs
        queue<pair<int,int> > q;
        q.push({entrance[0],entrance[1]});
        int i,j,new_i,new_j;
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            if (exits[i][j]) break;
            q.pop();
            for (int step = 0; step < STEPS; ++step) {
                new_i = i + dx[step];
                new_j = j + dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && maze[new_i][new_j] == '.' && dist[new_i][new_j] == INF) {
                    dist[new_i][new_j] = dist[i][j] + 1;
                    q.push({new_i,new_j});
                }
            }
        }
        int ans = INF;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (exits[i][j]) {
                    ans = min(ans, dist[i][j]);
                }
            }
        }
        return (ans == INF) ? -1 : ans;
    }
};