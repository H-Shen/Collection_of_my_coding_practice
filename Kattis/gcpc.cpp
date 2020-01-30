// https://open.kattis.com/problems/gcpc
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Team {
    int number;
    int a;
    int b;
    bool operator < (const Team &other) const {
        if (a == other.a) {
            if (b == other.b) {
                return number < other.number;
            }
            return b < other.b;
        }
        return a > other.a;
    }
    explicit Team(int number, int a, int b) : number(number), a(a), b(b) {}
    Team() = default;
};

using RBTree = tree<Team, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;
unordered_map<int, Team> unmap;
RBTree Tree;

int main() {

    int n, m, t, p;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        Team temp(i, 0, 0);
        unmap.emplace(i, temp);
        Tree.insert(temp);
    }
    while (m--) {
        scanf("%d %d", &t, &p);
        Tree.erase(unmap[t]);
        ++unmap[t].a;
        unmap[t].b += p;
        Tree.insert(unmap[t]);
        printf("%lu\n", Tree.order_of_key(unmap[1]) + 1);
    }
    return 0;
}
