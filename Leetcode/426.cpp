/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
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
    Node* treeToDoublyList(Node* root) {        
        dfs(root);
        int n = (int)v.size();
        if (n == 0) {
            return nullptr;
        }
        else if (n == 1) {
            root->right = root;
            root->left = root;
            return root;
        }
        for (int i = 0; i < n - 1; ++i) {
            v[i]->right = v[i+1];
        }
        v[n-1]->right=v[0];
        v[0]->left = v[n-1];
        for (int i = n - 1; i > 0; --i) {
            v[i]->left = v[i-1];
        }
        return v[0];
    }
};