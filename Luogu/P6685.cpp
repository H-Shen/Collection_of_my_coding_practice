#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    int n, m;
    cin >> n >> m;
    int x = (int)pow(n * 1.0, 1.0 / m);
    cout << x << endl;

    return 0;
}