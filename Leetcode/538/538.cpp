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
    vector<int> vec, sumFromRight;
    void dfs(TreeNode* u) {
        if (u) {
            dfs(u->left);
            vec.emplace_back(u->val);
            dfs(u->right);
        }
    }
    void dfs2(TreeNode* u) {
        if (u) {
            size_t pos = lower_bound(vec.begin(),vec.end(),u->val) - vec.begin();
            if (pos != vec.size()-1) {
                u->val += sumFromRight[pos+1];
            }
            dfs2(u->left);
            dfs2(u->right);
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        vector<int>().swap(vec);
        vector<int>().swap(sumFromRight);
        dfs(root);
        int n = (int)vec.size();
        sumFromRight.resize(n);
        sumFromRight[n-1] = vec[n-1];
        for (int i = n-2; i >= 0; --i) {
            sumFromRight[i] = sumFromRight[i+1] + vec[i];
        }
        dfs2(root);
        return root;
    }
};