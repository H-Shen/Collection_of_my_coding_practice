#include <bits/extc++.h>

using namespace std;
using ll = long long;

constexpr int MAXN = 3;

int main() {

    vector<int> A(MAXN);
    for (auto &i : A) {
        cin >> i;
    }
    sort(A.begin(), A.end());
    cout << A[1] - A[0] + A[2] - A[1] << '\n';

    return 0;
}
