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
    vector<int> result;
    int last = -1;
    int curr;
    int val;
    int freq = -1;
    // get max freq
    void dfs1(TreeNode* root) {
        if (root) {
            dfs1(root->left);
            if (last == -1) {
                val = root->val;
                last = 0;
                curr = 0;
            } else {
                if (root->val != val) {
                    freq = max(freq, curr - last + 1);
                    val = root->val;
                    last = 0;
                    curr = 0;
                } else {
                    ++curr;
                }
            }
            dfs1(root->right);
        }
    }
    void dfs2(TreeNode* root) {
        if (root) {
            dfs2(root->left);
            if (last == -1) {
                val = root->val;
                last = 0;
                curr = 0;
            }
            else {
                if (root->val != val) {
                    if (curr - last + 1 == freq) {
                        result.emplace_back(val);
                    }
                    val = root->val;
                    last = 0;
                    curr = 0;
                }
                else {
                    ++curr;
                }
            }
            dfs2(root->right);
        }
    }
    vector<int> findMode(TreeNode* root) {
        if (!root) {
            return result;
        }
        dfs1(root);
        freq = max(freq, curr - last + 1);
        last = -1;
        dfs2(root);
        if (curr - last + 1 == freq) {
            result.emplace_back(val);
        }
        return result;
    }
};