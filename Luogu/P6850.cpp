#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

constexpr int MAXN = 9;
array<int, MAXN> A;

int main() {

    for (auto &i : A) cin >> i;
    int sum = 50;
    for (int i = 0; i <= 6; ++i) {
        sum += A.at(i);
    }
    if (A.at(7)) {
        sum += 5;
    }
    if (sum >= A.at(8)) {
        cout << "AKIOI";
    } else {
        cout << "AFO";
    }
    cout << '\n';

    return 0;
}