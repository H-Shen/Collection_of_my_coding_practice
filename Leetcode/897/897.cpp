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
    void f(TreeNode* root, vector<TreeNode*> &A) {
        if (root) {
            f(root->left, A);
            A.emplace_back(root);
            f(root->right, A);
        }
    }
    TreeNode* increasingBST(TreeNode* root) {
        if (!root) return nullptr;
        vector<TreeNode* > A;
        f(root, A);
        int n = (int)A.size();
        for (int i = 0; i < n - 1; ++i) {
            A.at(i)->left = nullptr;
            A.at(i)->right = A.at(i + 1);
        }
        A.at(n - 1)->left = nullptr;
        A.at(n - 1)->right = nullptr;
        return A.at(0);
    }
};