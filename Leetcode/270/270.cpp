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
    vector<double> v;
    void midOrder(TreeNode* root) {
        if (root) {
            midOrder(root->left);
            v.emplace_back(root->val);
            midOrder(root->right);
        }
    }
    int closestValue(TreeNode* root, double target) {
        midOrder(root);
        if (target <= v.front()) return v.front();
        else if (target >= v.back()) return v.back();
        auto iter = lower_bound(v.begin(), v.end(), target);
        auto iter2 = iter;
        --iter2;
        double diff1 = abs(*iter - target);
        double diff2 = abs(*iter2 - target);
        if (diff1 < diff2) {
            return *iter;
        }
        return *iter2;
    }
};