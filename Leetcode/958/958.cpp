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
constexpr int MAXLEVEL = 10;

class Solution {
public:
    int height;
    void dfs(TreeNode* root, int currHeight) {
        if (root) {
            height = max(height, currHeight);
            dfs(root->left, currHeight+1);
            dfs(root->right, currHeight+1);
        }
    }
    bool isCompleteTree(TreeNode* root) {
        height = 0;
        dfs(root, height);
        vector<vector<TreeNode*>> vec(height+1);
        queue<pair<TreeNode*,int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int currentHeight = q.front().second;
            // prune:
            if (currentHeight > MAXLEVEL) {
                return false;
            }
            q.pop();
            vec[currentHeight].emplace_back(node);
            if (node->left) {
                q.push({node->left, currentHeight+1});
            }
            if (node->right) {
                q.push({node->right, currentHeight+1});
            }
        }
        for (int i = 0; i < height+1; ++i) {
            if (i != height) {
                // the number of nodes in the level of non-leaves == 2^i
                if (vec[i].size() != 1<<i) {
                    return false;
                }
            }       
        }
        // corner case: root only
        if (height == 0) {
            return true;
        }
        // check the level above leaves
        int length = (int)vec[vec.size()-2].size();
        int leaves = (int)vec[vec.size()-1].size();
        int leafCounter = 0;
        for (int i = 0; i < length; ++i) {
            if (vec[vec.size()-2][i]->left && vec[vec.size()-2][i]->right) {
                leafCounter += 2;
            }
            else if (vec[vec.size()-2][i]->left && !vec[vec.size()-2][i]->right) {
                leafCounter += 1;
                if (leafCounter != leaves) {
                    return false;
                }
            }
            else if (!vec[vec.size()-2][i]->left && vec[vec.size()-2][i]->right) {
                return false;
            }
            else {
                if (leafCounter != leaves) {
                    return false;
                }
            }
        }
        return true;
    }
};