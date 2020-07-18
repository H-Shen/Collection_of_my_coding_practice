#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

int main(int argc, char *argv[]) {

    int x, y, z;
    cin >> x >> y >> z;
    if (x > y + z) {
        cout << '+' << '\n';
        return 0;
    }
    if (y > x + z) {
        cout << '-' << '\n';
        return 0;
    }
    int new_x, new_y;
    unordered_set<int> temp;
    for (int i = 0; i <= z; ++i) {
        new_x = i;
        new_y = z - i;
        if (new_x > new_y) {
            temp.insert(1);
        } else if (new_x == new_y) {
            temp.insert(0);
        } else {
            temp.insert(-1);
        }
    }
    if (temp.size() > 1) {
        cout << '?' << '\n';
    } else {
        cout << '0' << '\n';
    }

    return 0;
}