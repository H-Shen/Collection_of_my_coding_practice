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

struct Tuple {
    int val, l, r;
    Tuple(int val, int l, int r) : val(val), l(l), r(r) {}
    Tuple() = default;
    bool operator == (const Tuple &node) const {
        return val == node.val && l == node.l && r == node.r;
    }
};

struct myHashFunc {
    size_t operator() (const Tuple& node) const {
        size_t h = 0;
        h ^= hash<int>{}(node.val) + 0x9e3779b9 + (h << 6) + (h >> 2);
        h ^= hash<int>{}(node.l) + 0x9e3779b9 + (h << 6) + (h >> 2);
        h ^= hash<int>{}(node.r) + 0x9e3779b9 + (h << 6) + (h >> 2);
        return h;
    }
};

class Solution {
public:
    vector<TreeNode*> ans;
    unordered_map<Tuple, int, myHashFunc> dp;   // tuple to its index
    unordered_map<int,int> freq;    // tuple's index to its oucurrences
    int globalId;
    int dfs(TreeNode* node) {
        if (node) {
            auto k = Tuple(node->val, dfs(node->left), dfs(node->right));
            auto iter = dp.find(k);
            if (iter == dp.end()) {
                dp[k] = globalId;
                ++freq[globalId];
                ++globalId;
            }
            else {
                ++freq[dp[k]];
            }
            if (freq[dp[k]] == 2) {
                ans.emplace_back(node);
            }
            return dp[k];
        }
        else {
            return -1;
        }
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>().swap(ans);
        dp.clear();
        freq.clear();
        globalId = 0;
        dfs(root);
        return ans;
    }
};