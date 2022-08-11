/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void dfs(struct TreeNode* node, int* val) {
    if (node) {
        ++(*val);
        dfs(node->left, val);
        dfs(node->right, val);
    }
}

void dfs2(struct TreeNode* node, int** array_ptr, int* index) {
    if (node) {
        dfs2(node->left, array_ptr, index);
        (*array_ptr)[*index] = node->val;
        ++(*index);
        dfs2(node->right, array_ptr, index);
    }
}

bool isValidBST(struct TreeNode* root){
    int n = 0;
    dfs(root,&n);
    int* temp = (int*)malloc(sizeof(int)*n);
    int index = 0;
    dfs2(root, &temp, &index);
    bool ans = true;
    for (int i = 0; i < n-1; ++i) {
        if (temp[i] >= temp[i+1]) {
            ans = false;
            break;
        }
    }
    
    free(temp);
    temp = NULL;
    return ans;
}