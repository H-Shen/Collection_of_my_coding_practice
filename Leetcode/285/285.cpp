/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> v;
    void midOrder(TreeNode* root) {
        if (root) {
            midOrder(root->left);
            v.emplace_back(root);
            midOrder(root->right);
        }
    }
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        midOrder(root);
        auto iter = upper_bound(v.begin(), v.end(), p, [](const TreeNode* l, const TreeNode* r){
            return l->val < r->val;
        });
        if (iter == v.end()) {
            return nullptr;
        }
        return *iter;
    }
};