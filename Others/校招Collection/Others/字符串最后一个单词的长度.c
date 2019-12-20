// https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da

#include <stdio.h>
#include <string.h>

#define MAXN 5005

char s[MAXN];

int main(void) {

    size_t length = 0;
    while (~scanf("%s", s)) {
        length = strlen(s);
    }
    printf("%lu\n", length);

    return 0;
}