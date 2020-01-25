// https://open.kattis.com/problems/ummcode
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline static
bool is_umm_code(const string &s) {
    for (const char &ch : s) {
        if (ch != 'u' && ch != 'm') {
            if (isspace(ch) || isalnum(ch)) {
                return false;
            }
        }
    }
    return true;
}

inline static
string filter(const string &s) {
    string ret;
    for (const char &ch : s) {
        if (ch == 'u' || ch == 'm') {
            ret += ch;
        }
    }
    return ret;
}

unordered_map<string, char> A;

void pre() {
    for (int i = 0; i <= 127; ++i) {
        bitset<7> temp(i);
        A[temp.to_string()] = static_cast<char>(i);
    }
}

int main() {

    pre();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    string s_;
    while (cin >> s) {
        if (is_umm_code(s)) {
            s_ += filter(s);
        }
    }
    for (auto &i : s_) {
        if (i == 'u') {
            i = '1';
        } else {
            i = '0';
        }
    }
    int n = static_cast<int>(s_.size());
    s = "";
    int counter = 0;
    for (int i = 0; i < n; ++i) {
        s.push_back(s_.at(i));
        ++counter;
        if (counter == 7) {
            cout << A[s];
            s = "";
            counter = 0;
        }
    }
    cout << '\n';

    return 0;
}
