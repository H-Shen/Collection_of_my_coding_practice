// https://open.kattis.com/problems/combinatorialstanleycup

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;
using ll = long long;

int main() {
    int n;
    cin >> n;
    cout << (1LL<<(__builtin_popcount(n))) << '\n';
    return 0;
}
