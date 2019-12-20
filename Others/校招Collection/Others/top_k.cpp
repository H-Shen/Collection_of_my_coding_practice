// https://ac.nowcoder.com/acm/problem/14838

#include <bits/stdc++.h>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &i : A) {
        cin >> i;
    }

    sort(A.begin(), A.end(), greater<>());
    for (size_t i = 0; i != 3; ++i) {
        cout << A.at(i) << endl;
    }

    return 0;
}