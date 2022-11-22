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
    vector<vector<int>> vec;
    int getHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1+max(getHeight(root->left), getHeight(root->right));
    }
    void bfs(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        while (!q.empty()) {
            pair<TreeNode*,int> p = q.front();
            q.pop();
            vec[p.second-1].emplace_back(p.first->val);
            if (p.first->left) {
                q.push({p.first->left, p.second+1});
            }
            if (p.first->right) {
                q.push({p.first->right, p.second+1});
            }
        }
    }
    int count(vector<int>& v) {
        vector<int> vecCopy(v);
        sort(vecCopy.begin(),vecCopy.end());
        unordered_map<int,int> val2index;
        int n = (int)v.size();
        if (n <= 1) {
            return 0;
        }
        for (int i = 0; i < n; ++i) {
            val2index[vecCopy[i]] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; ) {
            if (val2index[v[i]] != i) {
                swap(v[i], v[val2index[v[i]]]);
                ++ans;
            }
            else {
                ++i;
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        vector<vector<int>>().swap(vec);
        int h = getHeight(root);
        vec.resize(h);
        bfs(root);
        int cnt = 0;
        for (auto&i : vec) {
            cnt += count(i);
        }
        return cnt;
    }
};