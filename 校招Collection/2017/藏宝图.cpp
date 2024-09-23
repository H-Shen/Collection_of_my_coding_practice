// https://www.nowcoder.com/practice/74475ee28edb497c8aa4f8c370f08c30

#include <cstdio>
#include <cstring>

const int MAXLEN = 50;
char a[MAXLEN], b[MAXLEN];

int main() {

    scanf("%s %s", a, b);
    int i, j;
    int len_a = strlen(a), len_b = strlen(b);
    bool haveAns = true;

    if (len_b > len_a) {
        haveAns = false;
    } else {
        for (i = 0, j = 0; j < len_a; j++) {
            if (b[i] == a[j]) {
                i++;
            }
        }
        if (i != len_b) {
            haveAns = false;
        }
    }

    if (!haveAns) {
        printf("No\n");
    } else {
        printf("Yes\n");
    }

    return 0;
}