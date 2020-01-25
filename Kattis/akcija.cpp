// https://open.kattis.com/problems/akcija
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<ll> A(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &A.at(i));
        sum += A.at(i);
    }
    sort(A.begin(), A.end(), [](const ll &lhs, const ll &rhs) {
        return (lhs > rhs);
    });
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        ++counter;
        if (counter == 3) {
            sum -= A.at(i);
            counter = 0;
        }
    }
    printf("%lld\n", sum);

    return 0;
}
