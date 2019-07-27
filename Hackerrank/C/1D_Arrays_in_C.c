#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    int sum = 0;
    int val = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &val);
        sum += val;
    }
    printf("%d\n", sum);

    return 0;
}
