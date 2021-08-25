// https://open.kattis.com/problems/fizzbuzz2

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

string f(int n) {
    if (n % 15 == 0) {
        return "fizzbuzz";
    }
    else if (n % 3 != 0 && n % 5 != 0) {
        return to_string(n);
    }
    else if (n % 3 == 0 && n % 5 != 0) {
        return "fizz";
    }
    return "buzz";
}

constexpr int MAXN = 105;
string s[MAXN];

int main() {
    for (int i = 1; i < MAXN; ++i) {
        s[i] = f(i);
    }
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    string str;
    vector<pair<int,int> > A(n);
    for (int i = 0; i < n; ++i) {
        A[i].first = i + 1;
        for (int j = 1; j <= m; ++j) {
            cin >> str;
            if (str == s[j]) {
                ++A[i].second;
            }
        }
    }
    cout << min_element(A.begin(),A.end(),[](const auto &l, const auto &r){
        if (l.second == r.second) {
            return l.first < r.first;
        }
        return l.second > r.second;
    })->first << '\n';
    return 0;
}
