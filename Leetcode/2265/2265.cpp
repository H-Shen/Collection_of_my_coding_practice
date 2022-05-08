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

unordered_map<TreeNode*, int> dpSize, dpSum;

int dp1(TreeNode* root) {
    if (dpSize.count(root) > 0) {
        return dpSize[root];
    }
    dpSize[root] = 1;
    if (root->left) {
        dpSize[root] += dp1(root->left); 
    }
    if (root->right) {
        dpSize[root] += dp1(root->right);
    }
    return dpSize[root];
}

int dp2(TreeNode* root) {
    if (dpSum.count(root) > 0) {
        return dpSum[root];
    }
    dpSum[root] = root->val;
    if (root->left) {
        dpSum[root] += dp2(root->left);
    }
    if (root->right) {
        dpSum[root] += dp2(root->right);
    }
    return dpSum[root];
}

int n;

void dfs(TreeNode* root) {
    if (root) {
        if (dp2(root) / dp1(root) == root->val) {
            ++n;
        }
        dfs(root->left);
        dfs(root->right);
    }
}

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        dpSize.clear();
        dpSum.clear();
        n = 0;
        dfs(root);
        return n;
    }
};