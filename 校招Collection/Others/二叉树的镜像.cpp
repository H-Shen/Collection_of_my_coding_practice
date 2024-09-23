// https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void Mirror(TreeNode *root) {
        if (root) {
            swap(root->left, root->right);
            Mirror(root->left);
            Mirror(root->right);
        }
    }
};
