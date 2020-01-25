// https://open.kattis.com/problems/babylonian
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

vector<ll> powerOfSixty = {1, 60};

inline static
vector<ll> parse(const string &s) {
    vector<ll> p;
    string temp_str;
    int n = static_cast<int>(s.size());
    for (int i = 0; i < n; ++i) {
        if (s.at(i) == ',') {
            if (temp_str.empty()) {
                p.emplace_back(0);
            } else {
                p.emplace_back(stol(temp_str));
                temp_str = "";
            }
        } else {
            temp_str += s.at(i);
        }
    }
    if (temp_str.empty()) {
        p.emplace_back(0);
    } else {
        p.emplace_back(stol(temp_str));
        temp_str = "";
    }
    reverse(p.begin(), p.end());
    return p;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (powerOfSixty.size() <= 9) {
        powerOfSixty.emplace_back(powerOfSixty.back() * 60);
    }

    string s, s_;
    int n;
    cin >> n;
    while (n--) {
        cin >> s;
        auto temp_vec = parse(s);
        ll sum = 0;
        int length = static_cast<int>(temp_vec.size());
        for (int i = 0; i < length; ++i) {
            sum += powerOfSixty.at(i) * temp_vec.at(i);
        }
        cout << sum << '\n';
    }

    return 0;
}
