// https://open.kattis.com/problems/character
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ull = unsigned long long;

int main() {
    ull n;
    cin >> n;
    cout << (1ul << n) - 1 - n << '\n';
    return 0;
}
