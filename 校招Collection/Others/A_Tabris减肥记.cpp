// https://ac.nowcoder.com/acm/problem/14535

#include <iostream>

using namespace std;

int main()
{
    int n, w, t, cnt;
    cin >> n;
    while (n--) {
        cin >> w >> t;
        cnt = 0;
        while (w > 120) {
            w -= t;
            ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}