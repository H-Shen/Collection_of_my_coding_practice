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
    unordered_map<TreeNode*, TreeNode*> father;
    int counter = 0;
    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p) {
            ++counter;
        }
        else if (root == q) {
            ++counter;
        }
        if (root->left && root->right) {
            father[root->left] = root;
            father[root->right] = root;
            dfs(root->left, p, q);
            dfs(root->right, p, q);
        }
        else if (root->left && !root->right) {
            father[root->left] = root;
            dfs(root->left, p, q);
        }
        else if (!root->left && root->right) {
            father[root->right] = root;
            dfs(root->right, p, q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        if (counter != 2) {
            return nullptr;
        }
        unordered_set<TreeNode*> unset;
        auto node = p;
        while (node) {
            unset.insert(node);
            node = father[node];
        }
        node = q;
        while (node) {
            if (unset.find(node) != unset.end()) {
                break;
            }
            node = father[node];
        }
        return node;
    }
};