// https://www.nowcoder.com/practice/b42cfd38923c4b72bde19b795e78bcb3

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
    }
    else if (value < root->value) {
        if (!root->left_child) {
            root->left_child = make_shared<Node<T> >(value);
            root->left_child->father = root;
        } else {
            root->left_child = insert(root->left_child, value);
        }
    }
    else if (value > root->value) {
        if (!root->right_child) {
            root->right_child = make_shared<Node<T> >(value);
            root->right_child->father = root;
        } else {
            root->right_child = insert(root->right_child, value);
        }
    } else {
        // Duplicates are ignored
    }
    return root;
}

template <typename T>
inline
void pre_order_traverse(const shared_ptr<Node<T> > &root, vector<T> &output) {
    if (!root) {
        return;
    }
    output.emplace_back(root->value);
    pre_order_traverse(root->left_child, output);
    pre_order_traverse(root->right_child, output);
}

template <typename T>
inline
void in_order_traverse(const shared_ptr<Node<T> > &root, vector<T> &output) {
    if (!root) {
        return;
    }
    in_order_traverse(root->left_child, output);
    output.emplace_back(root->value);
    in_order_traverse(root->right_child, output);
}

template <typename T>
inline
void post_order_traverse(const shared_ptr<Node<T> > &root, vector<T> &output) {
    if (!root) {
        return;
    }
    post_order_traverse(root->left_child, output);
    post_order_traverse(root->right_child, output);
    output.emplace_back(root->value);
}

int main() {

    int n, val;
    shared_ptr<Node<int> > Tree;

    while (~scanf("%d", &n)) {
        Tree = nullptr;
        while (n--) {
            scanf("%d", &val);
            Tree = insert(Tree, val);
        }
        vector<int> temp;
        bool firstItem;

        // pre-order
        vector<int>().swap(temp);
        pre_order_traverse(Tree, temp);
        firstItem = true;
        for (const auto &i : temp) {
            printf("%d ", i);
        }
        printf("\n");

        // in-order
        vector<int>().swap(temp);
        in_order_traverse(Tree, temp);
        firstItem = true;
        for (const auto &i : temp) {
            printf("%d ", i);
        }
        printf("\n");

        // post-order
        vector<int>().swap(temp);
        post_order_traverse(Tree, temp);
        firstItem = true;
        for (const auto &i : temp) {
            printf("%d ", i);
        }
        printf("\n");
    }

    return 0;
}