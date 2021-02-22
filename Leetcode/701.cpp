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
    void insert(TreeNode* root, int val, TreeNode* parent) {
        if (!root) {
            TreeNode* node = new TreeNode(val);
            if (parent) {
                if (val > parent->val) {
                    parent->right = node;
                } else {
                    parent->left = node;
                }
            }
        } else {
            if (val > root->val) {
                insert(root->right, val, root);
            } else {
                insert(root->left, val, root);
            }
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        insert(root, val, nullptr);
        return root;
    }
};