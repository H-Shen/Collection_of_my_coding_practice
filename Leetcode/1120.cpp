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
    unordered_map<TreeNode*,pair<int,int> > dp;
    double ans;
    pair<int,int> solve(TreeNode* u) {  // first: the sum of val; second: the number of nodes
        if (dp.find(u) != dp.end()) {
            return dp[u];
        }
        dp[u] = {u->val,1};
        if (u->left && u->right) {
            auto p1 = solve(u->left);
            auto p2 = solve(u->right);
            dp[u].first += p1.first + p2.first;
            dp[u].second += p1.second + p2.second;
        }
        else if (u->left && !u->right) {
            auto p1 = solve(u->left);
            dp[u].first += p1.first;
            dp[u].second += p1.second;
        }
        else if (!u->left && u->right) {
            auto p1 = solve(u->right);
            dp[u].first += p1.first;
            dp[u].second += p1.second;
        }
        return dp[u];
    }
    int sgn(const double &x) {
        constexpr double EPS = 1e-7;
        if (x > EPS) return 1;
        if (x > -EPS) return 0;
        return -1;
    }
    void dfs(TreeNode* node) {
        if (node) {
            auto p = solve(node);
            double avg = p.first*1.0/p.second;
            if (sgn(avg - ans) > 0) {
                ans = avg;
            }
            dfs(node->left);
            dfs(node->right);
        }
    }
    double maximumAverageSubtree(TreeNode* root) {
        for (auto &[k,v] : dp) {
            delete k;
        }
        dp.clear();
        ans = -1.0;
        dfs(root);
        return ans;
    }
};