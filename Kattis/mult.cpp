// https://open.kattis.com/problems/mult

#include <bits/extc++.h>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int val = -1;
    --n;
    int temp;
    while (n--) {
        if (val == -1) {
            cin >> val;
        }
        else {
            cin >> temp;
            if (temp % val == 0) {
                cout << temp << '\n';
                val = -1;
            }
        }
    }
    return 0;
}
