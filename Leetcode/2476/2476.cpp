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
    vector<int> vec;
    void dfs(TreeNode* node) {
        if (node) {
            dfs(node->left);
            vec.emplace_back(node->val);
            dfs(node->right);
        }
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int>().swap(vec);
        dfs(root);
        vector<vector<int>> ans;
        for (auto&i : queries) {
            vector<int> temp;
            if (i < vec.front()) {
                temp.emplace_back(-1);
            } else {
                auto it = upper_bound(vec.begin(),vec.end(),i);
                --it;
                temp.emplace_back(*it);
            }
            if (i > vec.back()) {
                temp.emplace_back(-1);
            } else {
                auto it = lower_bound(vec.begin(),vec.end(),i);
                temp.emplace_back(*it);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};