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

// O(n)
class BSTIterator {
private:
    vector<int> vec;
    int index;
public:
    void dfs(TreeNode* node) {
        if (node) {
            dfs(node->left);
            vec.emplace_back(node->val);
            dfs(node->right);
        }
    }
    BSTIterator(TreeNode* root) {
        dfs(root);
        index = -1;
    }
    
    int next() {
        ++index;
        return vec[index];
    }
    
    bool hasNext() {
        return index+1 < (int)vec.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */