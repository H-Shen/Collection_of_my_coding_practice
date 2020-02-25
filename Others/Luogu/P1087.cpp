#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 1050;
char cstr[MAXN];

struct Node {
    string val;
    Node* left;
    Node* right;
    Node* father;
    explicit Node(string val) : val(move(val)), left(nullptr), right(nullptr), father(nullptr) {}
};

char type_check(const string &s) {
    bool has_one = false;
    bool has_zero = false;
    for (const auto &i : s) {
        if (i == '1') {
            has_one = true;
        }
        else if (i == '0') {
            has_zero = true;
        }
    }
    if (has_one && has_zero) {
        return 'F';
    } else if (has_one) {
        return 'I';
    }
    return 'B';
}

void postOrderTraversal(Node* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c", type_check(root->val));
    }
}

void generate(Node* root) {
    if (root && root->val.size() > 1) {
        root->left = new Node(root->val.substr(0, root->val.size() / 2));
        root->left->father = root;
        root->right = new Node(root->val.substr(root->val.size() / 2));
        root->right->father = root;
        generate(root->left);
        generate(root->right);
    }
}

int main() {

    int n;
    scanf("%d", &n);
    scanf("%s", cstr);
    Node* root = new Node(cstr);
    generate(root);
    postOrderTraversal(root);
    printf("\n");

    return 0;
}