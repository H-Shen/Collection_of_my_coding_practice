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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        //get height by bfs and find all nodes whose dep = depth-1
        queue<pair<TreeNode*,int>> q;
        vector<TreeNode*> vec;
        q.push({root,1});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int curDepth = q.front().second;
            q.pop();
            if (curDepth == depth-1) {
                vec.emplace_back(node);
            }
            if (node->left) {
                q.push({node->left,curDepth+1});
            }
            if (node->right) {
                q.push({node->right,curDepth+1});
            }
        }
        for (auto &i : vec) {
            TreeNode* leftNode = new TreeNode(val);
            TreeNode* rightNode = new TreeNode(val);
            if (i->left) {
                leftNode->left = i->left;
                i->left = leftNode;
            } else {
                i->left = leftNode;
            }
            if (i->right) {
                rightNode->right = i->right;
                i->right = rightNode;
            } else {
                i->right = rightNode;
            }
        }
        return root;
    }
};