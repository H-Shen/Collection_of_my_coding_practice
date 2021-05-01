/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

constexpr int MAXN = 505;
vector<vector<int> > AL;
vector<int> dist;
vector<int> query_list;

namespace DSU {
    vector<int> father, Size;
    void init(int n) {
        vector<int>().swap(father);
        vector<int>().swap(Size);
        father.resize(n + 5);
        iota(father.begin(), father.end(), 0);
        Size.resize(n + 5, 1);
    }
    int find(int x) {
        if (x != father[x]) {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return;
        }
        if (Size[x] > Size[y]) {
            swap(x, y);
        }
        Size[y] += Size[x];
        father[x] = y;
    }
}

namespace LCA {
    struct myHashFunc {
        size_t operator()(const pair<int,int> &o) const {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        }
    };
    vector<vector<int> > queries;
    vector<bool> vis;
    vector<int> ancestor;
    unordered_map<pair<int, int>, int, myHashFunc> unmap;
    void init() {
        // reset
        unmap.clear();
        vector<int>().swap(ancestor);
        vector<bool>().swap(vis);
        vector<vector<int> >().swap(queries);
        // init
        DSU::init(MAXN);
        ancestor.resize(MAXN);
        vis.resize(MAXN, false);
        queries.resize(MAXN);
    }
    void Tarjan(int u) {
        vis[u] = true;
        ancestor[u] = true;
        for (const auto &v : AL[u]) {
            if (!vis[v]) {
                Tarjan(v);
                DSU::merge(u, v);
                ancestor[DSU::find(u)] = u;
            }
        }
        for (const auto &v : queries[u]) {
            if (vis[v]) {
                unmap[{u, v}] = unmap[{v, u}] = ancestor[DSU::find(v)];
            }
        }
    }
}

class Solution {
public:
    void dfs(TreeNode* root, TreeNode* father) {
        if (!root) {
            return;
        }
        if (father) {
            // undirected
            AL[father->val].emplace_back(root->val);
            AL[root->val].emplace_back(father->val);
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }
    void dfs1(int u, int father_of_u, int currSum) {
        dist[u] = currSum;
        for (const auto &v : AL[u]) {
            if (v != father_of_u) {
                dfs1(v, u, dist[u] + 1);
            }
        }
    }
    void dfs2(TreeNode* root, TreeNode* target) {
        if (!root) {
            return;
        }
        LCA::queries[root->val].emplace_back(target->val);
        LCA::queries[target->val].emplace_back(root->val);
        query_list.emplace_back(root->val);
        dfs2(root->left, target);
        dfs2(root->right, target);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        vector<vector<int> >().swap(AL);
        vector<int>().swap(query_list);
        vector<int>().swap(dist);
        
        AL.resize(MAXN);
        dfs(root, nullptr);
        dist.resize(MAXN);
        dfs1(root->val, -1, 0);
        vector<int> result;
        if (K == 0) {
            result.emplace_back(target->val);
        }
        else {
            LCA::init();
            dfs2(root, target);
            LCA::Tarjan(root->val);            
            for (const auto &i : query_list) {
                if (dist[target->val] + dist[i] - 2*dist[LCA::unmap[{target->val, i}]] == K) {
                    result.emplace_back(i);
                }
            }
        }
        return result;
    }
};