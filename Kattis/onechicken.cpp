// https://open.kattis.com/problems/onechicken

#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int diff = abs(a - b);

    if (a > b) {
        if (diff > 1) {
            cout << "Dr. Chaz needs " << diff << " more pieces of chicken!";
        } else {
            cout << "Dr. Chaz needs " << diff << " more piece of chicken!";
        }
    } else {
        if (diff > 1) {
            cout << "Dr. Chaz will have " << diff << " pieces of chicken left over!";
        } else {
            cout << "Dr. Chaz will have " << diff << " piece of chicken left over!";
        }
    }

    return 0;
}
