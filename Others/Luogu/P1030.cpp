#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

unordered_map<int, char> convert;
unordered_map<char, int> convert_rev;

struct Node {
    int id;
    shared_ptr<Node> left;
    shared_ptr<Node> right;
    shared_ptr<Node> father;
    explicit Node(int id) : id(id), left(nullptr), right(nullptr), father(nullptr) {}
};

void postOrderTraversal(const shared_ptr<Node>& root, vector<int> &output) {
    if (root) {
        postOrderTraversal(root->left, output);
        postOrderTraversal(root->right, output);
        output.emplace_back(root->id);
    }
}

void preOrderTraversal(const shared_ptr<Node>& root) {
    if (root) {
        printf("%c", convert[root->id]);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

shared_ptr<Node> insert(shared_ptr<Node> root, int id) {
    if (!root) {
        root = make_shared<Node>(id);
    }
    else if (id < root->id) {
        if (!root->left) {
            root->left = make_shared<Node>(id);
            root->left->father = root;
        } else {
            root->left = insert(root->left, id);
        }
    }
    else if (id > root->id) {
        if (!root->right) {
            root->right = make_shared<Node>(id);
            root->right->father = root;
        } else {
            root->right = insert(root->right, id);
        }
    }
    return root;
}

constexpr int MAXN = 10;
char cstr[MAXN];

int main() {

    scanf("%s", cstr);
    string pre_order(cstr);
    int temp;
    for (size_t i = 0; i != pre_order.size(); ++i) {
        temp = static_cast<int>(i);
        convert[temp] = pre_order.at(i);
        convert_rev[pre_order.at(i)] = temp;
    }
    scanf("%s", cstr);
    string post_order(cstr);
    vector<int> post_order_int;
    for (const auto &i : post_order) {
        post_order_int.emplace_back(convert_rev[i]);
    }

    vector<int> perm = post_order_int;
    sort(perm.begin(), perm.end());
    do {
        shared_ptr<Node> T = nullptr;
        vector<int> temp_vec;
        for (const auto &i : perm) {
            T = insert(T, i);
        }
        postOrderTraversal(T, temp_vec);
        if (temp_vec == post_order_int) {
            preOrderTraversal(T);
            printf("\n");
            return 0;
        }
    } while (next_permutation(perm.begin(), perm.end()));

    return 0;
}
