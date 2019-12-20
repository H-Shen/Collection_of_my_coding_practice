// https://ac.nowcoder.com/acm/problem/15482

#include <stdio.h>

int main() {
    
    int n;
    scanf("%d", &n);
    while (n > 0) {
        printf("shang:%d yu:%d\n", n / 2, n % 2);
        n /= 2;
    }
    
    return 0;
}