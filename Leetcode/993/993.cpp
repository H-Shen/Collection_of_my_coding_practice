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
    static const int MAXN = 105;
    int node2height[MAXN];
    int node2parent[MAXN];
    void dfs(TreeNode* root, int currHeight, TreeNode* fa) {
        node2height[root->val] = currHeight;
        if (fa != nullptr) {
            node2parent[root->val] = fa->val;
        }
        if (root->left && root->right) {
            dfs(root->left, currHeight + 1, root);
            dfs(root->right, currHeight + 1, root);
        }
        else if (root->left && !root->right) {
            dfs(root->left, currHeight + 1, root);
        }
        else if (!root->left && root->right) {
            dfs(root->right, currHeight + 1, root);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        node2parent[root->val] = -1;
        dfs(root, 0, nullptr);
        return node2height[x] == node2height[y] && node2parent[x] != node2parent[y];
    }
};