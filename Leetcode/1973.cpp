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
using ll = long long;

class Solution {
public:
    unordered_map<TreeNode*, ll> dp;
    int ans;
    ll solve(TreeNode* root) {
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }
        dp[root] = root->val;
        if (root->left) {
            dp[root] += solve(root->left);
        }
        if (root->right) {
            dp[root] += solve(root->right);
        }
        return dp[root];
    }
    void dfs(TreeNode* root) {
        if (root) {
            if (solve(root) - root->val == root->val) {
                ++ans;
            }
            dfs(root->left);
            dfs(root->right);
        }
    }
    int equalToDescendants(TreeNode* root) {
        dp.clear();
        ans = 0;
        dfs(root);
        return ans;
    }
};