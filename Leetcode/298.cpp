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
    unordered_map<TreeNode*,int> dp;
    int ans;
    int solve(TreeNode* root) {
        if (dp.find(root) != dp.end()) return dp[root];
        int tempLeft, tempRight;
        if (root->left && root->right) {
            if (root->val == root->left->val - 1) {
                tempLeft = solve(root->left) + 1;
            }
            else {
                tempLeft = 1;
            }
            if (root->val == root->right->val - 1) {
                tempRight = solve(root->right) + 1;
            }
            else {
                tempRight = 1;
            }
            dp[root] = max(tempLeft, tempRight);
        }
        else if (root->left && !root->right) {
            if (root->val == root->left->val - 1) {
                tempLeft = solve(root->left) + 1;
            }
            else {
                tempLeft = 1;
            }
            dp[root] = tempLeft;
        }
        else if (!root->left && root->right) {
            if (root->val == root->right->val - 1) {
                tempRight = solve(root->right) + 1;
            }
            else {
                tempRight = 1;
            }
            dp[root] = tempRight;
        }
        else {
            dp[root] = 1;
        }
        return dp[root];
    }
    void dfs(TreeNode* root) {
        if (root) {
            ans = max(ans, solve(root));
            dfs(root->left);
            dfs(root->right);
        }
    }
    int longestConsecutive(TreeNode* root) {
        dp.clear();
        ans = 0;
        dfs(root);
        return ans;
    }
};