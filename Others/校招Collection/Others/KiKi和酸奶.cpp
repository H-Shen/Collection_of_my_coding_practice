// https://www.nowcoder.com/practice/c7721f3a1b1a47a783974453e82cadbb?tpId=107
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, h;
    while (~scanf("%d %d %d", &n, &h, &m)) {
        int cost = m / h;
        if (m % h != 0) {
            ++cost;
        }
        printf("%d\n", n - cost);
    }
    return 0;
}