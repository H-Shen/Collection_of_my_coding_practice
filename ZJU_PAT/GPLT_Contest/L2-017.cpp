#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;
int List[maxn];
int len = 0;

int main() {

    int n, i;
    scanf("%d", &n);
    len = n;
    for (i = 0; i < n; ++i) {
        scanf("%d", &List[i]);
    }
    sort(List, List + n);

    if (n % 2 == 0) {
        printf("Outgoing #: %d\n", n / 2);
        printf("Introverted #: %d\n", n / 2);
        printf("Diff = %d\n", accumulate(List + n / 2, List + n, 0) - accumulate(List, List + n / 2, 0));
    } else {

        int forePart0 = accumulate(List, List + (n - 1) / 2, 0);
        int backPart0 = accumulate(List + (n - 1) / 2, List + n, 0);
        int forePart1 = forePart0 + List[(n - 1) / 2];
        int backPart1 = backPart0 - List[(n - 1) / 2];
        int diff0 = backPart0 - forePart0;
        int diff1 = backPart1 - forePart1;

        //(n - 1) / 2, (n + 1) / 2
        printf("Outgoing #: %d\n", (n + 1) / 2);
        printf("Introverted #: %d\n", (n - 1) / 2);
        if (diff0 > diff1) {
            printf("Diff = %d\n", diff0);
        }
            //(n + 1) / 2, (n - 1) / 2
        else {
            printf("Diff = %d\n", diff1);
        }
    }
    return 0;
}