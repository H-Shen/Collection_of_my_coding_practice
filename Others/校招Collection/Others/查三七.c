// https://ac.nowcoder.com/acm/problem/15376

#include <stdio.h>
#include <string.h>

typedef long long ll;

int main() {

    ll n;
    scanf("%lld", &n);
    if (n % 3 == 0 || n % 7 == 0) {
        printf("1\n");
        return 0;
    }
    char s[30];
    sprintf(s, "%lld", n);
    if (strstr(s, "3") || strstr(s, "7")) {
        printf("1\n");
        return 0;
    }
    printf("0\n");

    return 0;
}
