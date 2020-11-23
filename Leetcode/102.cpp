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
    int h(TreeNode* root) {
        int height = 0;
        if (root) {
            if (root->left && root->right) {
                height = 1 + max(h(root->left), h(root->right));
            } else if (root->left && !root->right) {
                height = 1 + h(root->left);
            } else if (!root->left && root->right) {
                height = 1 + h(root->right);
            }
        }
        return height;
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) { 
        vector<vector<int> > result;
        if (root) {
            int currentLevel;
            result.resize(h(root) + 1);
            queue<pair<TreeNode*, int> > q;
            q.push({root, 0});
            while (!q.empty()) {
                TreeNode* u = q.front().first;
                currentLevel = q.front().second;
                q.pop();
                result.at(currentLevel).emplace_back(u->val);
                if (u->left) {
                    q.push({u->left, currentLevel + 1});
                }
                if (u->right) {
                    q.push({u->right, currentLevel + 1});
                }
            }
        }
        return result;
    }
};