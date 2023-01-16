#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string a, b;
    cin >> a >> b;
    int n = (int)a.size();
    int cnt = 0;
    for (int i = 0; i < n-1; ++i) {
        if (a[i] != b[i]) {
            ++cnt;
            a[i] = b[i];
            if (a[i+1] == '*') {
                a[i+1] = 'o';
            }
            else {
                a[i+1] = '*';
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}