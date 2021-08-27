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
    vector<vector<int> > v;
    int getHeight(TreeNode* root) {
        if (root->left && root->right) {
            return 1 + max(getHeight(root->left), getHeight(root->right));
        }
        else if (root->left && !root->right) {
            return 1 + getHeight(root->left);
        }
        else if (!root->left && root->right) {
            return 1 + getHeight(root->right);
        }
        return 0;
    }
    void bfs(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            TreeNode* node = cur.first;
            v.at(cur.second).emplace_back(node->val);
            if (node->left) {
                q.push({node->left, cur.second + 1});
            }
            if (node->right) {
                q.push({node->right, cur.second + 1});
            }
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        v.resize(getHeight(root) + 1);
        bfs(root);
        vector<double> result(v.size());
        for (size_t i = 0; i != v.size(); ++i) {
            result.at(i) = accumulate(v.at(i).begin(), v.at(i).end(), 0.0) / (int)v.at(i).size();
        }
        return result;
    }
};