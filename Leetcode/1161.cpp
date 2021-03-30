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
    int getHeight(TreeNode* root) {
        if (root->left && root->right) {
            return 1+max(getHeight(root->left), getHeight(root->right));
        }
        else if (root->left && !root->right) {
            return 1+getHeight(root->left);
        }
        else if (!root->left && root->right) {
            return 1+getHeight(root->right);
        }
        return 0;
    }
    void bfs(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            vec.at(cur.second) += cur.first->val;
            if (cur.first->left) {
                q.push({cur.first->left, cur.second + 1});
            }
            if (cur.first->right) {
                q.push({cur.first->right, cur.second + 1});
            }
        }
    }
    int maxLevelSum(TreeNode* root) {
        int height = getHeight(root);
        vec.resize(height + 1);
        bfs(root);
        return max_element(vec.begin(), vec.end()) - vec.begin() + 1;
    }
};