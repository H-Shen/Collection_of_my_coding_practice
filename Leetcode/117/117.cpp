/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node* > > v;
    void bfs(Node* root) {
        queue<pair<Node*, int> > q;
        q.push({root, 0});
        while (!q.empty()) {
            Node* curNode = q.front().first;
            int curLevel = q.front().second;
            q.pop();
            v.at(curLevel).emplace_back(curNode);
            if (curNode->left) {
                q.push({curNode->left, curLevel + 1});
            }
            if (curNode->right) {
                q.push({curNode->right, curLevel + 1});
            }
        }
    }
    int getHeight(Node* root) {
        if (root->left && root->right) {
            return 1 + max(getHeight(root->left), getHeight(root->right));
        }
        else if (root->left && !root->right) {
            return 1 + getHeight(root->left);
        }
        else if (!root->left && root->right) {
            return 1 + getHeight(root->right);
        }
        else {
            return 0;
        }
    }
    Node* connect(Node* root) {
        if (!root) return nullptr;
        v.resize(getHeight(root) + 1);
        bfs(root);
        int n;
        for (auto &i : v) {
            n = (int)i.size();
            if (n == 1) {
                i.front()->next = nullptr;
            }
            else {
                for (int j = 0; j < n - 1; ++j) {
                    i[j]->next = i[j+1];
                }
                i[n-1]->next = nullptr;
            }
        }
        return root;
    }
};