// https://www.nowcoder.com/practice/34d3911bf2fd48a285f6396e886a1259
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    auto p = div(a, b);
    printf("%d %d\n", p.quot, p.rem);
    return 0;
}