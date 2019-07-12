// https://www.nowcoder.com/practice/1de017fdb316458fb3cadbf3f7bf7d1d

#include <stdio.h>
#include <stdbool.h>

void reversePrint(int x) {
    if (x < 10) {
        printf("%d", x);
        return;
    }
    reversePrint(x % 10);
    reversePrint(x / 10);
}

int main(void) {

    int n;
    scanf("%d", &n);
    bool isNeg = false;
    if (n < 0) {
        isNeg = true;
    }
    if (isNeg) {
        printf("-");
        n = -n;
    }
    while (n != 0 && n % 10 == 0) {
        n /= 10;
    }
    reversePrint(n);
    return 0;
}