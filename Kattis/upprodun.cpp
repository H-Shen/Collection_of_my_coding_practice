// https://open.kattis.com/problems/upprodun

#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char> > output;
    if (m % n == 0) {
        output.resize(n, vector<char>(m / n, '*'));
    }
    else {
        output.resize(n, vector<char>(m / n, '*'));
        int rest = m % n;
        for (int i = 0; i < rest; ++i) {
            output.at(i).push_back('*');
        }
    }
    for (const auto &i : output) {
        for (const auto &j : i) {
            cout << j;
        }
        cout << '\n';
    }

    return 0;
}
