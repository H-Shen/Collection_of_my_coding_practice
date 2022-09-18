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
    int dfs(TreeNode* node) {
        if (node) {
            return 1+dfs(node->left);
        }
        return 0;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        // bfs
        int height = dfs(root);
        vector<vector<TreeNode*>> levels(height);
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            levels[u.second].emplace_back(u.first);
            if ((u.first)->left) {
                q.push({(u.first)->left, u.second+1});
                q.push({(u.first)->right, u.second+1});
            }
        }
        // reverse node values at each odd level
        int length;
        for (int i = 1; i < height; i+=2) {
            length = (int)levels[i].size();
            for (int j = 0, k = length-1; j < k; ++j, --k) {
                swap(levels[i][j]->val, levels[i][k]->val);
            }
        }
        return root;
    }
};