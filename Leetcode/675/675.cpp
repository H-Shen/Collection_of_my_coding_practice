constexpr int N = 52;
constexpr int STEP = 4;

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

bool vis[N][N]; // 这里用二维bool定长数组比二维bitset快
int n, m;

struct Node {
    int i,j,dist;
    Node(int i, int j, int dist) : i(i),j(j),dist(dist){};
    Node() = default;
};

class Solution {
public:
    int bfs(int current_i, int current_j, int next_i, int next_j, vector<vector<int>>& forest) {
        memset(vis,0,sizeof(vis));
        queue<Node> q;
        q.push(Node(current_i,current_j,0));
        vis[current_i][current_j] = true;
        int new_i,new_j;
        Node node;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node.i == next_i && node.j == next_j) return node.dist;
            for (int step = 0; step < STEP; ++step) {
                new_i = node.i + dx[step];
                new_j = node.j + dy[step];
                // 只要大于0 都可以走 树不砍就行
                if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && !vis[new_i][new_j] && forest[new_i][new_j] > 0) {
                    vis[new_i][new_j] = true;
                    q.push(Node(new_i,new_j,node.dist+1));
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        n = (int)forest.size();
        m = (int)forest[0].size();
        vector<pair<int,int>> trees;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(i,j);
                }
            }
        }
        // 因为树高唯一 所以每一步从矮树到高树的最短路也唯一
        sort(trees.begin(),trees.end(),[&](const auto &l, const auto &r){
            return forest[l.first][l.second] < forest[r.first][r.second];
        });
        int current_i = 0;
        int current_j = 0;
        int total_steps = 0;
        for (auto& i : trees) {
            // 贪心 每一步都走最短路即可 这里用bfs求最短路
            int current_steps = bfs(current_i,current_j,i.first,i.second, forest);
            if (current_steps == -1) return -1;
            total_steps += current_steps;
            current_i = i.first;
            current_j = i.second;
        }
        return total_steps;
    }
};