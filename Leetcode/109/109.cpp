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
    TreeNode* solve(vector<int>& nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int mid = l + ((r-l)>>1);
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = solve(nums, l, mid-1);
        node->right = solve(nums, mid+1, r);
        return node;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        auto node = head;
        while (node) {
            nums.emplace_back(node->val);
            node = node->next;
        }
        return solve(nums, 0, (int)nums.size()-1);
    }
};