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
    unordered_map<TreeNode*,TreeNode*> fa;
    int ans;
    int solve1(TreeNode* u) {
        if (dp1.find(u) != dp1.end()) {
            return dp1[u];
        }
        dp1[u] = u->val;
        int left = 0;
        int right = 0;
        if (u->left) {
            left = max(left,solve1(u->left));
        }
        if (u->right) {
            right = max(right,solve1(u->right));
        }
        dp1[u] += max(left, right);
        return dp1[u];
    }
    int solve2(TreeNode* u) {
        if (dp2.find(u) != dp2.end()) {
            return dp2[u];
        }
        if (fa[u]) {
            dp2[u] = max(u->val, u->val + solve2(fa[u]));
        }
        else {
            dp2[u] = u->val;
        }
        return dp2[u];
    }
    
    void dfs(TreeNode* u, TreeNode* fa_of_u) {
        if (u) {
            fa[u] = fa_of_u;
            dfs(u->left, u);
            dfs(u->right, u);
        }
    }
    void dfs2(TreeNode* u) {
        int temp0, temp1, temp2;
        if (u->left && u->right) {
            temp0 = solve2(u);
            temp1 = max(0,solve1(u->left));
            temp2 = max(0,solve1(u->right));
            ans = max(ans, max(temp1+temp2+u->val,max(temp0+temp1,temp0+temp2)));
            dfs2(u->left);
            dfs2(u->right);
        }
        else if (u->left && !u->right) {
            temp0 = solve2(u);
            temp1 = max(0,solve1(u->left));
            ans = max(ans, temp0+temp1);
            dfs2(u->left);
        }
        else if (!u->left && u->right) {
            temp0 = solve2(u);
            temp2 = max(0,solve1(u->right));
            ans = max(ans, temp0+temp2);
            dfs2(u->right);
        }
        else {
            ans = max(ans, solve2(u));
        }
    }
    int maxPathSum(TreeNode* root) {
        dp1.clear();
        dp2.clear();
        fa.clear();
        dfs(root,nullptr);
        ans = numeric_limits<int>::min();
        dfs2(root);
        return ans;
    }
};