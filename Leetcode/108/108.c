/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* solve(int* nums, int l, int r) {
    if (l > r) {
        return NULL;
    }
    int mid = l + ((r-l)>>1);
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode)*1);
    node->val = nums[mid];
    if (l < mid && mid < r) {
        node->left = solve(nums, l, mid-1);
        node->right = solve(nums, mid+1, r);
    }
    else if (l == mid && mid < r) {
        node->left = NULL;
        node->right = solve(nums, mid+1, r);
    }
    else if (l < mid && mid == r) {
        node->left = solve(nums, l, mid-1);
        node->right = NULL;
    }
    else {
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return solve(nums, 0, numsSize-1);
}