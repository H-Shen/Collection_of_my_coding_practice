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

constexpr int MAXN = 1050;

namespace LCA1 {
    int n, l;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;
    void reset() {
        vector<int>().swap(tin);
        vector<int>().swap(tout);
        vector<vector<int> >().swap(up);
        n = 0; l = 0; timer = 0;
    }
    void dfs(int v, int p, vector<vector<int> > &adj) {
        tin[v] = ++timer;
        up[v][0] = p;
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];

        for (int u : adj[v]) {
            if (u != p)
                dfs(u, v, adj);
        }
        tout[v] = ++timer;
    }
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    int lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    // Assume node id starts from 0
    void preprocess(int number_of_nodes) {
        reset();
        n = number_of_nodes;
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.resize(n, vector<int>(l + 1));
    }
    void init(int root, vector<vector<int> > &adj) { dfs(root, root, adj); }
}

class Solution {
public:
    vector<vector<int> > adj;
    int node2height[MAXN]{};
    unordered_map<TreeNode*, int> node2id;
    int id = 0;
    vector<int> leaves;
    void dfs1(TreeNode* root, int currHeight) {
        node2id[root] = id;
        node2height[id] = currHeight;
        if (!root->left && !root->right) {
            leaves.emplace_back(id);
        }
        ++id;
        if (root->left && root->right) {
            dfs1(root->left, currHeight + 1);
            dfs1(root->right, currHeight + 1);
        }
        else if (root->left && !root->right) {
            dfs1(root->left, currHeight + 1);
        }
        else if (!root->left && root->right) {
            dfs1(root->right, currHeight + 1);
        }
    }
    void dfs2(TreeNode* root, TreeNode* father_of_root) {
        if (father_of_root) {
            adj[node2id[father_of_root]].emplace_back(node2id[root]);
        }
        if (root->left && root->right) {
            dfs2(root->left, root);
            dfs2(root->right, root);
        }
        else if (root->left && !root->right) {
            dfs2(root->left, root);
        }
        else if (!root->left && root->right) {
            dfs2(root->right, root);
        }
    }
    int dist(int u, int v) {
        return node2height[u] + node2height[v] - 2*node2height[LCA1::lca(u, v)];
    }
    int countPairs(TreeNode* root, int distance) {
        if (!root) return 0;
        adj.resize(MAXN);
        dfs1(root, 0);
        dfs2(root, nullptr);
        LCA1::preprocess(id + 5);
        LCA1::init(0, adj);
        int counter = 0;
        int n = (int)leaves.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (dist(leaves[i], leaves[j]) <= distance) {
                    ++counter;
                }
            }
        }
        return counter;
    }
};