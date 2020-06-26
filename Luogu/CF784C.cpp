#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A) cin >> i;
    int result = *max_element(A.begin(), A.end()) ^ A.back();
    cout << result << '\n';

    return 0;
}