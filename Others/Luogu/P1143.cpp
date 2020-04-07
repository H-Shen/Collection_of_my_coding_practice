#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    string a;
    cin >> n >> a >> m;
    ll a_num = stoll(a, nullptr, n);
    string result;
    while (a_num > 0) {
        ll temp = a_num % m;
        if (temp >= 10) {
            result.push_back(temp - 10 + 'A');
        } else {
            result.push_back(temp + '0');
        }
        a_num /= m;
    }
    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}