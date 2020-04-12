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

    // Get the number of nodes in the BST
    // An alternative way is storing the size as a data member, thus
    // we can obtain the number of nodes by root->size in O(1)
    template<typename T>
    inline
    int get_size(std::shared_ptr<Node<T> > &root) {
        if (!root) {
            return 0;
        }
        return get_size(root->left_child) + get_size(root->right_child) + 1;
    }
}

template<typename T>
struct my_hash_func {
    size_t operator()(const shared_ptr<BST::Node<T> > Node) const {
        return std::hash<shared_ptr<BST::Node<T> > >()(Node);
    }
};

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

    int n;
    scanf("%d", &n);
    vector<shared_ptr<BST::Node<int> > > A;
    A.emplace_back(nullptr);
    for (int i = 1; i <= n; ++i) {
        A.emplace_back(make_shared<BST::Node<int> >(i));
    }
    int u, v;
    for (int i = 1; i <= n - 1; ++i) {
        scanf("%d %d", &u, &v);
        if (A[u]->left_child == nullptr) {
            A[u]->left_child = A[v];
        } else {
            A[u]->right_child = A[v];
        }
        A[v]->father = A[u];
    }
    scanf("%d %d", &u, &v);
    // get u to root
    unordered_set<shared_ptr<BST::Node<int> >, my_hash_func<int> > u_to_root;
    auto root = A[u];
    while (root->father) {
        u_to_root.insert(root);
        root = root->father;
    }
    u_to_root.insert(root);
    // find LCA
    shared_ptr<BST::Node<int> > lca = nullptr;
    auto v_node = A[v];
    while (v_node->father) {
        if (u_to_root.find(v_node) != u_to_root.end()) {
            lca = v_node;
            break;
        }
        v_node = v_node->father;
    }
    if (!lca) {
        lca = root;
    }
    // obtain the distance of path from u to lca
    auto u_node = A[u];
    int u_to_lca = 0;
    while (u_node != lca) {
        ++u_to_lca;
        u_node = u_node->father;
    }
    // obtain the distance of path from lca to v
    v_node = A[v];
    int v_to_lca = 0;
    while (v_node != lca) {
        ++v_to_lca;
        v_node = v_node->father;
    }
    dfs(A[1], 0, 1);
    int max_width = 0;
    for (const auto &[k, v] : depth2width) {
        max_width = max(max_width, static_cast<int>(v.size()));
    }
    printf("%d\n", BST::get_height(root));
    printf("%d\n", max_width);
    printf("%d\n", u_to_lca * 2 + v_to_lca);

    return 0;
}