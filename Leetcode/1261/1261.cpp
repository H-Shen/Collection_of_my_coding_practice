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
class FindElements {
private:
    unordered_set<int> elements;
public:
    void dfs1(TreeNode* root) {
        if (root->left) {
            root->left->val = 2 * root->val + 1;
            dfs1(root->left);
        }
        if (root->right) {
            root->right->val = 2 * root->val + 2;
            dfs1(root->right);
        }
    }
    void dfs2(TreeNode* root) {
        if (root) {
            dfs2(root->left);
            elements.insert(root->val);
            dfs2(root->right);
        }
    }
    FindElements(TreeNode* root) {
        if (root) {
            root->val = 0;
            dfs1(root);
            dfs2(root);
        }
    }
    
    bool find(int target) {
        return elements.find(target) != elements.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */