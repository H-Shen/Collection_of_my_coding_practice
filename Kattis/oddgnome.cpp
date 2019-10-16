// https://open.kattis.com/problems/oddgnome
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, g;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &g);
        vector<int> A(g);
        for (auto &i : A) {
            scanf("%d", &i);
        }
        int last = A.front();
        for (int i = 1; i < g; ++i) {
            if (A.at(i) - last != 1) {
                printf("%d\n", i + 1);
                break;
            }
            last = A.at(i);
        }
    }

    return 0;
}
