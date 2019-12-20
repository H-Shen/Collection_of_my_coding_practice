// https://www.nowcoder.com/practice/b8e21f5816874425836b7d32011f46b0

#include <bits/stdc++.h>

using namespace std;

int main() {

    int x;
    cin >> x;
    if (x % 5 == 0) {
        cout << x / 5 << endl;
    } else {
        cout << x / 5 + 1 << endl;
    }

    return 0;
}