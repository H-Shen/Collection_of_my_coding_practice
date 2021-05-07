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
    vector<vector<int>> result;
    void dfs(TreeNode* root, int targetSum, vector<int> path) {
        path.emplace_back(root->val);
        if (root->left && root->right) {
            dfs(root->left, targetSum - root->val, path);
            dfs(root->right, targetSum - root->val, path);
        }
        else if (root->left && !root->right) {
            dfs(root->left, targetSum - root->val, path);
        }
        else if (!root->left && root->right) {
            dfs(root->right, targetSum - root->val, path);
        }
        else {
            if (targetSum - root->val == 0) {
                result.emplace_back(path);
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return result;
        }
        dfs(root, targetSum, vector<int>());
        return result;
    }
};