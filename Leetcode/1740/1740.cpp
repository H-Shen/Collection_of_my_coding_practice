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
class Solution {
public:
    Solution() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); }
    unordered_map<int, int> height;
    unordered_map<int, int> parent;
    void dfs(TreeNode* root, int curHeight) {
        height[root->val] = curHeight;
        if (root->left && root->right) {
            dfs(root->left, curHeight + 1);
            dfs(root->right, curHeight + 1);
        }
        else if (root->left && !root->right) {
            dfs(root->left, curHeight + 1);
        }
        else if (!root->left && root->right) {
            dfs(root->right, curHeight + 1);
        }
    }
    void dfs2(TreeNode* u, TreeNode* father_of_u) {
        if (u) {
            if (father_of_u) {
                parent[u->val] = father_of_u->val;
            }
            else {
                parent[u->val] = -1;
            }
            dfs2(u->left, u);
            dfs2(u->right, u);
        }
    }
    int lca(int u, int v) {
        if (u == v) {
            return u;
        }
        int h1 = height[u];
        int h2 = height[v];
        if (h1 == h2) {
            return lca(parent[u], parent[v]);
        }
        else if (h1 > h2) {
            return lca(parent[u], v);
        }
        return lca(u, parent[v]);
    }
    int findDistance(TreeNode* root, int p, int q) {
        dfs(root, 0);
        dfs2(root, nullptr);
        return height[p] + height[q] - 2*height[lca(p,q)];
    }
};