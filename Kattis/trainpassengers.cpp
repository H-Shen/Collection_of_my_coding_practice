// https://open.kattis.com/problems/trainpassengers
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll c;
    int n;
    scanf("%lld %d", &c, &n);
    ll current = 0;
    ll out;
    ll in;
    ll stay;
    bool haveAns = true;
    for (int i = 0; i < n; ++i) {
        scanf("%lld %lld %lld", &out, &in, &stay);
        if (current < out) {
            haveAns = false;
            break;
        }
        current = current - out + in;
        if (current > c || current < 0) {
            haveAns = false;
            break;
        }
        if (current < c && stay > 0) {
            haveAns = false;
            break;
        }
        if (i == n - 1 && (stay > 0 || current != 0) ) {
            haveAns = false;
            break;
        }
    }
    if (haveAns) {
        printf("possible\n");
    } else {
        printf("impossible\n");
    }

    return 0;
}
