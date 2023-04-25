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
    int height(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1+max(height(root->left), height(root->right));
    }
    void dfs(TreeNode* root, unordered_map<TreeNode*,int> &brothersValue) {
        if (root->left && root->right) {
            brothersValue[root->left] = root->right->val;
            brothersValue[root->right] = root->left->val;
            dfs(root->left, brothersValue);
            dfs(root->right, brothersValue);
        }
        else if (!root->left && root->right) {
            brothersValue[root->right] = 0;
            dfs(root->right, brothersValue);
        }
        else if (root->left && !root->right) {
            brothersValue[root->left] = 0;
            dfs(root->left, brothersValue);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        // level-order traversal sum[i] = the sum of values in level[i]
        // node->val = sum[i] - node->val - node.bro->val
        // node->val ==> node->val + node.bro.val
        
        // get height
        int h = height(root);
        vector<vector<TreeNode*>> vec(h+1);
        // bfs
        queue<pair<TreeNode*,int>> q;
        q.emplace(root, 0);
        while (!q.empty()) {
            pair<TreeNode*,int> p = q.front();
            q.pop();
            vec[p.second].emplace_back(p.first);
            if (p.first->left) {
                q.emplace(p.first->left, p.second+1);
            }
            if (p.first->right) {
                q.emplace(p.first->right, p.second+1);
            }
        }
        // dfs
        vector<int> sum(h);
        for (int i = 0; i < h; ++i) {
            for (const auto &j : vec[i]) {
                sum[i] += j->val;
            }
        }
        unordered_map<TreeNode*, int> brothersValue;    // 0 means no brothers
        brothersValue[root] = 0;
        dfs(root, brothersValue);
        for (int i = 0; i < h; ++i) {
            for (auto&j : vec[i]) {
                if (brothersValue[j] != 0) {
                    j->val = sum[i] - j->val - brothersValue[j];
                }
                else {
                    j->val = sum[i] - j->val;
                }
            }
        }
        return root;
    }
};