// https://open.kattis.com/problems/simpleaddition
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
constexpr int MAXN = 10005;

int a[MAXN];
int b[MAXN];
int c[MAXN];
char s[MAXN];

int main() {

    scanf("%s", s);
    int length = strlen(s);
    for (int i = 0; i < length; ++i) {
        a[i] = s[length - i - 1] - '0';
    }
    scanf("%s", s);
    length = strlen(s);
    for (int i = 0; i < length; ++i) {
        b[i] = s[length - i - 1] - '0';
    }
    for (int i = 0; i < MAXN - 1; ++i) {
        c[i] = c[i] + a[i] + b[i];
        if (c[i] >= 10) {
            ++c[i + 1];
            c[i] -= 10;
        }
    }
    // output
    int pos;
    for (pos = MAXN - 1; pos >= 1; --pos) {
        if (c[pos] != 0) {
            break;
        }
    }
    for (; pos >= 0; --pos) {
        putchar(c[pos] + '0');
    }
    puts("");
    return 0;
}
