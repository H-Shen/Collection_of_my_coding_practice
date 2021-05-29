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
    string ans;
    void dfs(TreeNode* root, string s) {
        if (root->left && root->right) {
            dfs(root->left, s + (char)(root->left->val+'a'));
            dfs(root->right, s + (char)(root->right->val+'a'));
        }
        else if (root->left && !root->right) {
            dfs(root->left, s + (char)(root->left->val+'a'));
        }
        else if (!root->left && root->right) {
            dfs(root->right, s + (char)(root->right->val+'a'));
        }
        else {
            reverse(s.begin(), s.end());
            if (ans.empty()) {
                ans = s;
            } else {
                ans = min(ans, s);
            }
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        ans.clear();
        string s;
        s.push_back(root->val+'a');
        dfs(root, s);
        return ans;
    }
};