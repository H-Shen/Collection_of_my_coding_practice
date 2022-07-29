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
    unordered_map<TreeNode*, int> dpMax, dpSum, dpMin;
    unordered_map<TreeNode*, bool> isBST;
    int ans;
    int solve(TreeNode* node) {
        auto iter = dpMax.find(node);
        if (iter != dpMax.end()) {
            return iter->second;
        }
        int maxVal = node->val;
        if (node->left) {
            maxVal = max(maxVal, solve(node->left));
        }
        if (node->right) {
            maxVal = max(maxVal, solve(node->right));
        }
        dpMax[node] = maxVal;
        return maxVal;
    }
    int solve2(TreeNode* node) {
        auto iter = dpMin.find(node);
        if (iter != dpMin.end()) {
            return iter->second;
        }
        int minVal = node->val;
        if (node->left) {
            minVal = min(minVal, solve2(node->left));
        }
        if (node->right) {
            minVal = min(minVal, solve2(node->right));
        }
        dpMin[node] = minVal;
        return minVal;
    }
    bool solve3(TreeNode* node) {
        auto iter = isBST.find(node);
        if (iter != isBST.end()) {
            return iter->second;
        }
        if (node->left && node->right) {
            if (node->val > solve(node->left) && node->val < solve2(node->right) && solve3(node->left) && solve3(node->right)) {
                isBST[node] = true;
                return true;
            }
            else {
                isBST[node] = false;
                return false;
            }
        }
        else if (!node->left && node->right) {
            if (node->val < solve2(node->right) && solve3(node->right)) {
                isBST[node] = true;
                return true;
            }
            else {
                isBST[node] = false;
                return false;
            }
        }
        else if (node->left && !node->right) {
            if (node->val > solve(node->left) && solve3(node->left)) {
                isBST[node] = true;
                return true;
            }
            else {
                isBST[node] = false;
                return false;
            }
        }
        else {
            isBST[node] = true;
            return true;
        }
    }
    
    int solve4(TreeNode* node) {
        auto iter = dpSum.find(node);
        if (iter != dpSum.end()) {
            return iter->second;
        }
        int sum = node->val;
        if (node->left) {
            sum += solve4(node->left);
        }
        if (node->right) {
            sum += solve4(node->right);
        }
        dpSum[node] = sum;
        return sum;
    }
    void dfs(TreeNode* node) {
        if (node) {
            if (solve3(node)) {
                ans = max(ans, solve4(node));
            }
            dfs(node->left);
            dfs(node->right);
        }
    }
    int maxSumBST(TreeNode* root) {
        dpMax.clear();
        dpMin.clear();
        isBST.clear();
        dpSum.clear();
        ans = 0;
        dfs(root);
        return ans;
    }
};