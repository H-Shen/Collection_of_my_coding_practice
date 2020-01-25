// https://open.kattis.com/problems/register
//
#include <bits/extc++.h>

using namespace std;
using ll = long long;
constexpr int MAXN = 8;
constexpr ll UPPER = 9699689;

int main() {

    vector<ll> A(MAXN);
    for (auto &i : A) {
        scanf("%lld", &i);
    }
    vector<ll> B = {1,2,6,30,210,2310,30030,510510};
    ll sum = 0;
    for (int i = 0; i < MAXN; ++i) {
        sum += A.at(i) * B.at(i);
        if (sum > UPPER) {
            printf("0\n");
            return 0;
        }
    }
    printf("%lld\n", UPPER - sum);
    return 0;
}
