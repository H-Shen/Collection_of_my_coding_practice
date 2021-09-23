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
    vector<vector<int>> AL;
    unordered_map<TreeNode*,int> node2id;
    vector<int> weight, dp1, dp2;
    int id;
    int solve1(int u) {
        if (dp1[u] != -1) {
            return dp1[u];
        }
        dp1[u] = 1;
        for (const auto &v : AL[u]) {
            if (weight[u] == weight[v] + 1) {
                dp1[u] = max(dp1[u], solve1(v)+1); 
            }
        }
        return dp1[u];
    }
    int solve2(int u) {
        if (dp2[u] != -1) {
            return dp2[u];
        }
        dp2[u] = 1;
        for (const auto &v : AL[u]) {
            if (weight[u] + 1 == weight[v]) {
                dp2[u] = max(dp2[u], solve2(v)+1);
            }
        }
        return dp2[u];
    }
    void dfs1(TreeNode* u) {
        if (u) {
            node2id[u] = id;
            ++id;
            dfs1(u->left);
            dfs1(u->right);
        }
    }
    void dfs2(TreeNode* u, TreeNode* fa) {
        int uid = node2id[u];
        weight[uid] = u->val;
        if (fa) {
            AL[uid].emplace_back(node2id[fa]);
        }
        if (u->left) {
            AL[uid].emplace_back(node2id[u->left]);
            dfs2(u->left, u);
        }
        if (u->right) {
            AL[uid].emplace_back(node2id[u->right]);
            dfs2(u->right, u);
        }
    }
    int longestConsecutive(TreeNode* root) {
        id = 0;
        node2id.clear();
        dfs1(root);
        decltype(AL)().swap(AL);
        AL.resize(id);
        decltype(weight)().swap(weight);
        weight.resize(id);
        dfs2(root, nullptr);
        decltype(dp1)().swap(dp1);
        dp1.resize(id, -1);
        decltype(dp2)().swap(dp2);
        dp2.resize(id, -1);
        int ans = 0;
        for (int i = 0; i < id; ++i) {
            ans = max(ans, max(solve1(i), solve2(i)));
        }
        return ans;
    }
};