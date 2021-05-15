/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    unordered_map<Node*,NodeCopy*> node2node;
    void dfs1(Node* u) {
        if (u) {
            node2node[u] = new NodeCopy(u->val);
            dfs1(u->left);
            dfs1(u->right);
        }
    }
    void dfs2(Node* u) {
        if (u->random) {
            node2node[u]->random = node2node[u->random];
        }
        if (u->left && u->right) {
            node2node[u]->left = node2node[u->left];
            node2node[u]->right = node2node[u->right];
            dfs2(u->left);
            dfs2(u->right);
        }
        else if (u->left && !u->right) {
            node2node[u]->left = node2node[u->left];
            dfs2(u->left);
        }
        else if (!u->left && u->right) {
            node2node[u]->right = node2node[u->right];
            dfs2(u->right);
        }
    }
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if (!root) {
            return nullptr;
        }
        dfs1(root);
        dfs2(root);
        return node2node[root];
    }
};