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
    unordered_map<TreeNode*, int> node2sum;
    int tilt = 0;
    int dfs1(TreeNode* root) {
        if (root->left && root->right) {
            node2sum[root] = root->val + dfs1(root->left) + dfs1(root->right);
        }
        else if (!root->left && root->right) {
            node2sum[root] = root->val + dfs1(root->right);
        }
        else if (root->left && !root->right) {
            node2sum[root] = root->val + dfs1(root->left);
        }
        else {
            node2sum[root] = root->val;
        }
        return node2sum[root];
    }
    void dfs2(TreeNode* root) {
        if (root->left && root->right) {
            tilt += abs(node2sum[root->left] - node2sum[root->right]);
            dfs2(root->left);
            dfs2(root->right);
        }
        else if (!root->left && root->right) {
            tilt += abs(node2sum[root->right]);
            dfs2(root->right);
        }
        else if (root->left && !root->right) {
            tilt += abs(node2sum[root->left]);
            dfs2(root->left);
        }
    }
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        int rootSum = dfs1(root);
        dfs2(root);
        return tilt;
    }
};