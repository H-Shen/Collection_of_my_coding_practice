#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<string, string> > A(n);
    for (auto &i : A) {
        cin >> i.first;
        reverse_copy(i.first.begin(), i.first.end(), back_inserter(i.second));
    }
    sort(A.begin(), A.end(), [](const pair<string, string> &l, const pair<string, string> &r){
        return l.second < r.second;
    });
    for (const auto &i : A) {
        cout << i.first << '\n';
    }


    return 0;
}
