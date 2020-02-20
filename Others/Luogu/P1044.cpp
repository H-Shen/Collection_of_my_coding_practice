#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

/*
from math import factorial as f
def k(n):
    return f(2 * n) // (f(n) * f(n))
def C(n):
    return k(n) // (n + 1)
A = [C(i) for i in range(0, 19)]
*/

vector<ll> A = {
        1,
        1,
        2,
        5,
        14,
        42,
        132,
        429,
        1430,
        4862,
        16796,
        58786,
        208012,
        742900,
        2674440,
        9694845,
        35357670,
        129644790,
        477638700
};

int main() {

    int n;
    cin >> n;
    cout << A.at(n) << endl;

    return 0;
}
