// https://open.kattis.com/problems/thanosthehero
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<ll> A(n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &A.at(i));
    }
    ll sum = 0;
    ll diff;
    for (int i = n - 1; i >= 0; --i) {
        if (i == n - 1) {
            continue;
        } else {
            if (A.at(i) >= A.at(i + 1)) {
                diff = (A.at(i) - A.at(i + 1)) + 1;
                A.at(i) = A.at(i + 1) - 1;
                if (A.at(i) < 0) {
                    sum = 1;
                    break;
                }
                sum += diff;
            }
        }
    }
    printf("%lld\n", sum);


    return 0;
}
