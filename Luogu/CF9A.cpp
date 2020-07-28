#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    int y, w;
    cin >> y >> w;
    int counter = 0;
    int d = max(y, w);
    while (d <= 6) {
        ++counter;
        ++d;
    }
    int temp = 6;
    int temp_gcd = __gcd(temp, counter);
    temp /= temp_gcd;
    counter /= temp_gcd;
    cout << counter << '/' << temp << '\n';
    return 0;
}