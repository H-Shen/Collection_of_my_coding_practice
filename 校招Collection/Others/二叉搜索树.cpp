// https://www.nowcoder.com/practice/3d6dd9a58d5246f29f71683346bb8f1b

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 20;
char cstr[MAXN];

struct Node {
    int val;
    shared_ptr<Node> father;
    shared_ptr<Node> leftChild;
    shared_ptr<Node> rightChild;
    explicit Node(int val) :
            val(val),
            father(nullptr),
            leftChild(nullptr),
            rightChild(nullptr) {}
    Node() = delete;
};
shared_ptr<Node> insert(shared_ptr<Node> &root, int val) {
    if (!root) {
        root = make_shared<Node>(val);
    }
    else if (val < root->val) {
        if (!root->leftChild) {
            root->leftChild = make_shared<Node>(val);
            root->leftChild->father = root;
        } else {
            root->leftChild = insert(root->leftChild, val);
        }
    }
    else if (val > root->val) {
        if (!root->rightChild) {
            root->rightChild = make_shared<Node>(val);
            root->rightChild->father = root;
        } else {
            root->rightChild = insert(root->rightChild, val);
        }
    }
    return root;
}

inline static
bool isSameTree(shared_ptr<Node> &T1, shared_ptr<Node> &T2) {
    if (!T1 && !T2) {
        return true;
    }
    if (!T1 || !T2) {
        return false;
    }
    if (T1->val == T2->val) {
        return isSameTree(T1->leftChild, T2->leftChild) &&
               isSameTree(T1->rightChild, T2->rightChild);
    }
    return false;
}

int main() {

    int n;
    string s, s_;
    while (~scanf("%d", &n)) {
        if (n == 0) {
            break;
        }
        scanf("%s", cstr);
        s = cstr;
        shared_ptr<Node> tree = nullptr;
        for (const char &i : s) {
            tree = insert(tree, static_cast<int>(i - '0'));
        }
        while (n--) {
            scanf("%s", cstr);
            s_ = cstr;
            shared_ptr<Node> tree2 = nullptr;
            for (const char &i : s_) {
                tree2 = insert(tree2, static_cast<int>(i - '0'));
            }
            if (isSameTree(tree, tree2)) {
                puts("YES");
            } else {
                puts("NO");
            }
        }
    }

    return 0;
}