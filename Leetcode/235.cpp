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
    int MAXN = 1e5 + 5;
    unordered_set<int> vis;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* rootCopy(root);
        while (true) {
            vis.insert(rootCopy->val);
            if (p->val < rootCopy->val) {
                rootCopy = rootCopy->left;
            } else if (p->val > rootCopy->val) {
                rootCopy = rootCopy->right;
            } else {
                break;
            }
        }
        rootCopy = root;
        vector<TreeNode* > temp;
        while (true) {
            temp.emplace_back(rootCopy);
            if (q->val < rootCopy->val) {
                rootCopy = rootCopy->left;
            } else if (q->val > rootCopy->val) {
                rootCopy = rootCopy->right;
            } else {
                break;
            }
        }
        for (auto iter = temp.rbegin(); iter != temp.rend(); ++iter) {
            if (vis.find((*iter)->val) != vis.end()) {
                return *iter;
            }
        }
        return nullptr;
    }
};