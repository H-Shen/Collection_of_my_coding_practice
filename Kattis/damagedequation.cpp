// https://open.kattis.com/problems/damagedequation

#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

int main() {

    int a, b, c, d, l, r;
    cin >> a >> b >> c >> d;
    vector<char> op = {'+','-','*','/'};
    vector<int> left(2);
    vector<int> right(2);
    vector<pair<string, vector<int> > > result;
    string s;
    for (const auto &i : op) {
        for (const auto &j : op) {
            if (i == '/' && b == 0) {
                continue;
            }
            if (j == '/' && d == 0) {
                continue;
            }
            switch (i) {
                case '+': l = a + b; break;
                case '-': l = a - b; break;
                case '*': l = a * b; break;
                case '/': l = a / b; break;
                default: break;
            }
            switch (j) {
                case '+': r = c + d; break;
                case '-': r = c - d; break;
                case '*': r = c * d; break;
                case '/': r = c / d; break;
                default: break;
            }
            if (l == r) {
                s = to_string(a) + " " + i + " " + to_string(b) + " = " +
                        to_string(c) + " " + j + " " + to_string(d);
                result.emplace_back(s, vector<int>{a, (int)i, b, c, (int)j, d});
            }
        }
    }
    sort(result.begin(), result.end(), [](const auto &lhs, const auto &rhs){
        return lhs.second < rhs.second;
    });
    if (result.empty()) {
        cout << "problems ahead" << '\n';
    }
    else {
        for (const auto &[i, j] : result) {
            cout << i << '\n';
        }
    }
    return 0;
}
