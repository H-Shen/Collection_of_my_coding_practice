#include <bits/extc++.h>

using namespace std;

namespace BigInteger {

    static const int LEN = 1005;
    int a[LEN], b[LEN], c[LEN];

    void clear(int a[LEN]) {
        for (int i = 0; i < LEN; ++i) {
            a[i] = 0;
        }
    }

    void read(int a[LEN]) {
        static char s[LEN + 1];
        scanf("%s", s);
        clear(a);
        int len = strlen(s);
        for (int i = 0; i < len; ++i) {
            a[len - i - 1] = s[i] - '0';
        }
    }

    void print(int a[LEN]) {
        int i;
        for (i = LEN - 1; i >= 1; --i)
            if (a[i] != 0) {
                break;
            }
        for (; i >= 0; --i) {
            putchar(a[i] + '0');
        }
        putchar('\n');
    }

    void add(int a[LEN], int b[LEN], int c[LEN]) {
        clear(c);
        for (int i = 0; i < LEN - 1; ++i) {
            c[i] += a[i] + b[i];
            if (c[i] >= 10) {
                c[i + 1] += 1;
                c[i] -= 10;
            }
        }
    }
}

int main() {

    BigInteger::read(BigInteger::a);
    BigInteger::read(BigInteger::b);
    BigInteger::add(BigInteger::a, BigInteger::b, BigInteger::c);
    BigInteger::print(BigInteger::c);

    return 0;
}