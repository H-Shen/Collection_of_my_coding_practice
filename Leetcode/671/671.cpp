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
    int smallest = numeric_limits<int>::max();
    int second_smallest = -1;
    bool first = true;
    void dfs1(TreeNode* root) {
        if (root) {
            dfs1(root->left);
            smallest = min(smallest, root->val);
            dfs1(root->right);
        }
    }
    void dfs2(TreeNode* root) {
        if (root) {
            dfs2(root->left);
            if (root->val > smallest) {
                if (first) {
                    first = false;
                    second_smallest = root->val;
                } else {
                    second_smallest = min(second_smallest, root->val);
                }
            }
            dfs2(root->right);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        dfs1(root);
        dfs2(root);
        return second_smallest;
    }
};