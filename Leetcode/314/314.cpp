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
    unordered_map<int, vector<pair<int,int> > > unmap;
    void dfs(TreeNode* root, int curPos, int curHeight) {
        if (root) {
            unmap[curPos].emplace_back(root->val, curHeight);
            dfs(root->left, curPos - 1, curHeight + 1);
            dfs(root->right, curPos + 1, curHeight + 1);
        }
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        for (auto &[i, j] : unmap) {
            sort(j.begin(), j.end(), [](const auto &l, const auto &r){
                return l.second < r.second;
            });
        }
        vector<vector<int>> result(unmap.size());
        vector<int> v(unmap.size());
        auto iter = v.begin();
        for (const auto &[i, j] : unmap) {
            *iter = i;
            ++iter;
        }
        sort(v.begin(), v.end());
        for (size_t i = 0; i != result.size(); ++i) {
            for (const auto &[j, k] : unmap[v[i]]) {
                result[i].emplace_back(j);
            }
        }
        
        return result;
    }
};