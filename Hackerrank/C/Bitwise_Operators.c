#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
    int maxVal = 0;
    int a_max = maxVal, b_max = maxVal, c_max = maxVal;
    int a, b, c;
    
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            a = i & j;
            b = i | j;
            c = i ^ j;
            if (a > a_max && a < k) a_max = a;
            if (b > b_max && b < k) b_max = b;
            if (c > c_max && c < k) c_max = c;
        }
    }
    printf("%d\n%d\n%d\n", a_max, b_max, c_max);
    return;
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
