#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    ll p;
    cin >> n >> p;
    vector<string> A(n);
    for (auto &i : A) cin >> i;
    reverse(A.begin(), A.end());
    ll number_of_apples = 0;
    ll counter_of_gifts = 0;
    for (const auto &i : A) {
        if (i == "half") {
            number_of_apples = 2 * number_of_apples;
        } else {
            number_of_apples = 2 * number_of_apples + 1;
            ++counter_of_gifts;
        }
    }
    cout << (2 * number_of_apples - counter_of_gifts) * p / 2 << endl;


    return 0;
}