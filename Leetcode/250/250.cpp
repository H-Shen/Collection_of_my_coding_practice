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
    unordered_map<TreeNode*,bool> dp;
    bool solve(TreeNode* root) {
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }
        if (root->left && root->right) {
            if (root->val == root->left->val && root->val == root->right->val) {
                dp[root] = solve(root->left) && solve(root->right);
            }
            else {
                dp[root] = false;
            }
        }
        else if (root->left && !root->right) {
            if (root->val == root->left->val) {
                dp[root] = solve(root->left);
            }
            else {
                dp[root] = false;
            }
        }
        else if (!root->left && root->right) {
            if (root->val == root->right->val) {
                dp[root] = solve(root->right);
            }
            else {
                dp[root] = false;
            }
        }
        else {
            dp[root] = true;
        }
        return dp[root];
    }
    int n;
    void dfs(TreeNode* root) {
        if (root) {
            if (solve(root)) {
                ++n;
            }
            dfs(root->left);
            dfs(root->right);
        }
    }
    int countUnivalSubtrees(TreeNode* root) {
        if (!root) {
            return 0;
        }
        n = 0;
        dfs(root);
        return n;
    }
};