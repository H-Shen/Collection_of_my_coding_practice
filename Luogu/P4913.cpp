#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

namespace Binary_search_tree {

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
    
    // Obtain the maximal depth of a BST
    template<typename T>
    inline
    int get_height(const std::shared_ptr<Node<T> > &root) {
        if (!root) {
            return 0;
        }
        return 1 + std::max(get_height(root->left_child),
                            get_height(root->right_child));
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, left, right;
    cin >> n;
    vector<shared_ptr<Binary_search_tree::Node<int> > > A(n + 1);
    for (int i = 1; i <= n; ++i) {
        A.at(i) = make_shared<Binary_search_tree::Node<int> >(i);
    }
    for (int i = 1; i <= n; ++i) {
        cin >> left >> right;
        if (left == 0) {
            A.at(i)->left_child = nullptr;
        } else {
            A.at(i)->left_child = A.at(left);
            A.at(left)->father = A.at(i);
        }
        if (right == 0) {
            A.at(i)->right_child = nullptr;
        } else {
            A.at(i)->right_child = A.at(right);
            A.at(right)->father = A.at(i);
        }
    }

    // get root in O(logn)
    auto node = A.at(1);
    while (node->father) {
        node = node->father;
    }
    // get height in O(logn)
    cout << Binary_search_tree::get_height(node) << '\n';
    return 0;
}