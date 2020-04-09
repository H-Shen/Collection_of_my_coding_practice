// https://open.kattis.com/problems/sodaslurper
//
#include <bits/extc++.h>

using namespace std;

int main() {

    int a, b, e, c, f;
    scanf("%d %d %d", &e, &c, &f);
    int cnt = 0;
    e += c;
    while (true) {
        a = e / f;
        b = e % f;
        cnt += a;
        if (a == 0) {
            break;
        }
        e = a + b;
    }
    printf("%d\n", cnt);

    return 0;
}
