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
    bool haveAns;
    void dfs(TreeNode* root, const vector<int> &arr, int pos) {
        if (haveAns) {
            return;
        }
        if (root->left && root->right) {
            if (pos >= (int)arr.size() || root->val != arr[pos]) {
                return;
            }
            dfs(root->left, arr, pos+1);
            dfs(root->right,arr, pos+1);
        }
        else if (!root->left && root->right) {
            if (pos >= (int)arr.size() || root->val != arr[pos]) {
                return;
            }
            dfs(root->right,arr, pos+1);
        }
        else if (root->left && !root->right) {
            if (pos >= (int)arr.size() || root->val != arr[pos]) {
                return;
            }
            dfs(root->left, arr, pos+1);
        }
        else {
            if (pos == arr.size()-1 && root->val == arr[pos]) {
                haveAns = true;
            }
            return;
        }
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (!root) {
            return arr.empty();
        }
        haveAns = false;
        dfs(root, arr, 0);
        return haveAns;
    }
};