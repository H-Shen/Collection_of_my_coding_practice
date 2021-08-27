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
    int bfs(TreeNode* root) {
        int maxLevel = 0;
        int answer = root->val;
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            if (cur.second > maxLevel) {
                maxLevel = cur.second;
                answer = cur.first->val;
            }
            if (cur.first->left) {
                q.push({cur.first->left, cur.second + 1});
            }
            if (cur.first->right) {
                q.push({cur.first->right, cur.second + 1});
            }
        }
        return answer;
    }
    int findBottomLeftValue(TreeNode* root) {
        return bfs(root);
    }
};