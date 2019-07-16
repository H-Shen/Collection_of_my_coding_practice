#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define maxn 10005

char a[maxn];
char b[maxn];
char c;

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%c %s", &c, a);
    getchar();
    scanf("%[^\n]", b);
    printf("%c\n%s\n%s\n", c, a, b);
    
    return 0;
}