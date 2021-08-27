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
    unordered_set<int> unset;
    void dfs(TreeNode* root) {
        if (root) {
            unset.insert(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        int diff;
        for (const auto &i : unset) {
            diff = k - i;
            if (diff != i && unset.find(diff) != unset.end()) {
                return true;
            }
        }
        return false;
    }
};