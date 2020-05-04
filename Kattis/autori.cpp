// https://open.kattis.com/problems/autori
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
vector<string> splitByChar(string s, const char &delim) {
    vector<string> res;
    istringstream f(s);
    string temp;
    while (getline(f, s, delim)) {
        res.emplace_back(s);
    }
    return res;
}

int main() {
    string s;
    getline(cin, s);
    auto p = splitByChar(s, '-');
    string result;
    for (const auto &i : p) {
        result.push_back(i.front());
    }
    cout << result << endl;
    return 0;
}
