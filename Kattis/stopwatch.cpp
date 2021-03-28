// https://open.kattis.com/problems/stopwatch

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    int last = -1;
    int cur;
    bool run = false;
    int counter = 0;
    while (n--) {
        cin >> cur;
        if (!run) {
            run = true;
            last = cur;
        } else {
            run = false;
            counter += cur - last;
        }
    }
    if (run) cout << "still running\n";
    else cout << counter << '\n';

    return 0;
}
