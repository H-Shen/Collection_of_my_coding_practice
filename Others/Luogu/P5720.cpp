#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {
    ll a;
    cin >> a;
    int counter = 1;
    while (a != 1) {
        a /= 2;
        ++counter;
    }
    cout << counter << endl;
    return 0;
}