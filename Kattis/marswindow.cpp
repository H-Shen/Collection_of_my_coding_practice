// https://open.kattis.com/problems/marswindow
#include <bits/extc++.h>

using namespace std;

const int gap = 26;

unordered_set<int> A;

int main() {
    ios_base::sync_with_stdio(false);

    int year = 2018;
    int month = 3;

    while (year <= 10005) {
        A.insert(year);
        month += gap;
        if (month >= 12) {
            year = year + month / 12;
            month %= 12;
        }

    }

    int n;
    cin >> n;
    if (A.find(n) != A.end()) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
