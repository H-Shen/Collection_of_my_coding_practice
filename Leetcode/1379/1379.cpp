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
    int target_dfn;
    int cur_dfn;
    TreeNode* answer = nullptr;
    void dfs1(TreeNode* root, TreeNode* target) {
        if (root) {
            if (root == target) {
                target_dfn = cur_dfn;
            }
            ++cur_dfn;
            dfs1(root->left, target);
            dfs1(root->right, target);
        }
    }
    void dfs2(TreeNode* root) {
        if (root) {
            if (target_dfn == cur_dfn) {
                answer = root;
            }
            ++cur_dfn;
            dfs2(root->left);
            dfs2(root->right);
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        cur_dfn = 0;
        dfs1(original, target);
        cur_dfn = 0;
        dfs2(cloned);
        return answer;
    }
};