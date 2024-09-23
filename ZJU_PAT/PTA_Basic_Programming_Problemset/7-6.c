#include <stdio.h>

int main() {
    float f1, f2;
    int i;
    char ch;

    scanf("%f %d %c %f", &f1, &i, &ch, &f2);
    printf("%c %d %.2f %.2f\n", ch, i, f1, f2);
    return 0;
}