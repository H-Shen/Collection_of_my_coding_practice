// https://open.kattis.com/problems/continuousmedian
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct Node {
    ll val;
    int id;
    explicit Node(ll val, int id) : val(val), id(id) {}
    Node() = delete;
    bool operator<(const Node &other) const {
        if (val == other.val) {
            return (id < other.id);
        }
        return (val < other.val);
    }
};

tree<Node, null_type, less<>, rb_tree_tag,
        tree_order_statistics_node_update> Rbtree;

int main() {

    int t, n;
    scanf("%d", &t);
    ll sumOfMedian;
    ll val;
    ll median;
    int id;
    while (t--) {
        scanf("%d", &n);
        sumOfMedian = 0;
        Rbtree.clear();
        id = 0;
        for (int i = 1; i <= n; ++i, ++id) {
            scanf("%lld", &val);
            Rbtree.insert(Node(val, id));
            if (i % 2 == 1) {
                median = Rbtree.find_by_order(i / 2)->val;
            } else {
                median = (Rbtree.find_by_order(i / 2)->val + Rbtree.find_by_order(i / 2 - 1)->val) / 2;
            }
            sumOfMedian += median;
        }
        printf("%lld\n", sumOfMedian);
    }

    return 0;
}
