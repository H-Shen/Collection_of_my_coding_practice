// https://open.kattis.com/problems/dst
//
#include <iostream>

using namespace std;

int main() {

    int n;
    string s;
    int a, b, c, total;
    cin >> n;
    while (n--) {
        cin >> s >> a >> b >> c;
        total = b * 60 + c;
        if (s == "B") {
            total -= a;
        } else {
            total += a;
        }
        if (total < 0) {
            total = 24 * 60 + total;
        } else if (total >= 24 * 60) {
            total -= 24 * 60;
        }
        b = total / 60;
        c = total % 60;
        cout << b << ' ' << c << endl;
    }

    return 0;
}
