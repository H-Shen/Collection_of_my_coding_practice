// NOI2004

#include <bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 5;
char op[MAXN];

struct Node {
    ll val;
    ll id;
    Node(ll val, int id) : val(val), id(id) {}
    bool operator>(const Node &other) const {
        if (val == other.val) {
            return (id > other.id);
        }
        return (val > other.val);
    }
};

tree<Node, null_type, greater<>, rb_tree_tag,
        tree_order_statistics_node_update> Rbtree, Rbtree_temp;

ll people_has_left = 0;

// indicates an offset of the salary after all 'S/A' operations before,
// thus we don't need to adjust all nodes, store an offset would be enough
// A: -offset
// S: +offset
ll offset_of_salary = 0;
ll id_counter = 0;

// remember that minVal will be changed if the boss adjusts it!
ll minimal_salary;
int n;
ll val;

int main() {

    scanf("%d %lld", &n, &minimal_salary);
    while (n--) {
        scanf("%s %lld", op, &val);
        switch (op[0]) {
            case 'I':
                // Add the new node if val >= minimal_salary
                val += + offset_of_salary;
                if (val >= minimal_salary) {
                    Rbtree.insert(Node(val, id_counter));
                    ++id_counter;
                }
                break;
            case 'S':
                offset_of_salary += val;
                minimal_salary += val;
                Rbtree_temp.clear();
                // All nodes such that node.val < minimal_salary will be deleted from Rbtree
                Rbtree.split(Node(minimal_salary, -1), Rbtree_temp);
                people_has_left += Rbtree_temp.size();
                break;
            case 'A':
                offset_of_salary -= val;
                minimal_salary -= val;
                break;
            default:
                if (val > static_cast<ll>(Rbtree.size())) {
                    printf("-1");
                } else {
                    printf("%lld", Rbtree.find_by_order(val - 1)->val - offset_of_salary);
                }
                printf("\n");
                break;
        }
    }
    printf("%lld\n", people_has_left);

    return 0;
}
