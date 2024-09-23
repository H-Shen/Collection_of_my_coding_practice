// https://ac.nowcoder.com/acm/problem/14131

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {

    int n, tmp, i;
    int maxVal = -1;
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%d", &tmp);
        maxVal = max(maxVal, i + tmp);
    }
    printf("%d\n", maxVal);

    return 0;
}