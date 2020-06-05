#include <bits/extc++.h>

using namespace std;

int main() {

    int n;
    cin >> n;
    ++n;
    string s;
    while (true) {
        s = to_string(n);
        if (unordered_set<char>(s.begin(), s.end()).size() == s.size()) {
            cout << n << '\n';
            break;
        }
        ++n;
    }

    return 0;
}

