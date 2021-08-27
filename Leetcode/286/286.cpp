constexpr int INF = 2147483647;
constexpr int STEPS = 4;
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

class Solution {
public:
    // multiple sources bfs
    void wallsAndGates(vector<vector<int>>& rooms) {
        int n = (int)rooms.size();
        int m = (int)rooms[0].size();
        queue<pair<int,int> > q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (rooms[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }
        int i, j, new_i, new_j;
        while (!q.empty()) {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            for (int step = 0; step < STEPS; ++step) {
                new_i = i + dx[step];
                new_j = j + dy[step];
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && rooms[new_i][new_j] == INF) {
                    rooms[new_i][new_j] = rooms[i][j] + 1;
                    q.push({new_i,new_j});
                }
            }
        }
    }
};