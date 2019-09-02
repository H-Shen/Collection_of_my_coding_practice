// https://open.kattis.com/problems/speedlimit
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    int sum;
    int val;
    int currentTime;
    int lastTime;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        sum = 0;
        lastTime = -1;
        while (n--) {
            cin >> val >> currentTime;
            if (lastTime == -1) {
                sum += val * currentTime;
            } else {
                sum += val * (currentTime - lastTime);
            }
            lastTime = currentTime;
        }
        cout << sum << " miles" << endl;
    }

    return 0;
}
