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
    string dfs(TreeNode* t) {
        if (!t) return string();
        if (t->left && t->right) {
            return to_string(t->val) + '(' + dfs(t->left) + ')' + '(' + dfs(t->right) + ')';
        }
        else if (t->left && !t->right) {
            return to_string(t->val) + '(' + dfs(t->left) + ')';
        }
        else if (!t->left && t->right) {
            return to_string(t->val) + '(' + ')' + '(' + dfs(t->right) + ')';
        }
        else {
            return to_string(t->val);   
        }
    }
    string tree2str(TreeNode* t) {
        return dfs(t);
    }
};