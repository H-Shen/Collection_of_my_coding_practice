#include <bits/stdc++.h>

int gcd(int a, int b) {
    if (a < 0)
        return gcd(-a, b);
    return (b > 0) ? gcd(b, a % b) : a;
}

void test(int a, int b, int c, int d, char op) {

    int x0, y0, x1, y1, x2, y2, x3, y3;
    bool negative = false;

    y0 = b * c + d * a;
    x0 = a * c;
    y1 = b * c - d * a, x1 = a * c;
    y2 = b * d;
    x2 = a * c;
    y3 = b * c;
    x3 = a * d;

    if (y1 < 0) {
        negative = true;
        y1 = -y1;
    }

    int Gcd0 = gcd(x0, y0);
    x0 /= Gcd0;
    y0 /= Gcd0;
    int Gcd1 = gcd(x1, y1);
    x1 /= Gcd1;
    y1 /= Gcd1;
    int Gcd2 = gcd(x2, y2);
    x2 /= Gcd2;
    y2 /= Gcd2;
    int Gcd3 = gcd(x3, y3);
    x3 /= Gcd3;
    y3 /= Gcd3;

    if (op == '+')
        printf("%d/%d\n", y0, x0);
    else if (op == '-') {
        if (negative)
            printf("%d/%d\n", -y1, x1);
        else
            printf("%d/%d\n", y1, x1);
    } else if (op == '*')
        printf("%d/%d\n", y2, x2);
    else
        printf("%d/%d\n", y3, x3);
}

int main() {
    int a, b, c, d;
    char op;
    while (scanf("%d/%d %d/%d %c", &b, &a, &d, &c, &op) != EOF)
        test(a, b, c, d, op);
    return 0;
}