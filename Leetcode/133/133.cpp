/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<int, unordered_set<int> > adj;
    unordered_set<int> vis;
    void dfs(Node* last, Node* cur) {
        if (last) {
            adj[last->val].insert(cur->val);
        }
        if (vis.find(cur->val) != vis.end()) {
            return;
        }
        vis.insert(cur->val);
        for (const auto &i : cur->neighbors) {
            dfs(cur, i);
        }
    }
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        adj.clear();
        vis.clear();
        adj[node->val].clear();
        dfs(nullptr, node);
        unordered_map<int, Node*> id2node;
        for (const auto &[k, v] : adj) {
            if (id2node.find(k) == id2node.end()) {
                id2node[k] = new Node(k);
            }
            for (const auto &i : v) {
                if (id2node.find(i) == id2node.end()) {
                    id2node[i] = new Node(i);
                }
            }
        }
        for (const auto &[k, v] : adj) {
            for (const auto &i : v) {
                id2node[k]->neighbors.emplace_back(id2node[i]);
            }
        }
        return id2node[1];
    }
};