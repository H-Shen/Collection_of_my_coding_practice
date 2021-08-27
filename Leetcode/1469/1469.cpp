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
    vector<int> vec;
    void dfs(TreeNode* root) {
        if (root->left && root->right) {
            dfs(root->left);
            dfs(root->right);
        }
        else if (root->left && !root->right) {
            vec.emplace_back(root->left->val);
            dfs(root->left);
        }
        else if (!root->left && root->right) {
            vec.emplace_back(root->right->val);
            dfs(root->right);
        }
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        dfs(root);
        return vec;
    }
};