#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

array<int, 5> stats;

int convert(const string &s) {
    int n = count(s.begin(), s.end(), '*');
    if (n == 0) {
        return 0;
    }
    if (n == 4) {
        return 1;
    }
    if (n == 8) {
        return 2;
    }
    if (n == 12) {
        return 3;
    }
    return 4;
}



int main() {

    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char> > A;
    int total = 5*n + 1;
    string s;
    for (int i = 0; i < total; ++i) {
        cin >> s;
        A.emplace_back(s.begin(), s.end());
    }
    int i_, j_;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            i_ = 5 * i + 1;
            j_ = 5 * j + 1;
            string s;
            for (int x = i_; x < i_ + 4; ++x) {
                for (int y = j_; y < j_ + 4; ++y) {
                    s.push_back(A.at(x).at(y));
                }
            }
            ++stats.at(convert(s));
        }
    }
    for (int i = 0; i < 4; ++i) {
        cout << stats.at(i) << ' ';
    }
    cout << stats.at(4) << '\n';

    return 0;
}