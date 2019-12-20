#include <stdio.h>

// Simulate ForEach in C

void ForEach(void *a, int width, int num,
             void (*f)(void *)) {
    for (int i = 0; i < num; ++i)
        f((char *) a + width * i);
}

void PrintSquare(void *p) {
    int *q = (int *) p;
    int n = *q;
    printf("%d, ", n * n);
}

void PrintChar(void *p) {
    char *q = (char *) p;
    printf("%c, ", *q);
}

int main(void) {
    int a[5] = {1, 2, 3, 4, 5};
    char s[] = "hello!";
    ForEach(a, sizeof(int), 5, PrintSquare);
    puts("");
    ForEach(s, sizeof(char), 6, PrintChar);
    return 0;
}