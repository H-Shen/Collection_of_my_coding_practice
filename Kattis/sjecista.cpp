// https://open.kattis.com/problems/sjecista
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    int n;
    cin >> n;
    cout << n * (n - 1) * (n - 2) * (n - 3) / 24 << '\n';
    return 0;
}
