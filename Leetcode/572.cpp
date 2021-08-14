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
    unordered_map<TreeNode*,int> nodeSize;
    int getSize(TreeNode* node) {
        if (!node) {
            return 0;
        }
        if (nodeSize.find(node) != nodeSize.end()) {
            return nodeSize[node];
        }
        int ans = 1+getSize(node->left)+getSize(node->right);
        nodeSize[node] = ans;
        return ans;
    }
    bool isSameTree(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        if ((!l && r) || (l && !r)) return false;
        return l->val == r->val && isSameTree(l->left,r->left) && isSameTree(l->right,r->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // use height to prune
        int subRootSize = getSize(subRoot);
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (getSize(node) == subRootSize && isSameTree(node, subRoot)) return true;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return false;
    }
};