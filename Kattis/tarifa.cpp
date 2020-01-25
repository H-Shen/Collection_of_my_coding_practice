// https://open.kattis.com/problems/tarifa

#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int x, n, currentMonthData;
    cin >> x >> n;
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        cin >> currentMonthData;
        cnt = cnt + x - currentMonthData;
    }
    cnt = cnt + x;
    cout << cnt << endl;

    return 0;
}
