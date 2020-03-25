// https://www.nowcoder.com/practice/35a1e8b18658411388bc1672439de1d9
// Compiled in C++14(g++5.4)

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 31;

int main() {
    vector<int> A = {1};
    while (A.size() < MAXN) {
        A.emplace_back(A.back() << 1);
    }
    int n;
    while (~scanf("%d", &n)) {
        printf("%d\n", A.at(n));
    }
    return 0;
}