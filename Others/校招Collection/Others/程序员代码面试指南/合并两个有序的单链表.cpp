// https://www.nowcoder.com/practice/98a51a92836e4861be1803aaa9037440

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    scanf("%d", &n);
    vector<int> A(n);
    for (auto &i : A) {
        scanf("%d", &i);
    }
    scanf("%d", &m);
    A.resize(n + m);
    for (int i = n; i < n + m; ++i) {
        scanf("%d", &A.at(i));
    }
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