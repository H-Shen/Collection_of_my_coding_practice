// https://open.kattis.com/problems/countingclauses
//
#include <bits/stdc++.h>

using namespace std;

int main() {

    int m;
    int n;
    cin >> m >> n;
    int temp = m * n;
    int val;
    while (temp--) {
        cin >> val;
    }
    if (m >= 8) {
        cout << "satisfactory";
    } else {
        cout << "unsatisfactory";
    }
    cout << endl;
    
    return 0;
}
