#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 5;
char cstr[MAXN];

struct Node {
    char val;
    Node* left;
    Node* right;
    Node* father;
    explicit Node(char val) : val(val), left(nullptr), right(nullptr), father(nullptr) {}
};

void preOrderTraversal(Node* root) {
    if (root) {
        printf("%c", root->val);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {

    int n;
    scanf("%d", &n);
    vector<string> A(n);
    unordered_map<char, Node*> temp_unmap;
    for (int i = 0; i < n; ++i) {
        scanf("%s", cstr);
        A.at(i) = cstr;
        for (const auto &ch : A.at(i)) {
            if (ch != '*' && temp_unmap.find(ch) == temp_unmap.end()) {
                temp_unmap[ch] = new Node(ch);
            }
        }
    }
    char father;
    char left_child;
    char right_child;
    for (const string &s : A) {
        father = s.at(0);
        left_child = s.at(1);
        right_child = s.at(2);
        if (left_child != '*') {
            temp_unmap[father]->left = temp_unmap[left_child];
            temp_unmap[left_child]->father = temp_unmap[father];
        }
        if (right_child != '*') {
            temp_unmap[father]->right = temp_unmap[right_child];
            temp_unmap[right_child]->father = temp_unmap[father];
        }
    }
    // get root
    auto iter = temp_unmap.begin()->second;
    while (iter->father) {
        iter = iter->father;
    }
    preOrderTraversal(iter);
    printf("\n");
    return 0;
}
