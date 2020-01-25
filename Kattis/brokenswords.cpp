// https://open.kattis.com/problems/brokenswords
//
#include <bits/extc++.h>

using namespace std;

auto isEven = [](int a) { return a % 2 == 0; };
auto isOdd = [](int a) { return !isEven(a); };

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    string s;
    cin >> n;
    int a = 0, b = 0, c = 0, d = 0;
    int swords, stats1, stats2;
    while (n--) {
        cin >> s;
        for (int i = 0; i < 4; ++i) {
            if (s.at(i) == '0') {
                switch (i) {
                    case 0:
                        ++a;
                        break;
                    case 1:
                        ++b;
                        break;
                    case 2:
                        ++c;
                        break;
                    default:
                        ++d;
                        break;
                }
            }
        }
    }
    if (a + b < c + d) {
        if ( (isEven(a) && isOdd(b)) || (isOdd(a) && isEven(b)) ) {
            swords = (a + b - 1) / 2;
        } else {
            swords = (a + b) / 2;
        }
    } else {
        if ( (isEven(c) && isOdd(d)) || (isOdd(c) && isEven(d)) ) {
            swords = (c + d - 1) / 2;
        } else {
            swords = (c + d) / 2;
        }
    }
    stats1 = a + b - 2 * swords;
    stats2 = c + d - 2 * swords;
    cout << swords << ' ' << stats1 << ' ' << stats2 << endl;

    return 0;
}
