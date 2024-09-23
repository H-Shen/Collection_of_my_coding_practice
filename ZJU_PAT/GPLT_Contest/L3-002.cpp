#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

int main() __attribute__((optimize("-O3")));

using namespace std;
using namespace __gnu_pbds;

const int MAXN = 20, MAXITEM = 100005;
char s[MAXN];
int vis[MAXITEM] = {0};

struct Node {
    int first;
    int second;

    bool operator<(const Node &other) const {
        if (first == other.first) {
            return (second < other.second);
        }
        return (first < other.first);
    }
};

tree<Node, null_type, less<Node>, rb_tree_tag,
        tree_order_statistics_node_update> Rbtree;
vector<Node> A;

int main() {
    int N;
    scanf("%d", &N);
    int len = 0;
    Node temp;

    while (N--) {
        scanf("%s", s);
        if (strcmp(s, "Pop") == 0) {
            if (len == 0) {
                printf("Invalid\n");
            } else {
                temp = A[len - 1];
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
                printf("%d\n", (*Rbtree.find_by_order(len / 2 - 1)).first);
            } else {
                printf("%d\n", (*Rbtree.find_by_order((len - 1) / 2)).first);
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
