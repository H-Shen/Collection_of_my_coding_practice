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
    unordered_map<TreeNode*, int> dp;
    unordered_map<int, int> freq;
    int solve(TreeNode* root) {
        if (dp.find(root) != dp.end()) {
            return dp[root];
        }
        if (root->left && root->right) {
            dp[root] = root->val + solve(root->left) + solve(root->right);
        }
        else if (root->left && !root->right) {
            dp[root] = root->val + solve(root->left);
        }
        else if (!root->left && root->right) {
            dp[root] = root->val + solve(root->right);
        }
        else {
            dp[root] = root->val;
        }
        return dp[root];
    }
    void dfs(TreeNode* root) {
        if (root) {
            ++freq[solve(root)];
            dfs(root->left);
            dfs(root->right);
        }
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> result;
        int maxFreq = -1;
        for (const auto &[k, v] : freq) {
            maxFreq = max(maxFreq, v);
        }
        for (const auto &[k, v] : freq) {
            if (v == maxFreq) {
                result.emplace_back(k);
            }
        }
        return result;
    }
};