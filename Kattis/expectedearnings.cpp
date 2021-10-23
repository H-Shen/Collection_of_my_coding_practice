// https://open.kattis.com/problems/expectedearnings

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int n, k;
double p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> p;
    double exp = (n-k)*p + (-k)*(1.0-p);
    if (exp < 0) {
        cout << "spela" << '\n';
    } else {
        cout << "spela inte!" << '\n';
    }

    return 0;
}
