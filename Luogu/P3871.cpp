#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 5;
char op[MAXN];

template <typename T>
using Rbtree = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
struct Node {
    explicit Node(ll val, int id) : val(val), id(id) {}
    bool operator<(const Node &rhs) const {
        if (val == rhs.val) {
            return id < rhs.id;
        }
        return val < rhs.val;
    }
    ll val;
    int id;
};
int id;
Rbtree<Node> Tree;

int main() {

    int n;
    ll val;
    int length;
    scanf("%d", &n);
    while (n--) {
        scanf("%lld", &val);
        Tree.insert(Node(val, id));
        ++id;
    }
    scanf("%d", &n);
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "add") == 0) {
            scanf("%lld", &val);
            Tree.insert(Node(val, id));
            ++id;
        } else {
            length = static_cast<int>(Tree.size());
            if (length & 1) {
                printf("%lld\n", Tree.find_by_order(length / 2)->val);
            } else {
                printf("%lld\n", Tree.find_by_order((length-1) / 2)->val);
            }
        }
    }
    return 0;
}