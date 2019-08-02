// https://www.nowcoder.com/practice/c7d5def10ad942629df21483c89118df

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", i);
    }
    printf("\n");

    return 0;
}