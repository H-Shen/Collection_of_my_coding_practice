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
    unordered_map<TreeNode*, int> dp;
    int solve(TreeNode* node) {
        if (!node) {
            return 0;
        }
        if (dp.count(node) > 0) {
            return dp[node];
        }
        int v1, v2;
        // choose root
        v1 = node->val;
        if (node->left) {
            v1 += solve(node->left->left) + solve(node->left->right);
        }
        if (node->right) {
            v1 += solve(node->right->left) + solve(node->right->right);
        } 
        // not choose root
        v2 = 0;
        if (node->left) {
            v2 += solve(node->left);
        }
        if (node->right) {
            v2 += solve(node->right);
        }
        int maxVal = max(v1, v2);
        dp[node] = maxVal;
        return maxVal;
    }
    int rob(TreeNode* root) {
        dp.clear();
        return solve(root);
    }
};