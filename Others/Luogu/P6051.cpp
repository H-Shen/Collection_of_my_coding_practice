#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
vector<string> split_by_char(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

const string pattern("[-]{0,1}[0-9]+");
const regex r(pattern);

ll get_sum(const string &s, bool &has_digits) {
    ll temp;
    ll sum = 0;
    for (sregex_iterator it(s.begin(), s.end(), r), end_it;
         it != end_it; ++it) {
        has_digits = true;
        temp = stoll(it->str());
        try {
            if (it->str().front() == '-' && isdigit(s.at(it->position() - 1))) {
                temp = abs(temp);
            }
        } catch (...) {}
        sum += temp;
    }
    return sum;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    ll sum;
    bool has_digits;
    while (getline(cin, s)) {
        has_digits = false;
        auto p = split_by_char(s, '.');
        sum = 0;
        for (const auto &i : p) {
            sum += get_sum(i, has_digits);
        }
        if (has_digits) {
            cout << sum << '\n';
        }
    }
    return 0;
}
