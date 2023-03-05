using ll = long long;

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
    int getHeight(TreeNode* node) {
        if (!node) {
            return 0;
        }
        return 1 + max(getHeight(node->left), getHeight(node->right));
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<ll> levels(getHeight(root));
        queue<pair<TreeNode*,int>> q;
        q.emplace(root, 0);
        pair<TreeNode*,int> p;
        while (!q.empty()) {
            p = q.front();
            q.pop();
            levels[p.second] += p.first->val;
            if (p.first->left) {
                q.emplace(p.first->left, p.second+1);
            }
            if (p.first->right) {
                q.emplace(p.first->right, p.second+1);
            }
        }
        if (k > (int)levels.size()) {
            return -1;
        }
        nth_element(levels.begin(), levels.begin()+k-1, levels.end(), greater<>());
        return levels[k-1];
    }
};