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
    unordered_map<TreeNode*, pair<int,int> > unmap;
    void dfs(TreeNode* root, int row, int col) {
        if (root) {
            unmap[root] = {row,col};
            dfs(root->left,row+1,col-1);
            dfs(root->right,row+1,col+1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unmap.clear();
        dfs(root,0,0);
        vector<tuple<int,int,int> > vec(unmap.size());
        auto iter = vec.begin();
        for (const auto &[k,v] : unmap) {
            get<0>(*iter) = v.second;
            get<1>(*iter) = v.first;
            get<2>(*iter) = k->val;
            ++iter;
        }
        sort(vec.begin(),vec.end(),[](const auto &l, const auto &r){
            if (get<0>(l) == get<0>(r)) {
                if (get<1>(l) == get<1>(r)) {
                    return get<2>(l) < get<2>(r);
                }
                return get<1>(l) < get<1>(r);
            }
            return get<0>(l) < get<0>(r);
        });
        int curCol;
        vector<int> temp;
        vector<vector<int> > ans;
        for (const auto &[c,r,v] : vec) {
            if (temp.empty()) {
                curCol = c;
                temp.emplace_back(v);
                continue;
            }
            if (curCol == c) {
                temp.emplace_back(v);
            } else {
                ans.emplace_back(temp);
                vector<int>().swap(temp);
                curCol = c;
                temp.emplace_back(v);
            }
        }
        if (!temp.empty()) {
            ans.emplace_back(temp);
        }
        return ans;
    }
};