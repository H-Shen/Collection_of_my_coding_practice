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
    int currentValue = -1;
    bool dfs(TreeNode* root) {
        if (currentValue == -1) {
            currentValue = root->val;
        }
        else if (currentValue != root->val) {
            return false;
        }
        if (root->left && root->right) {
            return dfs(root->left) && dfs(root->right);
        }
        else if (root->left && !root->right) {
            return dfs(root->left);
        }
        else if (!root->left && root->right) {
            return dfs(root->right);
        }
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        return dfs(root);
    }
};