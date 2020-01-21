// 模板: 普通平衡树 (Balanced Tree)

#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

struct Node {
    ll val;
    int id;
    Node(ll val, int id) : val(val), id(id) {}
    Node() : Node(0, 0) {}
    bool operator<(const Node &other) const {
        if (val == other.val) {
            return (id < other.id);
        }
        return (val < other.val);
    }
};

// Define a balance tree (Red-black tree)
tree<Node, null_type, less<>, rb_tree_tag,
        tree_order_statistics_node_update> RBTree;
unordered_map<int, int> val2counter;

int main() {

    int n, opt;
    ll x;
    Node temp_node;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %lld", &opt, &x);
        switch (opt) {
            case 1:
                // Count from 1
                ++val2counter[x];
                RBTree.insert(Node(x, val2counter[x]));
                break;
            case 2:
                if (val2counter.find(x) != val2counter.end()) {
                    RBTree.erase(Node(x, val2counter[x]));
                    --val2counter[x];
                    if (val2counter[x] == 0) {
                        val2counter.erase(x);
                    }
                }
                break;
            case 3:
                if (val2counter.find(x) == val2counter.end()) {
                    temp_node.val = x;
                    temp_node.id = 1;
                    RBTree.insert(temp_node);
                    printf("%lu\n", RBTree.order_of_key(temp_node) + 1);
                    RBTree.erase(temp_node);
                } else {
                    temp_node.val = x;
                    temp_node.id = 1;
                    printf("%lu\n", RBTree.order_of_key(temp_node) + 1);
                }
                break;
            case 4:
                printf("%lld\n", RBTree.find_by_order(x - 1)->val);
                break;
            case 5:
                if (val2counter.find(x) == val2counter.end()) {
                    temp_node.val = x;
                    temp_node.id = 1;
                    RBTree.insert(temp_node);
                    printf("%lld\n", (--RBTree.lower_bound(temp_node))->val);
                    RBTree.erase(temp_node);
                } else {
                    temp_node.val = x;
                    temp_node.id = 1;
                    printf("%lld\n", (--RBTree.lower_bound(temp_node))->val);
                }
                break;
            default:
                if (val2counter.find(x) == val2counter.end()) {
                    temp_node.val = x;
                    temp_node.id = 1;
                    RBTree.insert(temp_node);
                    printf("%lld\n", RBTree.upper_bound(temp_node)->val);
                    RBTree.erase(temp_node);
                } else {
                    temp_node.val = x;
                    temp_node.id = val2counter[x];
                    printf("%lld\n", RBTree.upper_bound(temp_node)->val);
                }
                break;
        }
    }

    return 0;
}