#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n;
    cin >> n;
    --n;

    int a = 0;
    int b = 1;

    while (n > 0) {
        a = (b + 1) * 2;
        b = a;
        --n;
    }
    cout << a << endl;
    return 0;
}