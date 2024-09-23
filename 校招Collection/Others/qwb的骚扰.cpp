// https://ac.nowcoder.com/acm/problem/14743

#include <iostream>

using namespace std;

int main()
{
    int t, n, x, y;
    cin >> t;
    int time = 0;
    while (t--) {
        time = 0;
        cin >> n >> x >> y;
        if (n < x) time = 0;
        else if (x <= 3 * y) {  // if x/3 is smaller than y, then he could hang off at exactly 3min and dial again
            time = 3 * (n / x);
            n = n - x * (n / x);
            time += n / y;
        } else {
            time = 3 + (n - x) / y;
        }
        cout << time << endl;
    }
    return 0;
}