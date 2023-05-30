/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
public:
    string s;
    void dfs(RopeTreeNode* node) {
        if (node) {
            if (!node->left && !node->right) {
                s += node->val;
            }
            dfs(node->left);
            dfs(node->right);
        }
    }
    char getKthCharacter(RopeTreeNode* root, int k) {
        s.clear();
        dfs(root);
        return s.at(k-1);
    }
};