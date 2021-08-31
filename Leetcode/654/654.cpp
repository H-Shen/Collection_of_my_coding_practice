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


// Even though you could use Sparse Table for maximal range-queries quickly,
// the precomputation still cost O(nlogn)
class Solution {
public:
    TreeNode* createNode(vector<int>& nums, int i, int j) {
        if (i > j) {
            return nullptr;
        }
        auto iter = max_element(nums.begin()+i,nums.begin()+j+1);
        int pos = (int)(iter - nums.begin());
        TreeNode* node = new TreeNode(*iter);
        // divide
        TreeNode* left = createNode(nums, i, pos-1);
        TreeNode* right = createNode(nums, pos+1, j);
        // conquer
        node->left = left;
        node->right = right;
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return createNode(nums, 0, (int)nums.size()-1);
    }
};