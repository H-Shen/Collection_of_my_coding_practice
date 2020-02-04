// https://open.kattis.com/problems/bubbletea
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

vector<ll> A;
vector<ll> B;
vector<ll> Toppings;

int main() {

    int n;
    scanf("%d", &n);
    A.resize(n);
    B.resize(n, -1);
    for (auto &i : A) {
        scanf("%lld", &i);
    }
    int topping, length;
    ll val, price;
    scanf("%d", &topping);
    Toppings.resize(topping);
    for (int i = 0; i < topping; ++i) {
        scanf("%lld", &Toppings.at(i));
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &length);
        for (int j = 0; j < length; ++j) {
            scanf("%lld", &val);
            if (B.at(i) == -1) {
                B.at(i) = Toppings.at(val - 1);
            } else {
                B.at(i) = min(B.at(i), Toppings.at(val - 1));
            }
        }
    }
    scanf("%lld", &price);
    ll min_val = numeric_limits<ll>::max();
    for (int i = 0; i < n; ++i) {
        min_val = min(min_val, A.at(i) + B.at(i));
    }
    ll result = price / min_val - 1;
    if (result < 0) {
        result = 0;
    }
    printf("%lld\n", result);

    return 0;
}
