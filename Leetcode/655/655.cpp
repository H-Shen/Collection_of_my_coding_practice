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
    vector<vector<string>> printTree(TreeNode* root) {
        // get height
        queue<pair<TreeNode*,int>> q;
        int height = 0;
        q.push({root,height});
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int curHeight = q.front().second;
            height = max(height, curHeight);
            q.pop();
            if (node->left) {
                q.push({node->left,curHeight+1});
            }
            if (node->right) {
                q.push({node->right,curHeight+1});
            }
        }
        int rows = height+1;
        int cols = (1<<(height+1))-1;
        vector<vector<string>> vec(rows, vector<string>(cols));
        // fill by bfs
        struct Node {
            TreeNode* treeNode = nullptr;
            int r,c;
            Node() = default;
            Node(TreeNode* treeNode, int r, int c) : treeNode(treeNode), r(r), c(c){}
        };
        queue<Node> q2;
        q2.push(Node(root,0,(cols-1)>>1));
        int newCol;
        while (!q2.empty()) {
            Node node = q2.front();
            q2.pop();
            vec[node.r][node.c] = to_string(node.treeNode->val);
            if (node.treeNode->left) {
                newCol = node.c - (1<<(height-node.r-1));
                q2.push(Node(node.treeNode->left,node.r+1,newCol));
            }
            if (node.treeNode->right) {
                newCol = node.c + (1<<(height-node.r-1));
                q2.push(Node(node.treeNode->right,node.r+1,newCol));
            }
        }
        return vec;
    }
};