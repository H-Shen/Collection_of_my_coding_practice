/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int max_width = 0;
        if (!root) {
            return max_width;
        }
        deque<TreeNode*> dq;
        TreeNode* node = nullptr;
        dq.push_back(root);
        while (!dq.empty()) {
            while (!dq.empty() && !dq.front()) {
                dq.pop_front();
            }
            while (!dq.empty() && !dq.back()) {
                dq.pop_back();
            }
            if (dq.empty()) {
                break;
            }
            int n = static_cast<int>(dq.size());
            max_width = max(max_width, n);
            for (int i = 0; i < n; ++i) {
                node = dq.front();
                dq.pop_front();
                if (node) {
                    dq.push_back(node->left);
                } else {
                    dq.push_back(nullptr);
                }
                if (node) {
                    dq.push_back(node->right);
                } else {
                    dq.push_back(nullptr);
                }
            }
        }
        return max_width;
    }
};