// https://open.kattis.com/problems/guessinggame
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string a, b;
    int lower = 1;
    int upper = 10;
    bool inconsistent = false;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        cin >> a >> b;
        if (b == "on") {
            // last check
            if (n > upper || n < lower) {
                inconsistent = true;
            }
            // output
            if (!inconsistent) {
                cout << "Stan may be honest" << '\n';
            } else {
                cout << "Stan is dishonest" << '\n';
            }
            // reset
            inconsistent = false;
            lower = 1;
            upper = 10;
        } else if (b == "high" && !inconsistent) {
            if (n <= lower) {
                inconsistent = true;
            } else if (n - 1 < 1) {
                inconsistent = true;
            } else if (n > upper) {
                continue;
            } else {
                upper = n - 1;
            }
        } else if (b == "low" && !inconsistent) {
            if (n >= upper) {
                inconsistent = true;
            } else if (n + 1 > 10) {
                inconsistent = true;
            } else if (n < lower) {
                continue;
            } else {
                lower = n + 1;
            }
        }
    }

    return 0;
}
