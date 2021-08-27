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
    unordered_map<TreeNode*, unordered_set<TreeNode*> > AL;
    void dfs(TreeNode* root) {
        if (root->left && root->right) {
            AL[root].insert(root->left);
            AL[root].insert(root->right);
            dfs(root->left);
            dfs(root->right);
        }
        else if (root->left && !root->right) {
            AL[root].insert(root->left);
            dfs(root->left);
        }
        else if (!root->left && root->right) {
            AL[root].insert(root->right);
            dfs(root->right);
        }
        else {
            AL[root];
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        vector<vector<int> > result;
        while (!AL.empty()) {
            vector<TreeNode*> temp;
            for (const auto &[k, v] : AL) {
                if (v.empty()) {
                    temp.emplace_back(k);
                }
            }
            for (const auto &i : temp) {
                AL.erase(i);
            }
            for (auto &[k, v] : AL) {
                for (const auto &i : temp) {
                    v.erase(i);
                }
            }
            vector<int> vec;
            for (const auto &i : temp) {
                vec.emplace_back(i->val);
            }
            result.emplace_back(vec);
        }
        return result;
    }
};