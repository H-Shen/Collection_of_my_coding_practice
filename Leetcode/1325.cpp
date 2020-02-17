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
    bool change = false;
    void solve(TreeNode* root, int target) {
        if (root) {
            auto left_child = root->left;
            if (left_child && left_child->val == target) {
                if (left_child->left == nullptr && left_child->right == nullptr) {
                    change = true;
                    root->left = nullptr;
                }
            }
            auto right_child = root->right;
            if (right_child && right_child->val == target) {
                if (right_child->left == nullptr && right_child->right == nullptr) {
                    change = true;
                    root->right = nullptr;
                }
            }
            solve(root->left, target);
            solve(root->right, target);
        }
    }
    
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        while (true) {
            change = false;
            solve(root, target);
            if (!change) {
                break;
            }
        }
        if (root && !root->left && !root->right && root->val == target) {
            root = nullptr;
        }
        return root;
    }
};