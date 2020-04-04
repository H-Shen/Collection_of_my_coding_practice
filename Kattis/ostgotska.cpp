// https://open.kattis.com/problems/ostgotska
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr double EPS = 1e-7;

regex r("[a-z]+");

int sgn(const double &x) {
    if (x > EPS) return 1;
    if (x > -EPS) return 0;
    return -1;
}

bool check(const string &s) {
    int length = static_cast<int>(s.size());
    for (int i = 0; i < length - 1; ++i) {
        if (s.at(i) == 'a' && s.at(i + 1) == 'e') {
            return true;
        }
    }
    return false;
}

pair<int, int> split(const string &s) {
    int counter = 0;
    int length = 0;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it; it != end_it; ++it) {
        if (check(it->str())) {
            ++counter;
        }
        ++length;
    }
    return {counter, length};
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    getline(cin, s);
    auto p = split(s);
    if (sgn(p.first * 1.0 / p.second - 0.4) >= 0) {
        cout << "dae ae ju traeligt va" << '\n';
    } else {
        cout << "haer talar vi rikssvenska" << '\n';
    }
    return 0;
}
