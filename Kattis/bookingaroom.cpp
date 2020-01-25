// https://open.kattis.com/problems/bookingaroom
//
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int r, n, roomNumber;
    cin >> r >> n;
    vector<int> A(r + 1);
    while (n--) {
        cin >> roomNumber;
        A[roomNumber] = 1;
    }
    for (int i = 1; i <= r; ++i) {
        if (A[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "too late" << endl;

    return 0;
}
