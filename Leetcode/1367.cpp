/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool hasAns = false;
    void check(TreeNode* root, int pos) {
        if (pos >= (int)vec.size()) {
            hasAns = true;
            return;
        }
        if (!root) {
            return;
        }
        if (root->val != vec[pos]) {
            return;
        }
        check(root->left, pos+1);
        check(root->right, pos+1);
    }
    void dfs(TreeNode* root) {
        if (hasAns) {
            return;
        }
        if (root) {
            check(root, 0);
            dfs(root->left);
            dfs(root->right);
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        auto node(head);
        while (node) {
            vec.emplace_back(node->val);
            node = node->next;
        }
        dfs(root);
        return hasAns;
    }
};