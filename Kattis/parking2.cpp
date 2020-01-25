// https://open.kattis.com/problems/parking2

#include <bits/extc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int maxVal = -1;
    int minVal = 105;
    int n, cnt, val;
    cin >> n;
    while (n--) {
        cin >> cnt;
        maxVal = -1;
        minVal = 105;
        while (cnt--) {
            cin >> val;
            maxVal = max(maxVal, val);
            minVal = min(minVal, val);
        }
        cout << (maxVal - minVal) * 2 << endl;
    }
    return 0;
}
