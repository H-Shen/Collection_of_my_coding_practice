#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

// Define a node of a BST
struct Node {
    int value;
    shared_ptr<Node> father;
    shared_ptr<Node> left_child;
    shared_ptr<Node> right_child;

    Node() : Node(0) {}

    explicit Node(const int &v) :
            value(v),
            father(nullptr),
            left_child(nullptr),
            right_child(nullptr) {}
};

void level_order_traverse(const shared_ptr<Node> &root) {
    bool firstItem = true;
    queue<shared_ptr<Node> > q;
    q.push(root);
    shared_ptr<Node> node = nullptr;
    while (!q.empty()) {
        node = q.front();
        q.pop();
        if (node != nullptr) {
            if (firstItem) {
                firstItem = false;
            } else {
                printf(" ");
            }
            printf("%d", node->value);
        }
        if (node->left_child) {
            q.push(node->left_child);
        }
        if (node->right_child) {
            q.push(node->right_child);
        }
    }
    printf("\n");
}

vector<int> Node_Value;
int Node_Value_Idx = 0;

void in_order_assign(shared_ptr<Node> &root) {
    if (!root) {
        return;
    }
    in_order_assign(root->left_child);
    root->value = Node_Value.at(Node_Value_Idx);
    ++Node_Value_Idx;
    in_order_assign(root->right_child);
}

int main() {

    int n;
    scanf("%d", &n);
    vector<pair<int, int> > Relationship(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &Relationship.at(i).first, &Relationship.at(i).second);
    }
    vector<shared_ptr<Node> > Value(n);
    for (int i = 0; i < n; ++i) {
        Value.at(i) = make_shared<Node>();
    }
    Node_Value.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &Node_Value.at(i));
    }
    sort(Node_Value.begin(), Node_Value.end());
    for (int i = 0; i < n; ++i) {
        if (Relationship.at(i).first != -1) {
            Value.at(i)->left_child = Value.at(Relationship.at(i).first);
            Value.at(Relationship.at(i).first)->father = Value.at(i);
        }
        if (Relationship.at(i).second != -1) {
            Value.at(i)->right_child = Value.at(Relationship.at(i).second);
            Value.at(Relationship.at(i).second)->father = Value.at(i);
        }
    }
    in_order_assign(Value.at(0));
    level_order_traverse(Value.at(0));

    return 0;
}
