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
    unordered_map<int,int> val2pos;
    TreeNode* build(const vector<int> &preorder, int preorder_l, int preorder_r, const vector<int> &inorder, int inorder_l, int inorder_r) {
        if (preorder_l > preorder_r) {
            return nullptr;
        }
        int posOfRoot = val2pos[preorder[preorder_l]];
        auto root = new TreeNode(preorder[preorder_l]);
        int sizeOfLeftSubtree = posOfRoot - inorder_l;
        root->left = build(preorder, preorder_l+1, preorder_l+sizeOfLeftSubtree, inorder, inorder_l, posOfRoot-1);
        root->right = build(preorder, preorder_l+sizeOfLeftSubtree+1, preorder_r, inorder, posOfRoot+1, inorder_r);
        return root;
    } 
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        val2pos.clear();
        int n = (int)inorder.size();
        for (int i = 0; i < n; ++i) {
            val2pos[inorder[i]] = i;
        }
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }
};