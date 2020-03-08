// https://open.kattis.com/problems/pascal
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ll n;
    scanf("%lld", &n);
    if (n == 1) {
        printf("0\n");
    } else {
        unordered_set<ll> A;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                A.insert(i);
                A.insert(n / i);
            }
        }
        vector<ll> output(A.begin(), A.end());
        sort(output.begin(), output.end());
        output.pop_back();
        printf("%lld\n", n - output.back());
    }
    
    return 0;
}
