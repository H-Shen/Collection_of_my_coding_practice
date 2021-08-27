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
    unordered_map<TreeNode*, int> dp;   // dp[u] = the maxvalue in the path from u to root
    unordered_map<TreeNode*, TreeNode*> fa;
    int ans;
    void dfs(TreeNode* root, TreeNode* father_of_root) {
        if (root) {
            fa[root] = father_of_root;
            dfs(root->left, root);
            dfs(root->right, root);
        }
    }
    int solve(TreeNode* u) {
        if (dp.find(u) != dp.end()) {
            return dp[u];
        }
        if (fa[u]) {
            dp[u] = max(u->val, solve(fa[u]));
        }
        else {
            dp[u] = u->val;
        }
        return dp[u];
    }
    void dfs2(TreeNode* u) {
        if (u) {
            if (solve(u) <= u->val) {
                ++ans;
            }
            dfs2(u->left);
            dfs2(u->right);
        } 
    }
    int goodNodes(TreeNode* root) {
        dp.clear();
        fa.clear();
        dfs(root, nullptr);
        ans = 0;
        dfs2(root);
        return ans;
    }
};