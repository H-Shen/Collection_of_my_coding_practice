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
class Solution2 {
public:
    vector<int> vec;
    bool notUnique = false;
    void f(TreeNode* root) {
        if (root) {
            f(root->left);
            if (!vec.empty() && vec.back() == root->val) {
                notUnique = true;
                return;
            }
            vec.emplace_back(root->val);
            f(root->right);
        }
    }
    bool isValidBST(TreeNode* root) {
        f(root);
        if (notUnique) return false;
        return is_sorted(vec.begin(), vec.end());
    }
};

class Solution {
public:
    using ll = long long;
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