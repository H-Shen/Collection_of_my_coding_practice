#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

inline static
bool leap_year(const int y) {
    return ((y % 100 != 0 && y % 4 == 0) || (y % 400 == 0));
}

int main() {
    int x, y;
    cin >> x >> y;
    vector<int> A;
    for (int i = x; i <= y; ++i) {
        if (leap_year(i)) {
            A.emplace_back(i);
        }
    }
    cout << A.size() << endl;
    bool firstItem = true;
    for (auto &i : A) {
        if (firstItem) {
            firstItem = false;
        } else {
            cout << " ";
        }
        cout << i;
    }
    cout << endl;
    return 0;
}