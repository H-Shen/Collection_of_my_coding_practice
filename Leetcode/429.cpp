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
    int h(Node* root) {
        int height = 0;
        if (root) {
            if (!root->children.empty()) {
                int maxValue = -1;
                for (const auto &i : root->children) {
                    maxValue = max(maxValue, h(i));
                }
                height = 1 + maxValue;
            }
        }
        return height;
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > result;
        if (root) {
            int currentLevel;
            result.resize(h(root) + 1);
            queue<pair<Node*, int> > q;
            q.push({root, 0});
            while (!q.empty()) {
                Node* u = q.front().first;
                currentLevel = q.front().second;
                q.pop();
                result.at(currentLevel).emplace_back(u->val);
                for (const auto &v : u->children) {
                    if (v) {
                        q.push({v, currentLevel + 1});
                    }
                }
            }
        }
        return result;
    }
};