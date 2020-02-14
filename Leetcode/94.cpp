/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> output;
    void solve(TreeNode* root) {
        if (root) {
            solve(root->left);
            output.emplace_back(root->val);
            solve(root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return output;
    }
};