#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct Node {
    ll val;
    int id;
    Node(ll val, int id) : val(val), id(id) {}
    bool operator < (const Node &other) const {
        if (val == other.val) {
            return id < other.id;
        }
        return val < other.val;
    }
};

tree<Node, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> RBTree;

int main() {
    
    int n;
    int op;
    ll val;
    scanf("%d", &n);
    for (int id = 1; id <= n; ++id) {
        scanf("%d %lld", &op, &val);
        if (op == 1) {
            printf("%lu\n", RBTree.order_of_key(Node(val, -1)) + 1);
        }
        else if (op == 2) {
            printf("%lld\n", RBTree.find_by_order(val - 1)->val);
        }
        else if (op == 3) {
            printf("%lld\n", (--RBTree.lower_bound(Node(val, 1)))->val);
        }
        else if (op == 4) {
            auto iter = RBTree.upper_bound(Node(val, numeric_limits<int>::max()));
            if (iter == RBTree.end()) {
                printf("%d\n", numeric_limits<int>::max());
            } else {
                printf("%lld\n", RBTree.upper_bound(Node(val, numeric_limits<int>::max()))->val);
            }
        }
        else if (op == 5) {
            RBTree.insert(Node(val, id));
        }
    }

    return 0;
}

