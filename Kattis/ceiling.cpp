// https://open.kattis.com/problems/ceiling
//
#include <bits/extc++.h>

using namespace std;

struct Node {
    int val;
    Node* father;
    Node* leftChild;
    Node* rightChild;
    explicit Node(int val) :
            val(val),
            father(nullptr),
            leftChild(nullptr),
            rightChild(nullptr) {}
    Node() = delete;
};

inline static
bool isSameShape(Node *T1,  Node *T2) {
    if (!T1 && !T2) {
        return true;
    }
    if (!T1 || !T2) {
        return false;
    }
    return isSameShape(T1->leftChild, T2->leftChild) && isSameShape(T1->rightChild, T2->rightChild);
}

Node* insert(Node *root, int val) {
    if (!root) {
        root = new Node(val);
    }
    else if (val < root->val) {
        if (!root->leftChild) {
            root->leftChild = new Node(val);
            root->leftChild->father = root;
        } else {
            root->leftChild = insert(root->leftChild, val);
        }
    }
    else if (val > root->val) {
        if (!root->rightChild) {
            root->rightChild = new Node(val);
            root->rightChild->father = root;
        } else {
            root->rightChild = insert(root->rightChild, val);
        }
    }
    return root;
}

vector<int> A;
void inOrderTraversal(Node *root) {
    if (root) {
        inOrderTraversal(root->leftChild);
        A.emplace_back(root->val);
        inOrderTraversal(root->rightChild);
    }
}
void inOrderTraverse(Node *root) {
    vector<int>().swap(A);
    inOrderTraversal(root);
    for (const auto &i : A) {
        cout << i << ' ';
    }
    cout << endl;
}

namespace UnionFindSet {

    constexpr int maxn = 105;
    int father[maxn]; // Father nodes
    int Rank[maxn]; // Rank

    int find(int x) {
        if (x != father[x])
            father[x] = find(father[x]);
        return father[x];
    }

    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        if (Rank[x] > Rank[y]) {
            father[y] = x;
        } else {
            father[x] = y;
            if (Rank[x] == Rank[y])
                Rank[y] += 1;
        }
    }

    void reset() {
        for (int i = 0; i < maxn; i++) {
            father[i] = i;
            Rank[i] = 0;
        }
    }
}

int main() {

    int n, k, val;
    cin >> n >> k;
    vector<Node* > treeList(n);
    for (auto &i : treeList) {
        i = nullptr;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> val;
            treeList.at(i) = insert(treeList.at(i), val);
        }
    }

    // check different shapes
    UnionFindSet::reset();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (isSameShape(treeList.at(i), treeList.at(j))) {
                UnionFindSet::merge(i, j);
            }
        }
    }
    unordered_set<int> stats;
    for (int i = 0; i < n; ++i) {
        stats.insert(UnionFindSet::find(i));
    }
    cout << stats.size() << endl;

    return 0;
}
