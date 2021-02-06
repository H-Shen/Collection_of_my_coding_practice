#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<string> A(n);
    for (auto &i : A) cin >> i;
    sort(A.begin(), A.end(), [](const string &a, const string &b){
        return a + b > b + a;
    });
    for (const string &i : A) {
        cout << i;
    }
    cout << '\n';


    return 0;
}
