// https://www.nowcoder.com/practice/dd63c30dfef04770b5813e63f5a2615a

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string n;
    cin >> n;
    bool isNeg = false;
    if (n[0] == '-') {
        isNeg = true;
        n = string(n, 1);
    }
    reverse(n.begin(), n.end());
    if (isNeg) {
        cout << "-";
    }
    cout << n << endl;

    return 0;
}