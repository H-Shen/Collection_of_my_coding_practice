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
    unordered_map<TreeNode*, int> unmap;
    int getHeight(TreeNode* root) {
        if (unmap.find(root) != unmap.end()) return unmap[root];
        if (root->left && root->right) {
            unmap[root] = 1 + max(getHeight(root->left), getHeight(root->right));
        }
        else if (!root->left && root->right) {
            unmap[root] = 1 + getHeight(root->right);
        }
        else if (root->left && !root->right) {
            unmap[root] = 1 + getHeight(root->left);
        }
        else {
            unmap[root] = 0;
        }
        return unmap[root];
    }
    bool f(TreeNode* root) {
        if (!root) return true;
        if (root->left && root->right) {
            return abs(unmap[root->left] - unmap[root->right]) <= 1 && f(root->left) && f(root->right);
        }
        else if (!root->left && root->right) {
            return unmap[root->right] == 0 && f(root->left) && f(root->right);
        }
        else if (root->left && !root->right) {
            return unmap[root->left] == 0 && f(root->left) && f(root->right);
        }
        return true;
    }
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int rootHeight = getHeight(root);
        return f(root);
    }
};