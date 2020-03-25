// https://www.nowcoder.com/practice/a9e943b0dab142759807d0cfb6863897
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> A(n + m);
    for (auto &i : A) scanf("%d", &i);
    inplace_merge(A.begin(), A.begin() + n, A.end());
    bool first_item = true;
    for (const auto &i : A) {
        if (first_item) {
            first_item = false;
        } else {
            printf(" ");
        }
        printf("%d", i);
    }
    printf("\n");

    return 0;
}