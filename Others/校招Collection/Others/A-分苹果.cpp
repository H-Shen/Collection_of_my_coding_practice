// https://ac.nowcoder.com/acm/problem/14534

#include <iostream>

using namespace std;

int main()
{
    int t, n, m, k, tmp;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        tmp = (n + k) / m;
        if ( tmp >= 1 && (tmp * m >= n) ) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}