#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 20;
char s[MAXN];
unordered_map<int, int> vis;

struct Compare {
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        if (lhs.first == rhs.first) {
            return (lhs.second < rhs.second);
        }
        return (lhs.first < rhs.first);
    }
};

tree <pair<int, int> ,null_type, Compare, rb_tree_tag,
        tree_order_statistics_node_update> Rbtree;
vector <pair<int, int> > A;

int main() {

    int N;
    scanf("%d", &N);
    int len = 0;
    pair<int, int> temp;

    while (N--) {
        scanf("%s", s);
        if (strcmp(s, "Pop") == 0) {
            if (len == 0) {
                printf("Invalid\n");
            } else {
                temp = A.at(len - 1);
                printf("%d\n", temp.first);
                A.pop_back();
                --len;
                Rbtree.erase(temp);
            }
        } else if (strcmp(s, "PeekMedian") == 0) {
            if (len == 0) {
                printf("Invalid\n");
                continue;
            }
            if (len % 2 == 0) {
                printf("%d\n", Rbtree.find_by_order(len / 2 - 1)->first);
            } else {
                printf("%d\n", Rbtree.find_by_order((len - 1) / 2)->first);
            }
        } else {
            scanf("%d", &temp.first);
            temp.second = vis[temp.first];
            ++vis[temp.first];
            ++len;
            A.push_back(temp);
            Rbtree.insert(temp);
        }
    }
    return 0;
}
