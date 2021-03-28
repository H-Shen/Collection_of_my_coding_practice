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
    vector<TreeNode*> vec;
    void preOrder(TreeNode* root) {
        if (root) {
            vec.emplace_back(root);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void flatten(TreeNode* root) {
        preOrder(root);
        if (vec.size() <= 1) return;
        int n = (int)vec.size();
        for (int i = 0; i < n - 1; ++i) {
            vec.at(i)->left = nullptr;
            vec.at(i)->right = vec.at(i+1);
        }
        vec.back()->left = nullptr;
        vec.back()->right = nullptr;
    }
};