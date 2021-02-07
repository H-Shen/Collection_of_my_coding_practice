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
    vector<string> vec;
    void dfs(TreeNode* root, string cur) {
        if (root->left && root->right) {
            if (root->val == 1) {
                cur.push_back('1');
            }
            else {
                cur.push_back('0'); 
            }
            dfs(root->left, cur);
            dfs(root->right, cur);
        }
        else if (root->left && !root->right) {
            if (root->val == 1) {
                cur.push_back('1');
            }
            else {
                cur.push_back('0');
            }
            dfs(root->left, cur);
        }
        else if (!root->left && root->right) {
            if (root->val == 1) {
                cur.push_back('1');
            }
            else {
                cur.push_back('0');
            }
            dfs(root->right, cur);
        }
        else {
            if (root->val == 1) {
                cur.push_back('1');
            }
            else {
                cur.push_back('0');
            }
            vec.emplace_back(cur);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, string());
        int sum = 0;
        for (const auto &i : vec) {
            sum += stoi(i, nullptr, 2);
        }
        return sum;
    }
};