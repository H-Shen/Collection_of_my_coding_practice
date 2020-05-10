#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main() {

    string s;
    getline(cin, s);
    int upper = 0;
    int lower = 0;
    for (const auto &i : s) {
        if (isupper(i)) {
            ++upper;
        } else if (islower(i)) {
            ++lower;
        }
    }
    if (upper <= lower) {
        for (auto &i : s) {
            i = tolower(i);
        }
    } else {
        for (auto &i : s) {
            i = toupper(i);
        }
    }
    cout << s << '\n';

    return 0;
}