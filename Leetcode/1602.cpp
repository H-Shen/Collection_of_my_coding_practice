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

constexpr int MAXN = 100005;

class Solution {
public:
    int n, height;
    TreeNode* id2node[MAXN];
    vector<vector<int> > vec;
    void dfs(TreeNode* root) {
        if (root) {
            ++n;
            dfs(root->left);
            dfs(root->right);
        }
    }
    void dfs2(TreeNode* root) {
        if (root) {
            id2node[root->val] = root;
            dfs2(root->left);
            dfs2(root->right);
        }
    }
    int dfs3(TreeNode* root) {
        if (root->left && root->right) {
            return 1+max(dfs3(root->left), dfs3(root->right));
        }
        else if (root->left && !root->right) {
            return 1+dfs3(root->left);
        }
        else if (!root->left && root->right) {
            return 1+dfs3(root->right);
        }
        return 0;
    }
    void bfs(TreeNode* root) {
        queue<pair<TreeNode*,int> > q;
        q.push({root,0});
        TreeNode* curNode;
        int curLevel;
        while (!q.empty()) {
            curNode = q.front().first;
            curLevel = q.front().second;
            vec[curLevel].emplace_back(curNode->val);
            q.pop();
            if (curNode->left) {
                q.push({curNode->left, curLevel+1});
            }
            if (curNode->right) {
                q.push({curNode->right, curLevel+1});
            }
        }
    }
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        n = 0;
        dfs(root);
        memset(id2node, 0, sizeof id2node);
        dfs2(root);
        height = dfs3(root);
        decltype(vec)().swap(vec);
        vec.resize(height+1);
        bfs(root);
        for (const auto &i : vec) {
            for (auto iter = i.begin(); iter != i.end(); ++iter) {
                if (*iter == u->val) {
                    ++iter;
                    if (iter == i.end()) {
                        return nullptr;
                    }
                    return id2node[*iter];
                }
            }
        }
        return nullptr;
    }
};