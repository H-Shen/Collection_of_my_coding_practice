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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
            return root;
        } 
        TreeNode* target = root;
        TreeNode* father = nullptr;
        bool found = false;
        bool leftChild;
        while (true) {
            if (target->val == key) {
                found = true;
                break;
            }
            else if (target->val < key) {
                if (target->right) {
                    father = target;
                    leftChild = false;
                    target = target->right;
                }
                else {
                    break;
                }
            }
            else {
                if (target->left) {
                    father = target;
                    leftChild = true;
                    target = target->left;
                }
                else {
                    break;
                }
            }
        }
        if (!found) {
            return root;
        }
        if (target->left && target->right) {
            TreeNode* temp = target->right;
            TreeNode* tempFather = target;
            // find post node
            while (true) {
                if (temp->left) {
                    tempFather = temp;
                    temp = temp->left;
                }
                else {
                    break;
                }
            }
            target->val = temp->val;
            if (tempFather->left->val == temp->val) {
                tempFather->left = temp->right;
            }
            else {
                tempFather->right = temp->right;
            }
        }
        else if (target->left && !target->right) {
            if (father) {
                if (leftChild) {
                    father->left = target->left;
                }
                else {
                    father->right = target->left;
                }
            }
            else {
                root = target->left;
            }
        }
        else if (!target->left && target->right) {
            if (father) {
                if (leftChild) {
                    father->left = target->right;
                }
                else {
                    father->right = target->right;
                }
            }
            else {
                root = target->right;
            }
        }
        else {
            if (father) {
                if (leftChild) {
                    father->left = nullptr;
                }
                else {
                    father->right = nullptr;
                }
            }
            else {
                root = nullptr;
            }
        }
        return root;
    }
};