#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    const int maxn = 1005;
    const int digits = 10;
    char s[maxn];
    scanf("%s", s);
    
    int count[digits];
    for (int i = 0; i < digits; ++i) {
        count[i] = 0;
    }
    
    for (int i = 0; s[i] != '\0'; ++i) {
        if (isdigit(s[i])) {
            ++count[(size_t)(s[i] - '0')];
        }
    }
    
    for (int i = 0; i < digits - 1; ++i) {
        printf("%d ", count[i]);
    }
    printf("%d\n", count[digits - 1]);
    
    
    return 0;
}
