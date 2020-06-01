#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main(int argc, char *argv[]) {

    vector<vector<char> > vec;
    string s;
    for (int i = 0; i < 3; ++i) {
        cin >> s;
        vec.emplace_back(s.begin(), s.end());
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (vec.at(i).at(j) != vec.at(2 - i).at(2 - j)) {
                cout << "NO\n";
                return 0;
            }
        }
    }
    cout << "YES\n";
    return 0;
}
