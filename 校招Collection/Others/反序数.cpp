// https://www.nowcoder.com/practice/e0d06e79efa44785be5b2ec6e66ba898

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

inline
bool isReverse(const int &n) {
    int temp = 9 * n;
    string n_str = to_string(n);
    string temp_str = to_string(temp);
    reverse(temp_str.begin(), temp_str.end());
    return (n_str == temp_str);
}

int main() {
    for (int i = 1000; i <= 9999; ++i) {
        if (isReverse(i)) {
            cout << i << endl;
        }
    }
    return 0;
}