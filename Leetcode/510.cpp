/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    vector<Node*> v;
    void dfs(Node* root) {
        if (root) {
            dfs(root->left);
            v.emplace_back(root);
            dfs(root->right);
        }
    }
    Node* inorderSuccessor(Node* node) {
        if (!node) {
            return nullptr;
        }
        auto root(node);
        while (root->parent) {
            root = root->parent;
        }
        dfs(root);
        int n = (int)v.size();
        for (int i = 0; i < n; ++i) {
            if (v[i] == node) {
                if (i == n - 1) {
                    return nullptr;
                }
                else {
                    return v[i+1];
                }
            }
        }
        return nullptr;
    }
};