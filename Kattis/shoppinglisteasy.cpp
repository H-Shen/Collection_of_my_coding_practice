// https://open.kattis.com/problems/shoppinglisteasy

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<int, int>;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<string> > A(n, vector<string>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A.at(i).at(j);
        }
    }
    for (auto &i : A) sort(i.begin(), i.end());
    if (n == 1) {
        cout << m << '\n';
        for (const auto &i : A.front()) {
            cout << i << '\n';
        }
    }
    else {
        vector<string> result = A.front();
        for (int i = 1; i < n; ++i) {
            vector<string> temp;
            set_intersection(A[i].begin(), A[i].end(), result.begin(), result.end(), back_inserter(temp));
            result = temp;
        }
        cout << result.size() << '\n';
        for (const auto &i : result) {
            cout << i << '\n';
        }
    }

    return 0;
}
