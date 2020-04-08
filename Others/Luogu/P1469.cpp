#include <cstdio>

int main() {

    int n, val;
    int result = 0;
    scanf("%d", &n);
    scanf("%d", &result);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &val);
        result ^= val;
    }
    printf("%d\n", result);
    
    return 0;
}