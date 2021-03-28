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
    vector<vector<int> > vec;
    int getHeight(TreeNode* root) {
        if (root->left && root->right) {
            return 1 + max(getHeight(root->left), getHeight(root->right));
        }
        else if (root->left && !root->right) {
            return 1 + getHeight(root->left);
        }
        else if (!root->left && root->right) {
            return 1 + getHeight(root->right);
        }
        return 0;
    }
    void bfs(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            vec.at(cur.second).emplace_back(cur.first->val);
            if (cur.first->left) {
                q.push({cur.first->left, cur.second + 1});
            }
            if (cur.first->right) {
                q.push({cur.first->right, cur.second + 1});
            }
        }
    }
    bool isStrictlyIncreasing(const vector<int> &A) {
        if (A.size() <= 1) return true;
        for (size_t i = 1; i != A.size(); ++i) {
            if (A.at(i - 1) >= A.at(i)) return false;
        }
        return true;
    }
    bool isStrictlyDecreasing(const vector<int> &A) {
        if (A.size() <= 1) return true;
        for (size_t i = 1; i != A.size(); ++i) {
            if (A.at(i - 1) <= A.at(i)) return false;
        }
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        int height = getHeight(root);
        vec.resize(height + 1);
        bfs(root);
        int n = (int)vec.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                for (const auto &j : vec.at(i)) {
                    if (j % 2 == 0) {
                        return false;
                    }
                }
                if (!isStrictlyIncreasing(vec.at(i))) {
                    return false;
                }
            }
            else {
                for (const auto &j : vec.at(i)) {
                    if (j % 2 != 0) {
                        return false;
                    }
                }
                if (!isStrictlyDecreasing(vec.at(i))) {
                    return false;
                }
            }
        }
        return true;
    }
};