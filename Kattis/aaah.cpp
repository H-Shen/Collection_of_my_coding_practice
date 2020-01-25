// https://open.kattis.com/problems/aaah

#include <bits/extc++.h>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int cnt_a = 0, cnt_b = 0;

    for (const auto &ch : a) {
        if (ch == 'a') {
            ++cnt_a;
        }
    }
    for (const auto &ch : b) {
        if (ch == 'a') {
            ++cnt_b;
        }
    }

    if (cnt_a < cnt_b) {
        cout << "no";
    } else {
        cout << "go";
    }
    cout << endl;
    return 0;
}
