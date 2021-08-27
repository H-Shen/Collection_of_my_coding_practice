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
    int sum = 0;
    void dfs(string s, TreeNode* root) {
        if (root) {
            s += root->val + '0';
            if (root->left && root->right) {
                dfs(s, root->left);
                dfs(s, root->right);
            } else if (root->left && !root->right) {
                dfs(s, root->left);
            } else if (!root->left && root->right) {
                dfs(s, root->right);
            } else {
                sum += stoi(s);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        dfs(string(), root);
        return sum;
    }
};