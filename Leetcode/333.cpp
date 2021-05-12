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
    // dp by memo
    unordered_map<TreeNode*, int> treeSize, maxValue, minValue;
    unordered_map<TreeNode*, bool> isBST;
    int ans = 0;
    int solve1(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (treeSize.find(root) != treeSize.end()) {
            return treeSize[root];
        }
        treeSize[root] = 1 + solve1(root->left) + solve1(root->right);
        return treeSize[root];
    }
    int solve2(TreeNode* root) {
        if (maxValue.find(root) != maxValue.end()) {
            return maxValue[root];
        }
        if (root->left && root->right) {
            maxValue[root] = max(root->val, max(solve2(root->left), solve2(root->right)));
        }
        else if (root->left && !root->right) {
            maxValue[root] = max(root->val, solve2(root->left));
        }
        else if (!root->left && root->right) {
            maxValue[root] = max(root->val, solve2(root->right));
        }
        else {
            maxValue[root] = root->val;
        }
        return maxValue[root];
    }
    int solve3(TreeNode* root) {
        if (minValue.find(root) != minValue.end()) {
            return minValue[root];
        }
        if (root->left && root->right) {
            minValue[root] = min(root->val, min(solve3(root->left), solve3(root->right)));
        }
        else if (root->left && !root->right) {
            minValue[root] = min(root->val, solve3(root->left));
        }
        else if (!root->left && root->right) {
            minValue[root] = min(root->val, solve3(root->right));
        }
        else {
            minValue[root] = root->val;
        }
        return minValue[root];
    }
    
    bool solve4(TreeNode* root) {
        if (isBST.find(root) != isBST.end()) {
            return isBST[root];
        }
        
        if (root->left && root->right) {
            isBST[root] = root->val > solve2(root->left) && root->val < solve3(root->right) && solve4(root->left) && solve4(root->right);
        }
        else if (root->left && !root->right) {
            isBST[root] = root->val > solve2(root->left) && solve4(root->left);
        }
        else if (!root->left && root->right) {
            isBST[root] = root->val < solve3(root->right) && solve4(root->right);
        }
        else {
            isBST[root] = true;
        }
        return isBST[root];
    }
    void dfs(TreeNode* root) {
        if (root) {
            if (solve4(root)) {
                ans = max(ans, solve1(root));
            }
            dfs(root->left);
            dfs(root->right);
        }
    }
    int largestBSTSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        dfs(root);
        return ans;
    }
};