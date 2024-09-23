// https://www.nowcoder.com/practice/e11bc3a213d24fc1989b21a7c8b50c3f

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &&i : A) {
        cin >> i;
    }

    if (n <= 2) {
        cout << "Possible" << endl;
        return 0;
    }

    sort(A.begin(), A.end());
    for (int i = 1; i < n - 1; ++i) {
        if (A[i] - A[i - 1] != A[i + 1] - A[i]) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}