class Solution {
public:
    struct Node {
        int x, y, gap;
        explicit Node(int x, int y, int gap) : x(x), y(y), gap(gap) {}
        bool operator > (const Node &other) const {
            return gap > other.gap;
        }
    };

    int bfs(const vector<vector<int> > &heights) {
        constexpr int STEPS = 4;
        const int dx[] = {0, 0, -1, 1};
        const int dy[] = {-1, 1, 0, 0};
        int n = (int)heights.size();
        int m = (int)heights.front().size();
        vector<vector<bool> > vis(n, vector<bool>(m, false));
        std::priority_queue<Node, vector<Node>, greater<> > pq;
        pq.push(Node(0, 0, 0));
        int maximal_diff = -1;
        int new_x, new_y;
        while (!pq.empty()) {
            Node cur = pq.top();
            pq.pop();
            if (vis[cur.x][cur.y]) {
                continue;
            }
            vis[cur.x][cur.y] = true;
            maximal_diff = max(maximal_diff, cur.gap);
            if (cur.x == n - 1 && cur.y == m - 1) break;
            for (int step = 0; step < STEPS; ++step) {
                new_x = cur.x + dx[step];
                new_y = cur.y + dy[step];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m) {
                    pq.push(Node(new_x, new_y, abs(heights[new_x][new_y] - heights[cur.x][cur.y])));
                }
            }
        }
        return maximal_diff;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        return bfs(heights);
    }
};