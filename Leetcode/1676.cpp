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
    unordered_map<TreeNode*, int> node2dfn;
    unordered_map<TreeNode*, TreeNode*> father;
    int dfn = 0;
    void dfs(TreeNode* root) {
        if (root) {
            node2dfn[root] = dfn;
            ++dfn;
            dfs(root->left);
            dfs(root->right);
        }
    }
    void dfs2(TreeNode* root) {
        if (root->left && root->right) {
            father[root->left] = root;
            father[root->right] = root;
            dfs2(root->left);
            dfs2(root->right);
        }
        else if (root->left && !root->right) {
            father[root->left] = root;
            dfs2(root->left);
        }
        else if (!root->left && root->right) {
            father[root->right] = root;
            dfs2(root->right);
        }
    }
    TreeNode* lca(TreeNode* u, TreeNode* v) {
        if (!u || !v) {
            return nullptr;
        }
        if (u == v) {
            return u;
        }
        unordered_set<TreeNode*> unset;
        auto node(u);
        while (node) {
            unset.insert(node);
            node = father[node];
        }
        node = v;
        while (node) {
            if (unset.find(node) != unset.end()) {
                break;
            }
            node = father[node];
        }
        return node;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        dfs(root);
        dfs2(root);
        if (nodes.empty()) {
            return nullptr;
        }
        else if (nodes.size() == 1) {
            return nodes.front();
        }
        const auto [node1, node2] = minmax_element(nodes.begin(), nodes.end(), [&](const auto &l, const auto &r){
            return node2dfn[l] < node2dfn[r];
        });
        return lca(*node1, *node2);
    }
};