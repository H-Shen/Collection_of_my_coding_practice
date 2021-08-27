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
    unordered_map<TreeNode*, int> d1, d2;
    void dfs(TreeNode* root) {
        constexpr int WEIGHT = 1;
        d1[root] = 0;
        d2[root] = 0;
        if (root->left && root->right) {
            dfs(root->left);
            int temp = d1[root->left] + WEIGHT;
            // d1[root->left] + WEIGHT > d1[root] => update d1[root], d2[root]
            if (temp > d1[root]) {
                d2[root] = d1[root];
                d1[root] = temp;
            }
            // d1[root->left] + WEIGHT > d2[root] => update d2[root] only
            else if (temp > d2[root]) {
                d2[root] = temp;
            }
            // Perform the same operations to root->right
            dfs(root->right);
            temp = d1[root->right] + WEIGHT;
            if (temp > d1[root]) {
                d2[root] = d1[root];
                d1[root] = temp;
            }
            else if (temp > d2[root]) {
                d2[root] = temp;
            }
        }
        else if (root->left && !root->right) {
            dfs(root->left);
            int temp = d1[root->left] + WEIGHT;
            if (temp > d1[root]) {
                d2[root] = d1[root];
                d1[root] = temp;
            }
            else if (temp > d2[root]) {
                d2[root] = temp;
            }
        }
        else if (!root->left && root->right) {
            dfs(root->right);
            int temp = d1[root->right] + WEIGHT;
            if (temp > d1[root]) {
                d2[root] = d1[root];
                d1[root] = temp;
            }
            else if (temp > d2[root]) {
                d2[root] = temp;
            }
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        int diameter = 0;
        for (const auto &[k, v] : d1) {
            diameter = max(diameter, v + d2[k]);
        }
        return diameter;
    }
};