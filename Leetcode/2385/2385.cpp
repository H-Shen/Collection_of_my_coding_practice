/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
constexpr int MAXN = 1e5+5;
constexpr int INF = 0x3f3f3f3f;
int dist[MAXN];

class Solution {
public:
    vector<vector<int>> adj;
    void dfs(TreeNode* node, TreeNode* fa) {
        if (node) {
            int v = node->val;
            if (fa) {
                int u = fa->val;
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
    int bfs(int u) {
        queue<int> q;
        q.push(u);
        memset(dist, 0x3f, sizeof dist);
        dist[u] = 0;
        while (!q.empty()) {
            u = q.front();
            q.pop();
            for (const auto &v : adj[u]) {
                if (dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < MAXN; ++i) {
            if (dist[i] != INF) {
                ans = max(ans, dist[i]);
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>>().swap(adj);
        adj.resize(MAXN);
        dfs(root, nullptr);
        return bfs(start);
    }
};