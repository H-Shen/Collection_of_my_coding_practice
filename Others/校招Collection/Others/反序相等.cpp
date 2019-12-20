// https://www.nowcoder.com/practice/092e7068881549bd8985c379208ef3c2

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    for (int i = 1000; i <= 9999; ++i) {
        if (i * 9 >= 10000) {
            break;
        }
        string a = to_string(i);
        reverse(a.begin(), a.end());
        if (a == to_string(9 * i)) {
            cout << i << endl;
        }
    }
    return 0;
}