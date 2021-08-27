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
    vector<int> vec1, vec2;
    void dfs1(TreeNode* root) {
        if (root->left && root->right) {
            dfs1(root->left);
            dfs1(root->right);
        }
        else if (root->left && !root->right) {
            dfs1(root->left);
        }
        else if (!root->left && root->right) {
            dfs1(root->right);
        }
        else {
            vec1.emplace_back(root->val);
        }
    }
    void dfs2(TreeNode* root) {
        if (root->left && root->right) {
            dfs2(root->left);
            dfs2(root->right);
        }
        else if (root->left && !root->right) {
            dfs2(root->left);
        }
        else if (!root->left && root->right) {
            dfs2(root->right);
        }
        else {
            vec2.emplace_back(root->val);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        else if (root1 && !root2) {
            return false;
        }
        else if (!root1 && root2) {
            return false;
        }
        dfs1(root1);
        dfs2(root2);
        return vec1 == vec2;
    }
};