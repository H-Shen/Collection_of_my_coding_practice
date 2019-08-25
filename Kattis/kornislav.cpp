// https://open.kattis.com/problems/kornislav
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> A(4);
    for (auto &&i : A) {
        cin >> i;
    }
    sort(A.begin(), A.end());
    cout << A.at(0) * A.at(2) << endl;

    return 0;
}
