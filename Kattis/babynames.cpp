// https://open.kattis.com/problems/babynames
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using RBTree = tree<string, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int MAXN = 40;
char name1[MAXN];
char name2[MAXN];

RBTree male;
RBTree female;

int main() {

    int op, sex;
    while (~scanf("%d", &op)) {
        if (op == 0) {
            break;
        }
        else if (op == 1) {
            scanf("%s %d", name1, &sex);
            if (sex == 1) {
                male.insert(name1);
            } else {
                female.insert(name1);
            }
        }
        else if (op == 2) {
            scanf("%s", name1);
            male.erase(name1);
            female.erase(name1);
        }
        else if (op == 3) {
            scanf("%s %s %d", name1, name2, &sex);
            if (sex == 1) {
                int counter = 0;
                counter = male.order_of_key(name2) - male.order_of_key(name1);
                printf("%d\n", counter);
            }
            else if (sex == 2) {
                int counter = female.order_of_key(name2) - female.order_of_key(name1);;
                printf("%d\n", counter);
            }
            else {
                int counter1 = male.order_of_key(name2) - male.order_of_key(name1);
                int counter2 = female.order_of_key(name2) - female.order_of_key(name1);
                printf("%d\n", counter1 + counter2);
            }
        }
    }

    return 0;
}
