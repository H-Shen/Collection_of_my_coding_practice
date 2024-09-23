#include <bits/stdc++.h>

// Define a node of a BST
template<typename T>
struct Node {
    T value;
    std::shared_ptr<Node> father;
    std::shared_ptr<Node> left_child;
    std::shared_ptr<Node> right_child;
    Node() = delete;
    explicit Node(const T &v) :
            value(v),
            father(nullptr),
            left_child(nullptr),
            right_child(nullptr) {}
};

template <typename T>
void pre_order_traverse(const std::shared_ptr<Node<T> > &root, std::vector<T> &output) {
    if (!root) {
        return;
    }
    output.emplace_back(root->value);
    pre_order_traverse(root->left_child, output);
    pre_order_traverse(root->right_child, output);
}

// Obtain a mirror of a BST
template <typename T>
void mirror(std::shared_ptr<Node<T> > &root) {
    if (!root) {
        return;
    }
    std::swap(root->left_child, root->right_child);
    mirror(root->left_child);
    mirror(root->right_child);
}

// Insert a node to the BST
template <typename T>
std::shared_ptr<Node<T> > insert(std::shared_ptr<Node<T> > &root, const T &value) {
    if (!root) {
        root = std::make_shared<Node<T> >(value);
    }
    else if (value < root->value) {
        if (!root->left_child) {
            root->left_child = std::make_shared<Node<T> >(value);
            root->left_child->father = root;
        } else {
            root->left_child = insert(root->left_child, value);
        }
    }
    else {
        if (!root->right_child) {
            root->right_child = std::make_shared<Node<T> >(value);
            root->right_child->father = root;
        } else {
            root->right_child = insert(root->right_child, value);
        }
    }
    return root;
}

template <typename T>
void post_order_traverse(const std::shared_ptr<Node<T> > &root, std::vector<T> &output) {
    if (!root) {
        return;
    }
    post_order_traverse(root->left_child, output);
    post_order_traverse(root->right_child, output);
    output.emplace_back(root->value);
}

int main() {
    
    int n;
    scanf("%d", &n);
    std::vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    std::shared_ptr<Node<int> > Tree = nullptr;
    for (const auto &i : A) {
        Tree = insert(Tree, i);
    }
    std::vector<int> pre_order;
    std::vector<int> post_order;
    pre_order_traverse(Tree, pre_order);
    post_order_traverse(Tree, post_order);

    mirror(Tree);
    std::vector<int> pre_order_of_mirror;
    std::vector<int> post_order_of_mirror;
    pre_order_traverse(Tree, pre_order_of_mirror);
    post_order_traverse(Tree, post_order_of_mirror);

    if (pre_order == A) {
        printf("YES\n");
        bool firstItem = true;
        for (const auto &i : post_order) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    } else if (pre_order_of_mirror == A) {
        printf("YES\n");
        bool firstItem = true;
        for (const auto &i : post_order_of_mirror) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", i);
        }
    } else {
        printf("NO");
    }
    printf("\n");

    return 0;
}