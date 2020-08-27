#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll [[maybe_unused]] = long long;
using pii [[maybe_unused]] = pair<int, int>;

inline
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

inline 
const string_view UPPERCASE = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<string> A;

inline
char solve(const char &k_ch, const char &c_ch) {
    for (char ch = 'A';; ++ch) {
        if (A.at(k_ch - 'A').at(ch - 'A') == c_ch) {
            return ch;
        }
    }
}

int main() {

    fast_io();
    deque<char> temp(UPPERCASE.begin(), UPPERCASE.end());
    for (int i = 0; i < 26; ++i) {
        A.emplace_back(temp.begin(), temp.end());
        temp.emplace_back(temp.front());
        temp.pop_front();
    }
    string k, c, m;
    cin >> k >> c;
    string k_(k);
    while (k_.size() < c.size()) {
        k_.append(k);
    }
    while (k_.size() > c.size()) {
        k_.pop_back();
    }
    transform(k_.begin(), k_.end(), k_.begin(), ::toupper);
    string c_copy(c);
    transform(c_copy.begin(), c_copy.end(), c_copy.begin(), ::toupper);
    for (size_t i = 0; i != c_copy.size(); ++i) {
        c_copy.at(i) = solve(k_.at(i), c_copy.at(i));
    }
    for (size_t i = 0; i != c_copy.size(); ++i) {
        if (isupper(c.at(i))) {
            c_copy.at(i) = toupper(c_copy.at(i));
        } else {
            c_copy.at(i) = tolower(c_copy.at(i));
        }
    }
    cout << c_copy << '\n';
    return 0;
}
