#include <bits/extc++.h>

using namespace std;

int main() {

    int m, t, s;
    cin >> m >> t >> s;
    if (s < t) {
        if (m > 0) {
            --m;
        }
    } else {
        while (s > t) {
            if (m > 0) {
                --m;
            }
            s -= t;
        }
        if (m > 0) {
            --m;
        }
    }
    cout << m << endl;

    return 0;
}