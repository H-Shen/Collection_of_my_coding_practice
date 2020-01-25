// https://open.kattis.com/problems/sretan
//
#include <bits/extc++.h>

using namespace std;

void getNumber(int n) {

    if (n == 1) {
        cout << "4" << endl;
        return;
    }
    if (n == 2) {
        cout << "7" << endl;
        return;
    }

    bitset<64> A(n + 1);
    string s = A.to_string();
    deque<char> temp(s.begin(), s.end());
    while (temp.size() > 1 && temp.front() == '0') {
        temp.pop_front();
    }
    // remove initial 1
    temp.pop_front();
    // add 1 to all remaining digits
    for (auto &i : temp) {
        i += 1;
    }
    for (const char &i : temp) {
        if (i == '2') {
            cout << '7';
        } else {
            cout << '4';
        }
    }
    cout << endl;
}

int main() {
    int k;
    cin >> k;
    getNumber(k);
}
