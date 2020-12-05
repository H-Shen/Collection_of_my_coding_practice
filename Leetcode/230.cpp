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
    int counter, k, answer;
    bool stopRecursion;
    void f(TreeNode* root) {
        if (!stopRecursion && root) {
            f(root->left);
            ++counter;
            if (counter == k) {
                answer = root->val;
                stopRecursion = true;
                return;
            }
            f(root->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        this->counter = 0;
        this->stopRecursion = false;
        f(root);
        return this->answer;
    }
};