// https://open.kattis.com/problems/hidden
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;

    bool haveAns = true;
    size_t index = 0;
    for (const auto &i : b) {
        if (index == a.size()) {
            break;
        }
        if (i == a.at(index)) {
            ++index;
        } else {
            for (size_t j = index + 1; j < a.size(); ++j) {
                if (a.at(j) == i) {
                    haveAns = false;
                    goto label;
                }
            }
        }
    }

label:
    {
        if (index != a.size()) {
            haveAns = false;
        }
        if (haveAns) {
            cout << "PASS";
        } else {
            cout << "FAIL";
        }
        cout << '\n';
    }

    return 0;
}
