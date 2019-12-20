// https://ac.nowcoder.com/acm/problem/14741

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t, a, b, c, d;
    bool change;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c >> d;
        change = true;
        while (1) {
            if (a <= 0) {
                cout << "Yes" << endl;
                break;
            }
            if (b <= 0) {
                cout << "No" << endl;
                break;
            }
            if (change) {
                a -= d;
                change = false;
            } else {
                b -= c;
                change = true;
            }
        }
    }

    return 0;
}