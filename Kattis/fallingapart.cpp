// https://open.kattis.com/problems/fallingapart
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);
    vector<int> A(static_cast<size_t>(n));
    for (auto &i : A) {
        scanf("%d", &i);
    }
    sort(A.begin(), A.end(),  greater<>());
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            a += A.at(i);
        } else {
            b += A.at(i);
        }
    }
    printf("%d %d\n", a, b);

    return 0;
}
