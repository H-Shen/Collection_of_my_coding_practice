// https://open.kattis.com/problems/cardboardcontainer
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int V, L, H, W;
    int min_cost = numeric_limits<int>::max();
    int cost;
    scanf("%d", &V);
    for (L = 1; L * L <= V; ++L) {
        for (H = 1; H * H <= V; ++H) {
            if (V % (L * H) == 0) {
                W = V / (L * H);
                cost = 2*(L*H + L*W + W*H);
                min_cost = min(min_cost, cost);
            }
        }
    }
    printf("%d\n", min_cost);

    return 0;
}
