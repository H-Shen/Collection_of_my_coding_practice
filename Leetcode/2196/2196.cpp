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
constexpr int MAXN = 2*1e4+5;
constexpr int MAXVALUE = 1e5+5;

int parent[MAXN];
int val[MAXN];
int child[MAXN][2];
int vis[MAXVALUE];

class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        memset(vis,0,sizeof vis);
        memset(parent,0,sizeof parent);
        memset(val,0,sizeof val);
        memset(child,0,sizeof child);
        int id = 1;
        for (auto&i : descriptions) {
            if (vis[i[0]] == 0) {
                vis[i[0]] = id;
                ++id;
            }
            if (vis[i[1]] == 0) {
                vis[i[1]] = id;
                ++id;
            }
            parent[vis[i[1]]] = vis[i[0]];
            if (i[2]) {
                child[vis[i[0]]][0] = vis[i[1]];
            }
            else {
                child[vis[i[0]]][1] = vis[i[1]];
            }
        }
        for (int i = 0; i < MAXVALUE; ++i) {
            if (vis[i] != 0) {
                val[vis[i]] = i;
            }
        }
        vector<TreeNode*> tree(id+1);
        for (int i = 1; i <= id; ++i) {
            tree[i] = new TreeNode(val[i]);
        }
        int rootId = 0;
        for (int i = 1; i <= id; ++i) {
            if (parent[i] == 0) {
                rootId = i;
                break;
            }
        }
        for (int i = 1; i <= id; ++i) {
            if (child[i][0] != 0) {
                tree[i]->left = tree[child[i][0]];
            }
            if (child[i][1] != 0) {
                tree[i]->right = tree[child[i][1]];
            }
        }
        return tree[rootId];
    }
};