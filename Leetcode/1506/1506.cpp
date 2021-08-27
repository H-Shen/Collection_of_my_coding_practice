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
    unordered_map<Node*, bool> hasInDegree;
    Node* findRoot(vector<Node*> tree) {
        for (const auto &i : tree) {
            hasInDegree[i] = false;
        }
        for (const auto &i : tree) {
            for (const auto &j : i->children) {
                hasInDegree[j] = true;
            }
        }
        for (const auto &[k, v] : hasInDegree) {
            if (!v) {
                return k;
            }
        }
        return nullptr;
    }
};