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
    unordered_map<TreeNode*, int> dp1, dp2;
    int ans;
    int solve1(TreeNode* node) {
        if (dp1.find(node) != dp1.end()) {
            return dp1[node];
        }
        dp1[node] = node->val;
        if (node->left) {
            dp1[node] = min(dp1[node], solve1(node->left));
        }
        if (node->right) {
            dp1[node] = min(dp1[node], solve1(node->right));
        }
        return dp1[node];
    }
    int solve2(TreeNode* node) {
        if (dp2.find(node) != dp2.end()) {
            return dp2[node];
        }
        dp2[node] = node->val;
        if (node->left) {
            dp2[node] = max(dp2[node], solve2(node->left));
        }
        if (node->right) {
            dp2[node] = max(dp2[node], solve2(node->right));
        }
        return dp2[node];
    }
    void dfs(TreeNode* node) {
        if (node->left) {
            ans = max(ans, abs(solve1(node->left) - node->val));
            ans = max(ans, abs(solve2(node->left) - node->val));
            dfs(node->left);
        }
        if (node->right) {
            ans = max(ans, abs(solve1(node->right) - node->val));
            ans = max(ans, abs(solve2(node->right) - node->val));
            dfs(node->right);
        }
    }
    int maxAncestorDiff(TreeNode* root) {
        dp1.clear();
        dp2.clear();
        ans = numeric_limits<int>::min();
        dfs(root);
        return ans;
    }
};