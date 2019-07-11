// https://www.nowcoder.com/practice/7dd312bb4e7c4546a9aa8a001c2b11f5

#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int main() {

    int n;
    int minVal = INT_MAX;
    while (~scanf("%d", &n)) {
        minVal = min(minVal, n);
    }
    printf("%d\n", minVal);

    return 0;
}