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
    vector<int> d1, d2;
    vector<vector<int> > AL;
    unordered_map<Node*, int> node2Id;
    int n = 0;
    int id = 0;
    void dfs1(Node* root) {
        if (root) {
            ++n;
            for (const auto &i : root->children) {
                dfs1(i);
            }
        }
    }
    void dfs2(Node* u) {
        for (const auto &i : u->children) {
            if (i) {
                int uId = node2Id[u];
                int vId = node2Id[i];
                AL[uId].emplace_back(vId);
                AL[vId].emplace_back(uId);
                dfs2(i);
            }
        }
    }
    void dfs3(int u, int father_of_u) {
        d1[u] = 0;
        d2[u] = 0;
        for (const auto &v : AL[u]) {
            if (v == father_of_u) continue;
            dfs3(v, u);
            int temp = d1[v] + 1;   //
            if (temp > d1[u]) {
                d2[u] = d1[u];
                d1[u] = temp;
            }
            else if (temp > d2[u]) {
                d2[u] = temp;
            }
        }
    }
    void dfs4(Node* root) {
        if (root) {
            node2Id[root] = id;
            ++id;
            for (const auto &i : root->children) {
                dfs4(i);
            }
        }
    }

    int diameter(Node* root) {
        dfs1(root);
        AL.resize(n);
        dfs4(root);
        d1.resize(n);
        d2.resize(n);
        dfs2(root);
        dfs3(node2Id[root], -1);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            result = max(result, d1[i]+d2[i]);
        }
        return result;
    }
};