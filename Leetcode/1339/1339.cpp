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
using ll = long long;
constexpr ll MOD = 1e9+7;

class Solution {
public:
    unordered_map<TreeNode*, int> dp; // dp[u] = the sum of the subtree with u as root
    int solve(TreeNode* u) {
        if (dp.find(u) != dp.end()) {
            return dp[u];
        }
        if (u->left && u->right) {
            dp[u] = u->val + solve(u->left) + solve(u->right);
        }
        else if (u->left && !u->right) {
            dp[u] = u->val + solve(u->left);
        }
        else if (!u->left && u->right) {
            dp[u] = u->val + solve(u->right);
        }
        else {
            dp[u] = u->val;
        }
        return dp[u];
    }
    ll ans;
    ll sum;
    void dfs(TreeNode* u) {
        if (u) {
            ll temp = solve(u);
            ll res = temp * (sum - temp);
            ans = max(ans, res);
            dfs(u->left);
            dfs(u->right);
        }
    }
    int maxProduct(TreeNode* root) {
        ans = -1;
        sum = solve(root);
        dfs(root);
        return (int)(ans % MOD);
    }
};