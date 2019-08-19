#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int cnt_j = 0, cnt_y = 0, a_j, b_j, a_y, b_y, s;

    while (n--) {
        scanf("%d %d %d %d", &a_j, &b_j, &a_y, &b_y);
        s = a_j + a_y;
        if (b_j == s && b_y != s) {
            cnt_y++;
        } else if (b_j != s && b_y == s) {
            cnt_j++;
        }
    }
    printf("%d %d\n", cnt_j, cnt_y);
    return 0;
}