/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> node2node;
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        for (auto &[k,v] : node2node) {
            if (v) {
                delete v;
            }
        }
        node2node.clear();
        auto node(head);
        while (node) {
            node2node[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while (node) {
            if (node->random) {
                node2node[node]->random = node2node[node->random];
            }
            node = node->next;
        }
        for (auto &[k,v] : node2node) {
            if (k->next) {
                v->next = node2node[k->next];
            }
        }
        return node2node[head];
    }
};