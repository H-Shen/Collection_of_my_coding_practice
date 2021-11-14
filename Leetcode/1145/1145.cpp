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

constexpr int MAXN = 105;

class Solution {
public:
    TreeNode* val2node[MAXN];    
    unordered_map<TreeNode*,int> dp;
    int tol;
    int solve(TreeNode* node) {
        if (dp.find(node) != dp.end()) {
            return dp[node];
        }
        dp[node] = 1;
        if (node->left) {
            dp[node] += solve(node->left);
        }
        if (node->right) {
            dp[node] += solve(node->right);
        }
        return dp[node];
    }
    void dfs(TreeNode* node) {
        if (node) {
            val2node[node->val] = node;
            ++tol;
            dfs(node->left);
            dfs(node->right);
        }
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        memset(val2node, 0, sizeof val2node);
        dp.clear();
        tol = 0;
        dfs(root);
        TreeNode* node = val2node[x];
        int xSize, ySize;
        // choose y as x's left
        if (node->left) {
            ySize = solve(node->left);
            xSize = tol - ySize;
            if (ySize > xSize) return true;
        }
        // choose y as x's right
        if (node->right) {
            ySize = solve(node->right);
            xSize = tol - ySize;
            if (ySize > xSize) return true;
        }
        // choose y as x's father
        if (x != root->val) {
            ySize = tol - solve(node);
            xSize = solve(node);
            if (ySize > xSize) return true;
        }
        return false;
    }
};