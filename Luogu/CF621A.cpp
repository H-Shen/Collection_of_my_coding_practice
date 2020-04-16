#include <cstdio>

#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {

    int n;
    scanf("%d", &n);
    vector<ll> A(n);
    ll sum = 0;
    for (auto &i : A) {
        scanf("%lld", &i);
        sum += i;
    }
    if (sum % 2 == 0) {
        printf("%lld\n", sum);
        return 0;
    }
    sort(A.begin(), A.end());
    ll temp;
    for (const auto &i : A) {
        temp = sum - i;
        if (temp % 2 == 0) {
            printf("%lld\n", temp);
            return 0;
        }
    }
    printf("0\n");
    return 0;
}