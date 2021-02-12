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
    int sum = 0;
    void dfs(TreeNode* root, bool leftChild) {
        if (root->left && root->right) {
            dfs(root->left, true);
            dfs(root->right, false);
        }
        else if (!root->left && root->right) {
            dfs(root->right, false);
        }
        else if (root->left && !root->right) {
            dfs(root->left, true);
        }
        else {
            if (leftChild) sum += root->val;
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        dfs(root, false);
        return sum;
    }
};