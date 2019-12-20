// https://www.nowcoder.com/practice/7dd312bb4e7c4546a9aa8a001c2b11f5

#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;
    int minVal = numeric_limits<int>::max();
    while (~scanf("%d", &n)) {
        minVal = min(minVal, n);
    }
    printf("%d\n", minVal);

    return 0;
}