// https://open.kattis.com/problems/brokencalculator

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int n;
char op;
ll a, b, res;
ll last = 1;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%lld %c %lld", &a, &op, &b);
        switch (op) {
            case '+':
                res = a + b;
                res -= last;
                break;
            case '-':
                res = a - b;
                res *= last;
                break;
            case '*':
                res = a * b;
                res *= res;
                break;
            case '/':
                if (a & 1) {
                    res = (a + 1) / 2;
                } else {
                    res = a / 2;
                }
                break;
        }
        printf("%lld\n", res);
        last = res;
    }
    return 0;
}
