// https://open.kattis.com/problems/volim
//
#include <bits/stdc++.h>

using namespace std;
constexpr int maxn = 5;
char s[maxn];

int main() {

    int k;
    scanf("%d", &k);
    int q;
    int time;
    int total = 30 + 3 * 60;
    scanf("%d", &q);
    while (q--) {
        scanf("%d %s", &time, s);
        total -= time;
        if (total < 0) {
            printf("%d\n", k);
            return 0;
        }
        if (strcmp(s, "T") == 0) {
            if (k == 8) {
                k = 1;
            } else {
                ++k;
            }
        }
    }
    
    return 0;
}
