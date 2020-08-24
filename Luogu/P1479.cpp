#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr int MAXN = 26;
constexpr array<int, MAXN> A =
        {-1, -1, -1, -1, -1, 1, 1, 1, 1, 3, 3, 3, 6, 6, 10, 10, 15, 21, 21, 28, 28,
         35, 30, 30, 27, 12};

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {

    fast_io();
    int n;
    cin >> n;
    cout << A.at(n) << '\n';

    return 0;
}
