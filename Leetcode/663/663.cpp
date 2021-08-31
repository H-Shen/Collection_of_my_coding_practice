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
    int sumOfTree;
    bool haveAns;
    int solve(TreeNode* node) {
        if (dp.find(node) != dp.end()) {
            return dp[node];
        }
        dp[node] = node->val;
        if (node->left) {
            dp[node] += solve(node->left);
        }
        if (node->right) {
            dp[node] += solve(node->right);
        }
        return dp[node];
    }
    void dfs(TreeNode* node, TreeNode* fa) {
        if (haveAns) {
            return;
        }
        if (node) {
            if (fa && solve(node) == sumOfTree - solve(node)) {
                haveAns = true;
                return;
            }
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }
    bool checkEqualTree(TreeNode* root) {
        dp.clear();
        haveAns = false;
        sumOfTree = solve(root);
        dfs(root, nullptr);
        return haveAns;
    }
};