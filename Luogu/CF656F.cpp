#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    for (const char &ch : s) {
        if (ch == 'A') {
            ++sum;
        } else if (ch == '1') {
            sum += 10;
        } else {
            sum += ch - '0';
        }
    }
    cout << sum << '\n';
    return 0;
}