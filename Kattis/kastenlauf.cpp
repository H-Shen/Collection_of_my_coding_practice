// https://open.kattis.com/problems/kastenlauf
//
// dfs example
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAX_WEIGHT = 1000;

struct Node {
    int x, y;
};

vector<Node> A;
vector<bool> vis;
int n;

void dfs(int u) {
    // Base case
    if (vis.at(u)) {
        return;
    }
    vis.at(u) = true;
    for (int i = 0; i < n; ++i) {
        if (i != u && abs(A.at(u).x - A.at(i).x) + abs(A.at(u).y - A.at(i).y) <= MAX_WEIGHT) {
            dfs(i);
        }
    }
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        n += 2;
        vector<Node>().swap(A);
        vector<bool>().swap(vis);
        A.resize(n);
        vis.resize(n, false);
        for (auto &i : A) {
            scanf("%d %d", &i.x, &i.y);
        }
        dfs(0); // Since 0 is the index of jo's home
        if (vis.at(n - 1)) {
            printf("happy\n");
        } else {
            printf("sad\n");
        }
    }

    return 0;
}
