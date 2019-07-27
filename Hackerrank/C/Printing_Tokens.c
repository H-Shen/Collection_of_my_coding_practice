#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.

    int len = strlen(s);
    int onlyOneSpace = 0;

    for (int i = 0; i < len; ++i) {
        if (s[i] != ' ') {
            putchar(s[i]);
            onlyOneSpace = 0;
        } else if (onlyOneSpace != 1) {
            onlyOneSpace = 1;
            putchar('\n');
        }
    }

    if (onlyOneSpace == 0) {
        putchar('\n');
    }

    return 0;
}
