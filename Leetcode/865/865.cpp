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

constexpr int MAXN = 505;
class Solution {
public:
    int dfn[MAXN]{};
    int height[MAXN]{};
    TreeNode* nodes[MAXN]{};
    int father[MAXN]{};
    void dfs(TreeNode* root) {
        nodes[root->val] = root;
        if (root->left && root->right) {
            dfs(root->left);
            dfs(root->right);
        }
        else if (root->left && !root->right) {
            dfs(root->left);
        }
        else if (!root->left && root->right) {
            dfs(root->right);
        }
    }
    void dfs2(TreeNode* root, TreeNode* fa) {
        if (fa) {
            father[root->val] = fa->val;
        } else {
            father[root->val] = -1;
        }
        if (root->left && root->right) {
            dfs2(root->left, root);
            dfs2(root->right, root);
        }
        else if (root->left && !root->right) {
            dfs2(root->left, root);
        }
        else if (!root->left && root->right) {
            dfs2(root->right, root);
        }
    }
    void getHeight(TreeNode* root, int curHeight) {
        height[root->val] = curHeight;
        if (root->left && root->right) {
            getHeight(root->left, curHeight + 1);
            getHeight(root->right, curHeight + 1);
        }
        else if (root->left && !root->right) {
            getHeight(root->left, curHeight + 1);
        }
        else if (!root->left && root->right) {
            getHeight(root->right, curHeight + 1);
        }
    }
    int dfsRank = 0;
    void getDfsRank(TreeNode* root) {
        dfn[root->val] = dfsRank;
        ++dfsRank;
        if (root->left && root->right) {
            getDfsRank(root->left);
            getDfsRank(root->right);
        }
        else if (root->left && !root->right) {
            getDfsRank(root->left);
        }
        else if (!root->left && root->right) {
            getDfsRank(root->right);
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;
        dfs(root);
        dfs2(root, nullptr);
        getHeight(root, 0);
        getDfsRank(root);
        int maxHeight = 0;
        for (const auto &i : nodes) {
            if (i) {
                maxHeight = max(maxHeight, height[i->val]);
            }
        }
        int maxDfn = -1;
        int minDfn = MAXN;
        for (const auto &i : nodes) {
            if (i && height[i->val] == maxHeight) {
                maxDfn = max(maxDfn, dfn[i->val]);
                minDfn = min(minDfn, dfn[i->val]);
            }
        }
        int node1, node2;
        for (const auto &i : nodes) {
            if (i) {
                if (dfn[i->val] == maxDfn) {
                    node1 = i->val;
                }
                if (dfn[i->val] == minDfn) {
                    node2 = i->val;
                }
            }
        }
        while (node1 != node2) {
            node1 = father[node1];
            node2 = father[node2];
        }
        return nodes[node1];
    }
};