#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    char A[][10] = {"one", "two", "three",
                          "four", "five", "six",
                          "seven", "eight", "nine"};
    for (int n = a; n <= b; ++n) {
        if (n > 9) {
            if (n & 1) {
                printf("odd\n");
            }
            else {
                printf("even\n");
            }
        } else {
            printf("%s\n", *(A + n - 1));
        }
    }

    return 0;
}

