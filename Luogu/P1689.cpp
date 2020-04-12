#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

regex r0("([0-9]+|\\?)");
regex r1("(\\+|\\-|=)");

int main() {

    string s_;
    getline(cin, s_);
    string s;
    for (const char &i : s_) {
        if (i != ' ') {
            s.push_back(i);
        }
    }
    vector<string> expr;
    for (sregex_iterator it(s.begin(), s.end(), r0), end_it; it != end_it; ++it) {
        expr.emplace_back(it->str());
    }
    vector<string> Operator;
    for (sregex_iterator it(s.begin(), s.end(), r1), end_it; it != end_it; ++it) {
        Operator.emplace_back(it->str());
    }
    bool add = false;
    if (Operator.front() == "+") {
        add = true;
    }
    ll x, y, z;
    if (expr.at(0) == "?") {
        y = stoll(expr.at(1));
        z = stoll(expr.at(2));
        if (add) {
            x = z - y;
        }
        else {
            x = z + y;
        }
        cout << x << '\n';
    }
    else if (expr.at(1) == "?") {
        x = stoll(expr.at(0));
        z = stoll(expr.at(2));
        if (add) {
            y = z - x;
        }
        else {
            y = x - z;
        }
        cout << y << '\n';
    }
    else {
        x = stoll(expr.at(0));
        y = stoll(expr.at(1));
        if (add) {
            z = x + y;
        }
        else {
            z = x - y;
        }
        cout << z << '\n';
    }

    return 0;
}
