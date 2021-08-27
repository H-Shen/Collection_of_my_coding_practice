/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> output;
    void solve(Node* root) {
        if (root) {
            for (auto &i : root->children) {
                solve(i);
            }
            output.emplace_back(root->val);
        }
    }
    vector<int> postorder(Node* root) {
        solve(root);
        return output;
    }
};