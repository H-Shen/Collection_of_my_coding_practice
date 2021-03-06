// https://open.kattis.com/problems/egypt
#include <bits/extc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    vector<int> A;
    while (true) {
        vector<int>().swap(A);
        A.resize(3);
        for (auto &&i : A) {
            cin >> i;
        }
        if (A[0] == 0 && A[1] == 0 && A[2] == 0) {
            break;
        }
        sort(A.begin(), A.end());
        if (A[0] * A[0] + A[1] * A[1] == A[2] * A[2]) {
            cout << "right";
        } else {
            cout << "wrong";
        }
        cout << endl;
    }


    return 0;
}
