#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using RBTree = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

RBTree T;

int main() {

    int n, k, val;
    scanf("%d %d", &n, &k);
    while (n--) {
        scanf("%d", &val);
        T.insert(val);
    }
    if (k > static_cast<int>(T.size()) || k <= 0) {
        printf("NO RESULT\n");
    } else {
        printf("%d\n", *T.find_by_order(k - 1));
    }

    return 0;
}