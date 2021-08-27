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
    void solve(TreeNode* root, vector<int>& output) {
        if (root) {
            output.emplace_back(root->val);
            solve(root->left, output);
            solve(root->right, output);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> output;
        solve(root1, output);
        solve(root2, output);
        sort(output.begin(), output.end());
        return output;
    }
};