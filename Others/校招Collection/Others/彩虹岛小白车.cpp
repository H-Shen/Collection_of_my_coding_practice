// https://ac.nowcoder.com/acm/problem/14665

#include <iostream>

using namespace std;

int main()
{
    int n, a, b, c, d;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c >> d;
        int gap = c - d + b;
        if (gap >= a) cout << "Walk" << endl;
        else cout << "Bus" << endl;
    }
    return 0;
}