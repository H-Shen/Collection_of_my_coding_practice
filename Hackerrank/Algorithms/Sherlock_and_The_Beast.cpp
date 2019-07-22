#include <cmath>
#include <cstdio>

using namespace std;

int exgcd(int a, int b, int &x, int &y) {

    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int tp = x;
    x = y;
    y = tp - a / b * y;
    return r;
}

void solution(int a, int b, int c, int d, int &x, int &y) {

    if (a && b == 0) {
        x = c / a;
        y = -c / a;
        return;
    }

    if (a == 0 && b) {
        x = 1;
        y = c / b;
        return;
    }

    a /= d, b/= d, c /= d;
    x *= c;
    y *= c;

    int tx = x;
    x %= b;
    if (x < 0) {
        x += (int)abs(b * 1.0);
        int k = (tx - x) / b;
        y += k * a;
    }
    else if (x == 0) {
        y = c / b;
    }

    return;
}


int main() {

    int n, c, x, y, i;
    int a = 5, b = 3, d = 0;
    scanf("%d", &n);

    while (n--) {

        scanf("%d", &c);
        d = exgcd(a, b, x, y);

        if (c % d != 0) {
            printf("-1\n");  //no solutions
        }
        else {
            solution(a, b, c, d, x, y);
            if (x < 0 || y < 0) {
                printf("-1");  //no solutions
            }
            else {
                for (i = 0; i < 3 * y; ++i) {
                    printf("5");
                }
                for (i = 0; i < 5 * x; ++i) {
                    printf("3");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
