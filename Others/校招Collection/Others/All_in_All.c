// https://www.nowcoder.com/practice/f7a802e07bf5462c88ab99d490cebc9d

#include <stdio.h>
#include <stdbool.h>

#define maxn 100005

char s[maxn], t[maxn];

int main(void) {

    int i, j;
    bool haveAns;

    while (~scanf("%s %s", s, t)) {

        haveAns = false;
        for (i = 0, j = 0; s[i] != '\0'; ++i) {
            if (s[i] == t[j]) {
                ++j;
                if (t[j] == '\0') {
                    haveAns = true;
                    break;
                }
            }
        }
        if (haveAns)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}