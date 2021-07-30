constexpr int N = 100;
constexpr int INF = 0x3f3f3f3f;
int dist[N*N][N*N];

class Solution {
public:
    struct Node {
        int tail_i, tail_j, head_i, head_j;
    };
    int minimumMoves(vector<vector<int>>& grid) {
        int n = (int)grid.size();
        memset(dist, 0x3f, sizeof dist);
        queue<Node> q;
        Node src;
        src.tail_i = 0;
        src.tail_j = 0;
        src.head_i = 0;
        src.head_j = 1;
        dist[0*N+0][0*N+1] = 0;
        q.push(src);
        Node cur;
        Node newNode;
        int corner_i, corner_j;
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            // move right
            newNode.tail_i = cur.tail_i;
            newNode.tail_j = cur.tail_j+1;
            newNode.head_i = cur.head_i;
            newNode.head_j = cur.head_j+1;
            if (newNode.tail_i >= 0 && newNode.tail_i < n && newNode.tail_j >= 0 && newNode.tail_j < n && newNode.head_i >= 0 && newNode.head_i < n && newNode.head_j >= 0 && newNode.head_j < n && grid[newNode.tail_i][newNode.tail_j] == 0 && grid[newNode.head_i][newNode.head_j] == 0) {
                if (dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j] == INF) {
                    dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j] = dist[cur.tail_i*N+cur.tail_j][cur.head_i*N+cur.head_j] + 1;
                    if (newNode.tail_i == n-1 && newNode.tail_j == n-2 && newNode.head_i == n-1 && newNode.head_j == n-1) {
                        return dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j];
                    }
                    q.push(newNode);
                }
            }
            // move down
            newNode.tail_i = cur.tail_i+1;
            newNode.tail_j = cur.tail_j;
            newNode.head_i = cur.head_i+1;
            newNode.head_j = cur.head_j;
            if (newNode.tail_i >= 0 && newNode.tail_i < n && newNode.tail_j >= 0 && newNode.tail_j < n && newNode.head_i >= 0 && newNode.head_i < n && newNode.head_j >= 0 && newNode.head_j < n && grid[newNode.tail_i][newNode.tail_j] == 0 && grid[newNode.head_i][newNode.head_j] == 0) {
                if (dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j] == INF) {
                    dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j] = dist[cur.tail_i*N+cur.tail_j][cur.head_i*N+cur.head_j] + 1;
                    if (newNode.tail_i == n-1 && newNode.tail_j == n-2 && newNode.head_i == n-1 && newNode.head_j == n-1) {
                        return dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j];
                    }
                    q.push(newNode);
                }
            }
            // cw
            if (cur.tail_i == cur.head_i && cur.tail_j == cur.head_j - 1){
                newNode.tail_i = cur.tail_i;
                newNode.tail_j = cur.tail_j;
                newNode.head_i = cur.head_i+1;
                newNode.head_j = cur.head_j-1;
                corner_i = cur.tail_i+1;
                corner_j = cur.tail_j+1;
                if (newNode.tail_i >= 0 && newNode.tail_i < n && newNode.tail_j >= 0 && newNode.tail_j < n && newNode.head_i >= 0 && newNode.head_i < n && newNode.head_j >= 0 && newNode.head_j < n && grid[newNode.tail_i][newNode.tail_j] == 0 && grid[newNode.head_i][newNode.head_j] == 0) {
                    if (corner_i >= 0 && corner_i < n && corner_j >= 0 && corner_j < n && grid[corner_i][corner_j] == 0) {
                        if (dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j] == INF) {
                            dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j] = dist[cur.tail_i*N+cur.tail_j][cur.head_i*N+cur.head_j] + 1;
                            if (newNode.tail_i == n-1 && newNode.tail_j == n-2 && newNode.head_i == n-1 && newNode.head_j == n-1) {
                                return dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j];
                            }
                            q.push(newNode);
                        }
                    }
                }
            }
            // ccw
            if (cur.tail_j == cur.head_j && cur.tail_i == cur.head_i - 1){
                newNode.tail_i = cur.tail_i;
                newNode.tail_j = cur.tail_j;
                newNode.head_i = cur.head_i-1;
                newNode.head_j = cur.head_j+1;
                corner_i = cur.tail_i+1;
                corner_j = cur.tail_j+1;
                if (newNode.tail_i >= 0 && newNode.tail_i < n && newNode.tail_j >= 0 && newNode.tail_j < n && newNode.head_i >= 0 && newNode.head_i < n && newNode.head_j >= 0 && newNode.head_j < n && grid[newNode.tail_i][newNode.tail_j] == 0 && grid[newNode.head_i][newNode.head_j] == 0) {
                    if (corner_i >= 0 && corner_i < n && corner_j >= 0 && corner_j < n && grid[corner_i][corner_j] == 0) {
                        if (dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j] == INF) {
                            dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j] = dist[cur.tail_i*N+cur.tail_j][cur.head_i*N+cur.head_j] + 1;
                            if (newNode.tail_i == n-1 && newNode.tail_j == n-2 && newNode.head_i == n-1 && newNode.head_j == n-1) {
                                return dist[newNode.tail_i*N+newNode.tail_j][newNode.head_i*N+newNode.head_j];
                            }
                            q.push(newNode);
                        }
                    }
                }
            }
        }
        return -1;
    }
};