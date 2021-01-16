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
    int minDiff = numeric_limits<int>::max();
    bool firstElement = true;
    int last;
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            if (firstElement) {
                firstElement = false;
                last = root->val;
            } else {
                minDiff = min(minDiff, abs(root->val - last));
                last = root->val;
            }
            dfs(root->right);
        }
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return minDiff;
    }
};