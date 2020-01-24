// https://open.kattis.com/problems/doctorkattis
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 20;
char name[MAXN];

struct Cat {
    string name;
    int infection_level;
    int index;
    bool operator < (const Cat &other) const {
        if (infection_level == other.infection_level) {
            return (index < other.index);
        }
        return (infection_level > other.infection_level);
    }
    explicit Cat(string name, int infection_level, int index) : name(std::move(name)), infection_level(infection_level), index(index) {}
    Cat() = default;
};

unordered_map<string, Cat> name2obj;
tree<Cat, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> RBTree;

int main() {

    int n, op, val;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &op);
        if (op == 0) {
            scanf("%s %d", name, &val);
            Cat temp_cat(name, val, i);
            RBTree.insert(temp_cat);
            name2obj[name] = temp_cat;
        } else if (op == 1) {
            scanf("%s %d", name, &val);
            RBTree.erase(name2obj[name]);
            name2obj[name].infection_level += val;
            RBTree.insert(name2obj[name]);
        } else if (op == 2) {
            scanf("%s", name);
            RBTree.erase(name2obj[name]);
            name2obj.erase(name);
        } else {
            if (RBTree.empty()) {
                printf("The clinic is empty\n");
            } else {
                printf("%s\n", RBTree.find_by_order(0)->name.c_str());
            }
        }
    }


    return 0;
}
