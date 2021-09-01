/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, unordered_set<TreeNode*>> in;  // (node i, all nodes that point to i) 
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                in[node->left].insert(node);
                q.push(node->left);
            }
            if (node->right) {
                in[node->right].insert(node);
                q.push(node->right);
            }
        }
        unordered_map<TreeNode*,int> node2height;
        queue<pair<TreeNode*,int>> q2;
        q2.push({root,1});
        while (!q2.empty()) {
            TreeNode* node = q2.front().first;
            int height = q2.front().second;
            if (node2height.find(node) == node2height.end()) {
                node2height[node] = height;
            }
            q2.pop();
            if (node->left) {
                q2.push({node->left,height+1});
            }
            if (node->right) {
                q2.push({node->right,height+1});
            }
        }
        TreeNode* toNode = nullptr;
        TreeNode* fromNode = nullptr;
        for (const auto &[k,v] : in) {
            if (v.size() == 2) {
                toNode = k;
                for (const auto &p : v) {
                    if (node2height[p] == node2height[toNode]) {
                        fromNode = p;
                        break;
                    }
                }
                break;
            }
        }
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                if (node->left == fromNode) {
                    node->left = nullptr;
                    break;
                }
                q.push(node->left);
            }
            if (node->right) {
                if (node->right == fromNode) {
                    node->right = nullptr;
                    break;
                }
                q.push(node->right);
            }
        }
        return root;
    }
};