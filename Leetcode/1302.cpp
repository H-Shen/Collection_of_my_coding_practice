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
    int maxDepth;
    int sum;
    void dfs1(TreeNode* root, int level) {
        if (root->left && root->right) {
            dfs1(root->left, level + 1);
            dfs1(root->right, level + 1);
        }
        else if (!root->left && root->right) {
            dfs1(root->right, level + 1);
        }
        else if (root->left && !root->right) {
            dfs1(root->left, level + 1);
        }
        else {
            maxDepth = max(maxDepth, level);
        }
    }
    void dfs2(TreeNode* root, int level) {
        if (root->left && root->right) {
            dfs2(root->left, level + 1);
            dfs2(root->right, level + 1);
        }
        else if (!root->left && root->right) {
            dfs2(root->right, level + 1);
        }
        else if (root->left && !root->right) {
            dfs2(root->left, level + 1);
        }
        else {
            if (level == maxDepth) {
                sum += root->val;
            }
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        if (!root) return 0;
        maxDepth = -1;
        sum = 0;
        dfs1(root, 0);
        dfs2(root, 0);
        return sum;
    }
};