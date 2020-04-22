#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 105;
char cstr[MAXN];

int main() {

    int n;
    scanf("%d %s", &n, cstr);
    int counter = 0;
    int total = 0;
    for (int i = 0; cstr[i] != 0; ++i) {
        if (cstr[i] == 'x') {
            ++counter;
        } else if (counter > 0) {
            if (counter > 2) {
                total += counter - 2;
            }
            counter = 0;
        }
    }
    if (counter > 2) {
        total += counter - 2;
    }

    printf("%d\n", total);

    return 0;
}