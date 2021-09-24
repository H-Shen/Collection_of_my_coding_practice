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
    void dfs(TreeNode* u) {
        if (u) {
            dfs(u->left);
            vec.emplace_back(u->val);
            dfs(u->right);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        vector<int>().swap(vec);
        dfs(root);
        int n = (int)vec.size();
        vector<int> sumFromRight(n);
        sumFromRight[n-1] = vec[n-1];
        for (int i = n-2; i >= 0; --i) {
            sumFromRight[i] = sumFromRight[i+1] + vec[i];
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* node;
        size_t pos;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            pos = lower_bound(vec.begin(),vec.end(),node->val)-vec.begin();
            if (pos != vec.size()-1) {
                node->val += sumFromRight[pos+1];
            }
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        return root;
    }
};