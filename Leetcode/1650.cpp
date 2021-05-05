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
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if (!q || !p) return nullptr;
        if (q == p) return p;
        unordered_set<Node*> unmap;
        Node* node = p;
        while (node) {
            unmap.insert(node);
            node = node->parent;
        }
        node = q;
        while (node) {
            if (unmap.find(node) != unmap.end()) {
                break;
            }
            node = node->parent;
        }
        return node;
    }
};