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

bool sameTree(TreeNode* l, TreeNode* r) {
    if (!l && !r) return true;
    if (!l || !r) return false;
    if (l->val == r->val) {
        return sameTree(l->left,r->left) && sameTree(l->right,r->right);
    }
    return false;
}

struct keyEqualFn {
    bool operator() (TreeNode* l, TreeNode* r) const {
        return sameTree(l, r);
    }  
};

struct hashFn {
    size_t operator() (TreeNode* node) const {
        return hash<int>()(node->val);
    }  
};

TreeNode* insert(TreeNode* root, int val) {
    if (!root) {
        root = new TreeNode(val);
    }
    else if (val > root->val) {
        if (!root->right) {
            root->right = new TreeNode(val);
        }
        else {
            root->right = insert(root->right, val);
        }
    }
    else {
        if (!root->left) {
            root->left = new TreeNode(val);
        }
        else {
            root->left = insert(root->left, val);
        }
    }
    return root;
}


class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> v(n);
        for (int i = 1; i <= n; ++i) v[i-1] = i;
        unordered_set<TreeNode*, hashFn, keyEqualFn> unset;
        do {
            TreeNode* root = nullptr;
            for (int j = 0; j < n; ++j) {
                root = insert(root, v[j]);
            }
            unset.insert(root);
        } while (next_permutation(v.begin(),v.end()));
        vector<TreeNode*> vec;
        for (auto &i : unset) {
            vec.emplace_back(i);
        }
        return vec;
    }
};