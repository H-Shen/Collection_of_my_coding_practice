// https://open.kattis.com/problems/harshadnumbers
//
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

inline static
bool isHarshad(const ll &a) {
    ll sumOfDigits = 0;
    ll a_copy = a;
    while (a_copy > 0) {
        sumOfDigits += a_copy % 10;
        a_copy /= 10;
    }
    return a % sumOfDigits == 0;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    while (!isHarshad(n)) {
        ++n;
    }
    cout << n << endl;


    return 0;
}
