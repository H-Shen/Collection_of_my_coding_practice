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

constexpr int MAXN = 1e5+5;
constexpr int NUMBER_OF_CHILDREN = 2;
int parent[MAXN][NUMBER_OF_CHILDREN];   // left child: 0 right child: 1
int n;

class Solution {
public:
    void dfs(TreeNode* node, TreeNode* fa, bool isLeft) {
        if (node) {
            ++n;
            if (fa) {
                if (isLeft) {
                    parent[node->val][0] = fa->val;
                }
                else {
                    parent[node->val][1] = fa->val;   
                }
            }
            dfs(node->left, node, true);
            dfs(node->right, node, false);
        }
    }
    int getLca(int u, int v) {
        unordered_set<int> unset;
        while (true) {
            unset.insert(u);
            if (parent[u][0] == 0 && parent[u][1] == 0) break;
            if (parent[u][0] == 0) {
                u = parent[u][1];
            }
            else {
                u = parent[u][0];
            }
        }
        while (true) {
            if (unset.find(v) != unset.end()) return v;
            if (parent[v][0] == 0) {
                v = parent[v][1];
            }
            else {
                v = parent[v][0];
            }
        }
        return -1;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        memset(parent, 0, sizeof parent);
        n = 0;
        dfs(root, nullptr, false);
        int lca = getLca(startValue, destValue);
        string ans;
        while (startValue != lca) {
            ans.push_back('U');
            if (parent[startValue][0] == 0) {
                startValue = parent[startValue][1];
            }
            else {
                startValue = parent[startValue][0];
            }
        }
        string rest;
        while (destValue != lca) {
            if (parent[destValue][0] == 0) {
                destValue = parent[destValue][1];
                rest.push_back('R');
            }
            else {
                destValue = parent[destValue][0];
                rest.push_back('L');
            }
        }
        reverse(rest.begin(),rest.end());
        ans += rest;
        return ans;
    }
};