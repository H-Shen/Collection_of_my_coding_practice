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
    unordered_map<TreeNode*, TreeNode*> father;
    unordered_map<TreeNode*,int> dp;
    int ans;
    int solve(TreeNode* node) {
        if (dp.find(node) != dp.end()) {
            return dp[node];
        }
        // Case 1: node is root
        if (!father[node]) {
            dp[node] = 0;
        }
        // Case 2: node is the left child
        else if (node == father[node]->left) {
            // Subcase 1: father is root
            if (!father[father[node]]) {
                dp[node] = 1;
            }
            // Subcase 2: father is the right child of its father
            else if (father[node] == father[father[node]]->right) {
                dp[node] = dp[father[node]] + 1;
            }
            // Subcase 3: father is the left child of its father
            else {
                dp[node] = 1;
            }
        }
        // Case 3: node is the right child
        else {
            if (!father[father[node]]) {
                dp[node] = 1;
            }
            else if (father[node] == father[father[node]]->left) {
                dp[node] = dp[father[node]] + 1;
            }
            else {
                dp[node] = 1;
            }
        }
        return dp[node];
    }
    // get the father of each node
    void dfs1(TreeNode* node) {
        if (node->left && node->right) {
            father[node->left] = node;
            father[node->right] = node;
            dfs1(node->left);
            dfs1(node->right);
        }
        else if (node->left && !node->right) {
            father[node->left] = node;
            dfs1(node->left);
        }
        else if (!node->left && node->right) {
            father[node->right] = node;
            dfs1(node->right);
        }
    }
    // get the longest zigzag path
    void dfs2(TreeNode* node) {
        if (node) {
            ans = max(ans, solve(node));
            dfs2(node->left);
            dfs2(node->right);
        }
    }
    int longestZigZag(TreeNode* root) {
        ans = 0;
        dp.clear();
        father.clear();
        father[root] = nullptr;
        dfs1(root);
        dfs2(root);
        return ans;
    }
};