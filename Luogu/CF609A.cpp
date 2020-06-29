#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (auto &i : A) cin >> i;
    sort(A.begin(), A.end(), greater<>());
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        if (m > 0) {
            m -= A.at(i);
            ++counter;
        } else {
            break;
        }
    }
    cout << counter << '\n';
    return 0;
}
