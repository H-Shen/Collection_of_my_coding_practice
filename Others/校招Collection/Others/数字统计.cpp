// https://ac.nowcoder.com/acm/contest/238/D

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 6;
char num[MAXN];

int main() {

    int L, R;
    scanf("%d %d", &L, &R);
    int counter = 0;
    for (int i = L; i <= R; ++i) {
        sprintf(num, "%d", i);
        for (int j = 0; num[j] != '\0'; ++j) {
            if (num[j] == '2') {
                ++counter;
            }
        }
    }
    printf("%d\n", counter);

    return 0;
}