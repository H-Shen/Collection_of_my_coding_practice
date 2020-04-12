#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> A(n);
    for (auto &i : A) {
        cin >> i;
    }
    sort(A.begin(), A.end(), [](const string &lhs, const string &rhs){
        return (lhs + rhs > rhs + lhs);
    });
    cout << accumulate(A.begin(), A.end(), string()) << '\n';

    return 0;
}
