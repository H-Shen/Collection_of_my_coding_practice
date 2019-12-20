#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, tmp;
    cin >> n;
    bool haveAns = false;
    for (int f = 0; f <= 99; ++f) {
        tmp = 98 * f - n;
        if (tmp >= 0 && tmp % 199 == 0) {
            haveAns = true;
            cout << (tmp / 199) << "." << f << endl;
            break;
        }
    }
    if (!haveAns) {
        cout << "No Solution" << endl;
    }
    return 0;
}