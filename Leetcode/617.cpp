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
    // merge root2 to root1
    void dfs(TreeNode* root1, TreeNode *root2) {
        root1->val += root2->val;
        if (root1->left && root2->left) {
            dfs(root1->left, root2->left);
        }
        else if (!root1->left && root2->left) {
            root1->left = root2->left;
        }
        if (root1->right && root2->right) {
            dfs(root1->right, root2->right);
        }
        else if (!root1->right && root2->right) {
            root1->right = root2->right;
        }
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return nullptr;
        else if (root1 && !root2) return root1;
        else if (!root1 && root2) return root2;
        dfs(root1, root2);
        return root1;
    }
};