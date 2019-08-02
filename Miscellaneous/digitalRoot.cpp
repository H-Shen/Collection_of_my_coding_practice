#include <bits/stdc++.h>

using namespace std;

/**
 * Calculate the digital root of random integer.
 */
int main() {
    ios_base::sync_with_stdio(false);
    string str;
    while (cin >> str) {
        if (str.front() == '-') {
            str = str.substr(1);
        }
        int num = 0;
        for (size_t i = 0; i != str.length(); i++) {
            num += str[i] - '0';
            if (num > 9)
                num = num / 10 + num % 10;
        }
        cout << num << endl;
    }
    return 0;
}
