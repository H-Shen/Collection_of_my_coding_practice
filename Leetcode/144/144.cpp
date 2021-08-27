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
    void f(TreeNode* root, vector<int> &v) {
        if (root) {
            v.emplace_back(root->val);
            f(root->left, v);
            f(root->right, v);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        f(root, v);
        return v;
    }
};