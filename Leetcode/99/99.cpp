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
    // O(n) space
    vector<TreeNode*> vec;
    void dfs(TreeNode* node) {
        if (node) {
            dfs(node->left);
            vec.emplace_back(node);
            dfs(node->right);
        }
    }
    void recoverTree(TreeNode* root) {
        decltype(vec)().swap(vec);
        dfs(root);
        vector<TreeNode*> vecSorted(vec);
        sort(vecSorted.begin(),vecSorted.end(),[](const TreeNode* l, const TreeNode* r) {
            return l->val < r->val;
        });
        TreeNode* node1 = nullptr;
        TreeNode* node2 = nullptr;
        for (size_t i = 0; i != vec.size(); ++i) {
            if (vecSorted[i] != vec[i]) {
                if (!node1) {
                    node1 = vec[i];
                } else if (!node2) {
                    node2 = vec[i];
                }
            }
        }
        swap(node1->val, node2->val);
    }
};