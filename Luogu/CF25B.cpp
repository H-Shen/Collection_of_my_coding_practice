#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
string join(const vector<string> &v, const char &ch) {
    string s;
    for (auto p = cbegin(v); p != cend(v); ++p) {
        s.append(*p);
        if (p != cend(v) - 1) {
            s.push_back(ch);
        }
    }
    return s;
}

int main() {

    int n;
    cin >> n;
    string s;
    cin >> s;
    int length = static_cast<int>(s.size());
    if (length % 2 == 0) {
        vector<string> temp;
        for (int i = 0; i < length; i += 2) {
            temp.emplace_back(s.at(i) + string() + s.at(i + 1));
        }
        cout << join(temp, '-') << '\n';
    } else if (length == 3) {
        cout << s << '\n';
    } else {
        cout << s.substr(0, 3) << '-';
        vector<string> temp;
        for (int i = 3; i < length; i += 2) {
            temp.emplace_back(s.at(i) + string() + s.at(i + 1));
        }
        cout << join(temp, '-') << '\n';
    }

    return 0;
}