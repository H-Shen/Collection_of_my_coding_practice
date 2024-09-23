// https://www.nowcoder.com/practice/30a0153649304645935c949df7599602

#include <bits/stdc++.h>

using namespace std;

// Define a node of a BST
template<typename T>
struct Node {
    T value;
    shared_ptr<Node> father;
    shared_ptr<Node> left_child;
    shared_ptr<Node> right_child;
    Node() = delete;
    explicit Node(const T &v) :
            value(v),
            father(nullptr),
            left_child(nullptr),
            right_child(nullptr) {}
};

// Insert a node to the BST
template <typename T>
inline
shared_ptr<Node<T> > insert(shared_ptr<Node<T> > &root, const T &value) {
    if (!root) {
        root = make_shared<Node<T> >(value);
        // output
        if (root->father) {
            printf("%d\n", root->father->value);
        } else {
            printf("-1\n");
        }
    }
    else if (value < root->value) {
        if (!root->left_child) {
            root->left_child = make_shared<Node<T> >(value);
            root->left_child->father = root;
            // output
            if (root) {
                printf("%d\n", root->value);
            } else {
                printf("-1\n");
            }

        } else {
            root->left_child = insert(root->left_child, value);
        }
    }
    else if (value > root->value) {
        if (!root->right_child) {
            root->right_child = make_shared<Node<T> >(value);
            root->right_child->father = root;
            // output
            if (root) {
                printf("%d\n", root->value);
            } else {
                printf("-1\n");
            }

        } else {
            root->right_child = insert(root->right_child, value);
        }
    } else {
        // No duplicates are allowed
        throw runtime_error("Value duplicated.");
    }
    return root;
}

int main() {
    int n, val;
    shared_ptr<Node<int> > Tree = nullptr;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        Tree = insert(Tree, val);
    }
    return 0;
}