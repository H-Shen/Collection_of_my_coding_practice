#include <iostream>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n;
    cin >> n;
    if (n <= 2) {
        cout << 2 << '\n';
    } else if (n % 2 == 0) {
        cout << n << '\n';
    } else {
        cout << n * 2 << '\n';
    }

    return 0;
}