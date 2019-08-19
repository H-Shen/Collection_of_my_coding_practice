#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int hundred = n / 100;
    int ten = (n - hundred * 100) / 10;
    int one = n % 10;
    string hStr(hundred, 'B');
    string tStr(ten, 'S');
    string oStr;
    for (int i = 1; i <= one; ++i) {
        oStr += to_string(i);
    }
    cout << hStr << tStr << oStr << endl;
    return 0;
}