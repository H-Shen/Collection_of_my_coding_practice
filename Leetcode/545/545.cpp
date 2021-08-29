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
    vector<TreeNode*> leaves;
    // get leaves from left to right by following their dfs rank
    void dfs(TreeNode* root) {
        if (root) {
            if (!root->left && !root->right) {
                leaves.emplace_back(root);
                return;
            }
            if (root->left) {
                dfs(root->left);
            }
            if (root->right) {
                dfs(root->right);
            }
        }
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        // get the left
        vector<TreeNode*> left;
        if (root->left) {
            auto node = root->left;
            while (true) {
                left.emplace_back(node);
                if (node->left) {
                    node = node->left;
                }
                else if (!node->left && node->right) {
                    node = node->right;
                }
                else if (!node->left && !node->right) {
                    break;
                }
            }
        }
        // get leaves
        vector<TreeNode*>().swap(leaves);
        dfs(root);
        // get the right
        vector<TreeNode*> right;
        if (root->right) {
            auto node = root;
            while (true) {
                right.emplace_back(node);
                if (node->right) {
                    node = node->right;
                }
                else if (node->left && !node->right) {
                    node = node->left;
                }
                else if (!node->left && !node->right) {
                    break;
                }
            }
            reverse(right.begin(),right.end());
        }
        unordered_set<TreeNode*> unmap;
        vector<int> ans;
        // add the root
        unmap.insert(root);
        ans.emplace_back(root->val);
        // add the left
        for (const auto &i : left) {
            if (unmap.find(i) == unmap.end()) {
                unmap.insert(i);
                ans.emplace_back(i->val);
            }
        }
        // add leaves
        for (const auto &i : leaves) {
            if (unmap.find(i) == unmap.end()) {
                unmap.insert(i);
                ans.emplace_back(i->val);
            }
        }
        // add the right
        for (const auto &i : right) {
            if (unmap.find(i) == unmap.end()) {
                unmap.insert(i);
                ans.emplace_back(i->val);
            }
        }
        return ans;
    }
};