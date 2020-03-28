#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace BST {

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
    
    // Insert a node to the BST
    template <typename T>
    inline
    std::shared_ptr<Node<T> > insert(std::shared_ptr<Node<T> > &root, const T &value) {
        if (!root) {
            root = std::make_shared<Node<T> >(value);
        }
        else if (value <= root->value) {
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
}

unordered_map<int, vector<int> > depth2width;
template<typename T>
void dfs(const shared_ptr<BST::Node<T> > &node, int level, int position) {
    if (node) {
        depth2width[level].emplace_back(position);
        if (node->left_child) {
            dfs(node->left_child, level + 1, 2 * position);
        }
        if (node->right_child) {
            dfs(node->right_child, level + 1, 2 * position + 1);
        }
    }
}

int main() {

    shared_ptr<BST::Node<int> > T = nullptr;
    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        if (i == 0) {
            T = make_shared<BST::Node<int> >(val);
        } else {
            T = BST::insert(T, val);
        }
    }
    dfs(T, 0, 1);
    int n1, n2;
    if (depth2width.empty()) {
        n1 = 0;
        n2 = 0;
    } else if (depth2width.size() == 1) {
        n1 = depth2width[0].size();
        n2 = 0;
    } else {
        n1 = depth2width[depth2width.size() - 1].size();
        n2 = depth2width[depth2width.size() - 2].size();
    }
    printf("%d + %d = %d\n", n1, n2, n1 + n2);

    return 0;
}
