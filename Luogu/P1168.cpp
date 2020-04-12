#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Node {
    int val;
    int id;
    explicit Node(int val, int id) : val(val), id(id) {}
    bool operator < (const Node &other) const {
        if (val == other.val) {
            return (id < other.id);
        }
        return (val < other.val);
    }
};

using RBTree = tree<Node, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
RBTree T;

int main() {

    int n, val;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &val);
        T.insert(Node(val, n));
        if (T.size() % 2 != 0) {
            printf("%d\n", T.find_by_order(T.size() / 2)->val);
        }
    }
    return 0;
}
