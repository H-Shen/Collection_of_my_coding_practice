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
    vector<vector<int> > paths;
    void dfs(TreeNode* root, vector<int> curPath) {
        if (root->left && root->right) {
            curPath.emplace_back(root->val);
            dfs(root->left, curPath);
            dfs(root->right, curPath);
        }
        else if (root->left && !root->right) {
            curPath.emplace_back(root->val);
            dfs(root->left, curPath);
        }
        else if (!root->left && root->right) {
            curPath.emplace_back(root->val);
            dfs(root->right, curPath);
        }
        else {
            curPath.emplace_back(root->val);
            paths.emplace_back(curPath);
        }
    }
    string convert(const vector<int> &A) {
        string s = to_string(A.front());
        int n = (int)A.size();
        for (int i = 1; i < n; ++i) {
            s += "->" + to_string(A.at(i));
        }
        return s;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        dfs(root, vector<int>());
        for (const auto &i : paths) {
            result.emplace_back(convert(i));
        }
        return result;
    }
};