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
    int total = 0;
    void solve(TreeNode* root) {
        if (root) {
            if (root->val % 2 == 0) {
                if (root->left) {
                    if (root->left->left) {
                        total += root->left->left->val;
                    }
                    if (root->left->right) {
                        total += root->left->right->val;
                    }
                }
                if (root->right) {
                    if (root->right->left) {
                        total += root->right->left->val;
                    }
                    if (root->right->right) {
                        total += root->right->right->val;
                    }
                }
            }
            solve(root->left);
            solve(root->right);
        }
    }
    int sumEvenGrandparent(TreeNode* root) {
        solve(root);
        return total;
    }
};