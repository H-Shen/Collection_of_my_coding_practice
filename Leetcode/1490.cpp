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
    unordered_map<Node*, Node*> node2node;
    void dfs(Node* root) {
        if (node2node.find(root) == node2node.end()) {
            node2node[root] = new Node(root->val);
            for (const auto &v : root->children) {
                dfs(v);
            }
        }
    }
    Node* cloneTree(Node* root) {
        if (!root) {
            return nullptr;
        }
        for (auto &[k, v] : node2node) {
            delete v;
        }
        node2node.clear();
        dfs(root);
        for (auto &[k, v] : node2node) {
            for (auto &i : k->children) {
                v->children.emplace_back(node2node[i]);
            }
        }
        return node2node[root];
    }
};