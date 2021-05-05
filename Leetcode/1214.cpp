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
    vector<int> v1;
    unordered_set<int> v2;
    void dfs1(TreeNode* root) {
        if (root) {
            v1.emplace_back(root->val);
            dfs1(root->left);
            dfs1(root->right);
        }
    }
    void dfs2(TreeNode* root) {
        if (root) {
            v2.insert(root->val);
            dfs2(root->left);
            dfs2(root->right);
        }
    }
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        dfs1(root1);
        dfs2(root2);
        for (const auto &i : v1) {
            if (v2.find(target - i) != v2.end()) {
                return true;
            }
        }
        return false;
    }
};