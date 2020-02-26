#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {
    int n;
    cin >> n;
    int a = 5 * n;
    int b = 11 + 3 * n;
    if (a < b) {
        cout << "Local" << endl;
    } else {
        cout << "Luogu" << endl;
    }
    return 0;
}
