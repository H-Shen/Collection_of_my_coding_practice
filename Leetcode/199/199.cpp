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
    int height = -1;
    vector<vector<int> > vec;
    void dfs(TreeNode* root, int currHeight) {
        if (root) {
            dfs(root->left, currHeight + 1);
            dfs(root->right, currHeight + 1);
        } else {
            height = max(height, currHeight);
        }
    }
    void bfs(TreeNode* root) {
        if (root) {
            queue<pair<TreeNode*, int> > q;
            q.push({root, 0});
            while(!q.empty()) {
                pair<TreeNode*, int> cur = q.front();
                TreeNode* curNode = cur.first;
                int curHeight = cur.second;
                vec.at(curHeight).emplace_back(curNode->val);
                q.pop();
                if (curNode->left) {
                    q.push({curNode->left, curHeight + 1});
                }
                if (curNode->right) {
                    q.push({curNode->right, curHeight + 1});
                }
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        vec.resize(height);
        bfs(root);
        vector<int> result(height);
        for (int i = 0; i < height; ++i) {
            result.at(i) = vec.at(i).back();
        }
        return result;
    }
};