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
    vector<TreeNode*> id2node;
    unordered_map<TreeNode*,int> node2id;
    vector<int> dp;
    vector<pair<int,int>> AL;
    int solve(int nodeId) {
        if (dp[nodeId] != -1) {
            return dp[nodeId];
        }
        dp[nodeId] = id2node[nodeId]->val;
        if (AL[nodeId].first != -1) {
            dp[nodeId] += solve(AL[nodeId].first);
        }
        if (AL[nodeId].second != -1) {
            dp[nodeId] += solve(AL[nodeId].second);
        }
        return dp[nodeId];
    }
    void dfs1(TreeNode* node) {
        if (node) {
            node2id[node] = (int)id2node.size();
            id2node.emplace_back(node);
            dfs1(node->left);
            dfs1(node->right);
        }
    }
    void dfs2(int nodeId) {
        TreeNode* node = id2node[nodeId];
        if (node->left && node->right) {
            AL[nodeId].first = node2id[node->left];
            AL[nodeId].second = node2id[node->right];
            dfs2(AL[nodeId].first);
            dfs2(AL[nodeId].second);
        }
        else if (!node->left && node->right) {
            AL[nodeId].first = -1;
            AL[nodeId].second = node2id[node->right];
            dfs2(AL[nodeId].second);
        }
        else if (node->left && !node->right) {
            AL[nodeId].first = node2id[node->left];
            AL[nodeId].second = -1;
            dfs2(AL[nodeId].first);
        }
        else {
            AL[nodeId].first = -1;
            AL[nodeId].second = -1;
        }
    }
    TreeNode* pruneTree(TreeNode* root) {
        vector<TreeNode*>().swap(id2node);
        node2id.clear();
        vector<int>().swap(dp);
        decltype(AL)().swap(AL);
        dfs1(root);
        AL.resize(id2node.size());
        dp.resize(id2node.size(),-1);
        int rootId = 0;
        dfs2(rootId);
        // Corner case: all nodes have the value of 0
        if (solve(rootId) == 0) {
            return nullptr;
        }
        // prune
        for (int i = 0; i < (int)AL.size(); ++i) {
            if (solve(i) != 0) {
                if (AL[i].first != -1 && solve(AL[i].first) == 0) {
                    AL[i].first = -1;
                }
                if (AL[i].second != -1 && solve(AL[i].second) == 0) {
                    AL[i].second = -1;
                }
            } 
        }
        for (auto &[k,v] : node2id) {
            if (AL[v].first == -1) {
                k->left = nullptr;
            }
            if (AL[v].second == -1) {
                k->right = nullptr;
            }
        }
        return root;
    }
};