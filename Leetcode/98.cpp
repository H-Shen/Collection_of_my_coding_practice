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

class Solution {
public:
    bool f(TreeNode* root, ll lowerbound, ll upperbound) {
        if (root) {
            if (!(root->val > lowerbound && root->val < upperbound)) {
                return false;
            }
            return f(root->left, lowerbound, root->val) && f(root->right, root->val, upperbound);
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return f(root, numeric_limits<ll>::min(), numeric_limits<ll>::max());
    }
};