// HAOI2008

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 30;
constexpr int MAX_LIST = 10;
char instruction[MAXN];

struct Node {
    int val{};
    int id{};
    string name;

    Node() = default;

    Node(int val, int id, string name) : val(val), id(id),
                                         name(std::move(name)) {}

    bool operator>(const Node &other) const {
        if (val == other.val) {
            return (id < other.id);
        }
        return (val > other.val);
    }
};

tree<Node, null_type, greater<>, rb_tree_tag,
        tree_order_statistics_node_update> Rbtree;
unordered_map<string, Node> Hashmap;

int main() {

    int n;
    int val;
    string temp_str;
    int rank;
    int counter;
    bool firstItem;
    scanf("%d", &n);
    for (int kase = 0; kase < n; ++kase) {
        scanf("%s", instruction);
        if (instruction[0] == '+') {
            // Example: +FRANK 12340000
            scanf("%d", &val);
            temp_str = "";
            for (int i = 1; instruction[i] != '\0'; ++i) {
                temp_str.push_back(instruction[i]);
            }

            if (Hashmap.find(temp_str) == Hashmap.end()) {
                Hashmap[temp_str].name = temp_str;
                Hashmap[temp_str].val = val;
                Hashmap[temp_str].id = kase;
                Rbtree.insert(Node(val, kase, temp_str));
            } else {
                Rbtree.erase(Node(Hashmap[temp_str].val, Hashmap[temp_str].id,
                                  temp_str));
                Hashmap[temp_str].val = val;
                Hashmap[temp_str].id = kase;
                Rbtree.insert(Node(val, kase, temp_str));
            }

        } else if (isdigit(instruction[1])) {
            // Example: ?2
            temp_str = "";
            for (int i = 1; instruction[i] != '\0'; ++i) {
                temp_str.push_back(instruction[i]);
            }
            rank = stoi(temp_str) - 1;
            firstItem = true;
            auto iter = Rbtree.find_by_order(rank);
            counter = 0;
            while (iter != Rbtree.end()) {
                if (counter == MAX_LIST) {
                    break;
                }
                if (firstItem) {
                    firstItem = false;
                } else {
                    printf(" ");
                }
                printf("%s", iter->name.c_str());
                ++counter;
                ++iter;
            }
            if (!firstItem) {
                printf("\n");
            }
        } else {
            // Example: ?KAINE
            temp_str = "";
            for (int i = 1; instruction[i] != '\0'; ++i) {
                temp_str.push_back(instruction[i]);
            }
            printf("%lu\n", Rbtree.order_of_key(
                    Node(Hashmap[temp_str].val, Hashmap[temp_str].id,
                         temp_str)) + 1);
        }
    }


    return 0;
}
