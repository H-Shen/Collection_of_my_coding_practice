// https://www.nowcoder.com/practice/e12c53c925754a07b5f5a2a4dd8fa829

#include <bits/stdc++.h>

using namespace std;

vector<int> A;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode *root) {
    if (root) {
        inorderTraversal(root->left);
        A.emplace_back(root->val);
        inorderTraversal(root->right);
    }
}

bool isBinarySearchTree() {
    for (size_t i = 0; i != A.size() - 1; ++i) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, r;
    scanf("%d%d", &n, &r);
    TreeNode *tree, *root;
    tree = (TreeNode *) malloc(sizeof(TreeNode) * (n + 1));
    root = &tree[r];
    for (int i = 1; i <= n; i++) {
        int v, l, r;
        scanf("%d%d%d", &v, &l, &r);
        tree[i].val = v;
        tree[i].left = l ? &tree[l] : 0;
        tree[i].right = r ? &tree[r] : 0;
    }
    inorderTraversal(root);
    printf(isBinarySearchTree() ? "true\n" : "false\n");
    return 0;
}