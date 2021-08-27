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
class BSTIterator {
private:
    vector<int> v;
    vector<int>::iterator iter;
    void dfs(TreeNode* root) {
        if (root) {
            dfs(root->left);
            v.emplace_back(root->val);
            dfs(root->right);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        dfs(root);
        iter = v.begin();
        --iter;
    }
    
    bool hasNext() {
        return std::next(iter) != v.end();
    }
    
    int next() {
        return *(++iter);
    }
    
    bool hasPrev() {
        return !(iter == v.begin() || std::next(iter) == v.begin());
    }
    
    int prev() {
        return *(--iter);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */