// https://open.kattis.com/problems/cprnummer

#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> a;
    vector<int> v = {4,3,2,7,6,5,4,3,2,1};
    for (auto&i : s) {
        if (i != '-') a.emplace_back(i - '0');
    }
    int temp = 0;
    for (size_t i = 0; i != v.size(); ++i) {
        temp += a[i]*v[i];
    }
    if (temp % 11 == 0) {
        cout << '1' << '\n';
    } else {
        cout << '0' << '\n';
    }
    return 0;
}
