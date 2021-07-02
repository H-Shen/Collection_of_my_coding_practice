#include <string>
#include <iostream>
#include <cstring>

using namespace std;
using ll = long long;

int f(const string &s) {
    int ans = 0;
    char *p = const_cast<char *>(s.c_str());
    while ((p = strstr(p, "JOI")) != nullptr) {
        ++p;
        ++ans;
    }
    return ans;
}

int g(const string &s) {
    int ans = 0;
    char *p = const_cast<char *>(s.c_str());
    while ((p = strstr(p, "IOI")) != nullptr) {
        ++p;
        ++ans;
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    cout << f(s) << '\n';
    cout << g(s) << '\n';

    return 0;
}