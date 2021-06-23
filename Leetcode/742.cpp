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

constexpr int MAXN = 1005;

vector<vector<int> > AL;
vector<int> leaves, dist;

namespace LCA {
    int n, l;
    int timer;
    vector<int> dfs_in, dfs_out;
    vector<vector<int>> fa;
    void dfs(int u, int father_of_u) {
        dfs_in[u] = ++timer;
        fa[u][0] = father_of_u;
        for (int i = 1; i <= l; ++i) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (const auto &v : AL[u]) {
            if (v != father_of_u) {
                dfs(v, u);
            }
        }
        dfs_out[u] = ++timer;
    }
    bool is_ancestor_of(int u, int v) {
        return dfs_in[u] <= dfs_in[v] && dfs_out[v] <= dfs_out[u];
    }
    int lca(int u, int v) {
        if (is_ancestor_of(u, v)) {
            return u;
        }
        if (is_ancestor_of(v, u)) {
            return v;
        }
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor_of(fa[u][i], v)) {
                u = fa[u][i];
            }
        }
        return fa[u][0];
    }
    // Assume node id starts from 0
    void preprocess(int number_of_nodes) {
        // reset
        vector<int>().swap(dfs_in);
        vector<int>().swap(dfs_out);
        decltype(fa)().swap(fa);
        // pre
        n = number_of_nodes;
        dfs_in.resize(n+1);
        dfs_out.resize(n+1);
        timer = 0;
        l = ceil(log2(n));
        fa.resize(n, vector<int>(l + 1));
    }
    void init(int root) { dfs(root, root); }
}

class Solution {
public:
    void dfs(TreeNode* root) {
        if (root->left && root->right) {
            AL[root->val].emplace_back(root->left->val);
            AL[root->val].emplace_back(root->right->val);
            dfs(root->left);
            dfs(root->right);
        }
        else if (root->left && !root->right) {
            AL[root->val].emplace_back(root->left->val);
            dfs(root->left);
        }
        else if (!root->left && root->right) {
            AL[root->val].emplace_back(root->right->val);
            dfs(root->right);
        }
        else {
            leaves.emplace_back(root->val);
        }
    }
    void dfs2(int u, int fa, int dis) {
        dist[u] = dis;
        for (const auto &v : AL[u]) {
            if (v != fa) {
                dfs2(v,u,dis+1);
            }
        }
    }
    int getDist(int u, int v) {
        return dist[u]+dist[v]-2*dist[LCA::lca(u,v)];
    }
    int findClosestLeaf(TreeNode* root, int k) {
        decltype(AL)().swap(AL);
        decltype(leaves)().swap(leaves);
        decltype(dist)().swap(dist);
        AL.resize(MAXN);
        dist.resize(MAXN);
        dfs(root);
        dfs2(root->val,-1,0);
        LCA::preprocess(MAXN);
        int ans = 0;
        LCA::init(root->val);
        int shortestDist = numeric_limits<int>::max();
        // O(nlogn)
        for (const auto &i : leaves) {
            shortestDist = min(shortestDist,getDist(i,k));
        }
        for (const auto &i : leaves) {
            if (getDist(i,k) == shortestDist) {
                return i;
            }
        }
        return k;
    }
};