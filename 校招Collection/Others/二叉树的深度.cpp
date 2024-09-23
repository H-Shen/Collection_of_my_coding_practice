// https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b

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
    int TreeDepth(TreeNode *pRoot) {
        int rightDepth = 0, leftDepth = 0;
        if (!pRoot) {
            return 0;
        }

        if (pRoot->left) {
            leftDepth = TreeDepth(pRoot->left);
        } else {
            leftDepth = 0;
        }

        if (pRoot->right) {
            rightDepth = TreeDepth(pRoot->right);
        } else {
            rightDepth = 0;
        }
        return (rightDepth > leftDepth) ? rightDepth + 1 : leftDepth + 1;
    }
};