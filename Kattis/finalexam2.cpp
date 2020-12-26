// https://open.kattis.com/problems/finalexam2
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<char> A(n);
    string s;
    for (auto &i : A) {
        cin >> s;
        i = s.front();
    }
    int counter = 0;
    for (int i = 1; i < n; ++i) {
        if (A.at(i) == A.at(i - 1)) {
            ++counter;
        }
    }
    cout << counter << '\n';

    return 0;
}
