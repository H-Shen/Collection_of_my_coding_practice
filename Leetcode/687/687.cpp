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
    int solve1(TreeNode* u) {
        if (dp1.find(u) != dp1.end()) {
            return dp1[u];
        }
        dp1[u] = 1;
        int left = 0;
        int right = 0;
        if (u->left && u->val == u->left->val) {
            left = solve1(u->left);
        }
        if (u->right && u->val == u->right->val) {
            right = solve1(u->right);
        }
        dp1[u] += max(left, right);
        return dp1[u];
    }
    int solve2(TreeNode* u) {
        if (dp2.find(u) != dp2.end()) {
            return dp2[u];
        }
        dp2[u] = 1;
        if (fa[u] && u->val == fa[u]->val) {
            dp2[u] += solve2(fa[u]);
        }
        return dp2[u];
    }
    
    int ans;
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
            if (u->val == u->left->val) {
                temp1 = solve1(u->left);
            } else {
                temp1 = 0;
            }
            if (u->val == u->right->val) {
                temp2 = solve1(u->right);
            } else {
                temp2 = 0;
            }
            ans = max(ans, max(temp1+temp2+1, max(temp0+temp1,temp0+temp2)));
            dfs2(u->left);
            dfs2(u->right);
        }
        else if (u->left && !u->right) {
            temp0 = solve2(u);
            if (u->val == u->left->val) {
                temp1 = solve1(u->left);
            } else {
                temp1 = 0;
            }
            ans = max(ans, temp0+temp1);
            dfs2(u->left);
        }
        else if (!u->left && u->right) {
            temp0 = solve2(u);
            if (u->val == u->right->val) {
                temp2 = solve1(u->right);
            } else {
                temp2 = 0;
            }
            ans = max(ans, temp0+temp2);
            dfs2(u->right);
        }
        else {
            temp0 = solve2(u);
            ans = max(ans,temp0);
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        if (!root) {
            return 0;
        }
        dp1.clear();
        dp2.clear();
        dfs(root,nullptr);
        ans = -1;
        dfs2(root);
        return ans-1;
    }
};