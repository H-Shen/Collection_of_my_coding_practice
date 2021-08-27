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

class Solution {
public:
    array<TreeNode*, MAXN> id2node;
    array<int, MAXN> parent;
    unordered_set<int> remain;
    void dfs(TreeNode* u) {
        if (u) {
            id2node[u->val] = u;
            dfs(u->left);
            dfs(u->right);
        }
    }
    void dfs2(TreeNode* u, TreeNode* father_of_u) {
        if (u) {
            if (father_of_u) {
                parent[u->val] = father_of_u->val;
            }
            else {
                parent[u->val] = -1;
            }
            dfs2(u->left, u);
            dfs2(u->right, u);
        }
    }
    void dfs3(TreeNode* u) {
        if (u) {
            remain.erase(u->val);
            dfs3(u->left);
            dfs3(u->right);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i = 0; i < MAXN; ++i) {
            if (id2node[i]) {
                delete id2node[i];
            }
            id2node[i] = nullptr;
        }
        dfs(root);
        dfs2(root, nullptr);
        for (const auto &i : to_delete) {
            if (id2node[i]) {
                // left child
                if (id2node[i]->left) {
                    parent[id2node[i]->left->val] = -1;
                    id2node[i]->left = nullptr;
                }
                // right child
                if (id2node[i]->right) {
                    parent[id2node[i]->right->val] = -1;
                    id2node[i]->right = nullptr;
                }
                // parent
                if (parent[i] != -1) {
                    if (id2node[i] == id2node[parent[i]]->left) {
                        id2node[parent[i]]->left = nullptr;
                    }
                    else {
                        id2node[parent[i]]->right = nullptr;
                    }
                }
            }
        }
        vector<TreeNode*> ans;
        remain.clear();
        unordered_set<int> unset(to_delete.begin(), to_delete.end());
        for (int i = 0; i < MAXN; ++i) {
            if (id2node[i]) {
                if (unset.find(i) == unset.end()) {
                    remain.insert(i);
                }
            }
        }
        while (!remain.empty()) {
            int u = *remain.begin();
            while (parent[u] != -1) {
                u = parent[u];
            }
            ans.emplace_back(id2node[u]);
            dfs3(id2node[u]);
        }
        return ans;
    }
};