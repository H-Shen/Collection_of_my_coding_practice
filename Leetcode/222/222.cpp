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
    // O(logn)
    bool search(TreeNode* root, int currId, int targetId) {
        if (!root) return false;
        vector<int> vec;
        while (targetId > 1) {
            vec.emplace_back(targetId % 2);
            targetId /= 2;
        }
        reverse(vec.begin(), vec.end());
        TreeNode* ptr = root;
        for (const auto &i : vec) {
            if (!ptr) {
                return false;
            }
            if (i == 1) {
                if (!ptr->right) {
                    return false;
                }
                ptr = ptr->right;
            }
            else {
                if (!ptr->left) {
                    return false;
                }
                ptr = ptr->left;
            }
        }
        return true;
    }
    // O(logn)
    int getLeftNodeHeight(TreeNode* root, int currHeight) {
        if (root->left) {
            return getLeftNodeHeight(root->left, 1 + currHeight);
        }
        return currHeight;
    }
    // O(log(logn))
    int countNodes(TreeNode* root) {
        if (!root) return 0;        
        int l = getLeftNodeHeight(root, 0);
        int lowerBound = 1 << l;
        int upperBound = (1 << (l + 1)) - 1;
        int mid = -1;
        while (lowerBound <= upperBound) {
            mid = lowerBound + ((upperBound - lowerBound) >> 1);
            bool a = search(root, 1, mid);
            bool b = search(root, 1, mid + 1);
            if (a && b)  {
                lowerBound = mid + 1;
            } else if (!a && !b) {
                upperBound = mid - 1;
            } else {
                break;
            }
        }
        return mid;
    }
};