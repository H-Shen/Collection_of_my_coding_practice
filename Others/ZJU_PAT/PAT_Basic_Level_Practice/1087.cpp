#include <bits/stdc++.h>

using namespace std;

inline
int val(int n) {
    return static_cast<int>(floor(n / 2.0) + floor(n / 3.0) + floor(n / 5.0));
}

int main() {

    int n;
    unordered_set<int> A;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        A.insert(val(i));
    }
    printf("%d\n", static_cast<int>(A.size()));

    return 0;
}