// https://www.nowcoder.com/practice/a35ce98431874e3a820dbe4b2d0508b1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INCREMENT 500

int main(void) {

    // Get the input string
    int threshold = 50;
    char ch;
    char *str = (char *) malloc(sizeof(char *) * threshold);

    int strLen = 0;
    do {
        scanf("%c", &ch);
        strLen++;
        if (strLen >= threshold) {
            threshold += INCREMENT;
            str = (char *) realloc(str, sizeof(char *) * (threshold));
        }
        str[strLen - 1] = (char) tolower(ch);
    } while (ch != '\n');

    str[strLen - 1] = '\0';

    // Get the input character
    scanf("%c", &ch);
    ch = (char) tolower(ch);
    int counter = 0;
    for (int i = 0; i < strLen; ++i) {
        if (str[i] == ch) {
            ++counter;
        }
    }

    // Output
    printf("%d\n", counter);

    return 0;
}
