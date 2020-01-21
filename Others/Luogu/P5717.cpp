#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> A(3);
    for (auto &it : A) cin >> it;
    sort(A.begin(), A.end());

    if (A[0] + A[1] <= A[2] || A[0] <= 0 || A[1] <= 0 || A[2] <= 0) {
        cout << "Not triangle\n";
    }
    else {

        if (A[0] * A[0] + A[1] * A[1] == A[2] * A[2]) {
            cout << "Right triangle\n";
        } else if (A[0] * A[0] + A[1] * A[1] - A[2] * A[2] < 0 ||
                   A[0] * A[0] + A[2] * A[2] - A[1] * A[1] < 0 ||
                   A[1] * A[1] + A[2] * A[2] - A[0] * A[0] < 0) {
            cout << "Obtuse triangle\n";
        } else {
            cout << "Acute triangle\n";
        }
        if (A[0] == A[1] || A[1] == A[2] || A[0] == A[2]) {
            cout << "Isosceles triangle\n";
        }
        if (A[0] == A[1] && A[1] == A[2]) {
            cout << "Equilateral triangle\n";
        }
    }

    return 0;
}