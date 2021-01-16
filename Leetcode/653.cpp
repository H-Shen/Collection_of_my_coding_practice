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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
class Solution {
public:
    vector<int> v;
    bool f(int target) {
        unordered_set<int, custom_hash> unset(v.begin(), v.end());
        for (const auto &i : unset) {
            int complement = target - i;
            if (unset.find(complement) != unset.end() && complement != i) {
                return true;
            }
        }
        return false;
    }
    void dfs(TreeNode* root) {
        if (root) {
            v.emplace_back(root->val);
            dfs(root->left);
            dfs(root->right);
        }
    }
    bool findTarget(TreeNode* root, int k) {
        dfs(root);
        return f(k);
    }
};