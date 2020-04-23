#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

vector<ll> A;

int main() {

    ll M;
    scanf("%lld", &M);
    A.emplace_back(0 % M);
    A.emplace_back(1 % M);
    int n = 1;
    while (true) {
        A.emplace_back((A.at(A.size() - 2) + A.at(A.size() - 1)) % M);
        if (A.at(A.size() - 2) == 0 && A.at(A.size() - 1) == 1) {
            printf("%d\n", n);
            break;
        }
        ++n;
    }
    return 0;
}