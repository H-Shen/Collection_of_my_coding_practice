/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution2 {
public:
    unordered_map<int, TreeNode*> val2node;
    unordered_map<int, int> father;
    void dfs_1(TreeNode* current) {
        if (current == nullptr) return;
        val2node[current->val] = current;
        dfs_1(current->left);
        dfs_1(current->right);
    }
    void dfs_2(TreeNode* parent, TreeNode* son) {
        if (son == nullptr) return;
        if (parent) {
            father[son->val] = parent->val;
        }
        dfs_2(son, son->left);
        dfs_2(son, son->right);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs_1(root);
        dfs_2(nullptr, root);
        unordered_set<int> vis;
        TreeNode* pCopy = p;
        while (true) {
            vis.insert(pCopy->val);
            if (pCopy == root) break;
            pCopy = val2node[father[pCopy->val]];
        }
        TreeNode* qCopy = q;
        while (true) {
            if (vis.find(qCopy->val) != vis.end()) {
                return qCopy;
            }
            qCopy = val2node[father[qCopy->val]];
        }
        return nullptr;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p) return p;
        if (root == q) return q;
        TreeNode* lcaOfLeftSubtree = lowestCommonAncestor(root->left, p, q);
        TreeNode* lcaOfRightSubtree = lowestCommonAncestor(root->right, p, q);
        if (lcaOfLeftSubtree && lcaOfRightSubtree) {
            return root;
        }
        return lcaOfLeftSubtree ? lcaOfLeftSubtree : lcaOfRightSubtree;
    }
};