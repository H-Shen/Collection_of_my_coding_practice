/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool treeSymmetricCheck(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p) {
        return false;
    }
    if (!q) {
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    return treeSymmetricCheck(p->left, q->right) && treeSymmetricCheck(p->right, q->left);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return (root) ? treeSymmetricCheck(root, root) : true;
    }
};
