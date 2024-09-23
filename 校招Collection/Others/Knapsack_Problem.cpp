// https://ac.nowcoder.com/acm/problem/13882

#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int T, n, w, d, i, w_total, d_total, tmp;
    cin >> T;
    while (T--) {
        cin >> n >> w >> d;
        w_total = 0, d_total = 0;
        for (i = 0; i < n; ++i) {
            cin >> tmp;
            w_total += tmp;
        }
        for (i = 0; i < n; ++i) {
            cin >> tmp;
            d_total += tmp;
        }
        if (w_total <= w && d_total <= d) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}