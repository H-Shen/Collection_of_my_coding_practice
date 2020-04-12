#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "Today, I ate 1 apple.\n";
    } else if (n == 0) {
        cout << "Today, I ate 0 apple.\n";
    } else {
        cout << "Today, I ate " << n << " apples.\n";
    }
    return 0;
}