// https://open.kattis.com/problems/skruop

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

int main() {
    int n;
    string a, b;
    int v = 7;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        if (b[0] == 'o') {
            if (v < 10) {
                ++v;
            }
        }
        else {
            if (v > 0) {
                --v;
            }
        }
    }
    cout << v << '\n';
    return 0;
}
