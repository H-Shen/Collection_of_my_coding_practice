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
    int minAbsVal = numeric_limits<int>::max();
    int last;
    bool first = true;
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            if (first) {
                first = false;
                last = root->val;
            } else {
                minAbsVal = min(minAbsVal, abs(root->val - last));
                last = root->val;
            }
            dfs(root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return minAbsVal;
    }
};