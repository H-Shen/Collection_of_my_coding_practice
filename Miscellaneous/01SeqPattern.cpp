#include<bits/stdc++.h>

using namespace std;

inline static
deque<char> convertToBaseTwo(long long n) {
    deque<char> temp;
    bool isNegative = false;
    if (n < 0) {
        isNegative = true;
        n = -n;
    }
    while (n > 0) {
        if (n % 2 == 0) {
            temp.push_front('0');
        } else {
            temp.push_front('1');
        }
        n /= 2;
    }
    if (isNegative) {
        temp.push_front('-');
    }
    return temp;
}

// For seq: 1, 2, 11, 12, 21, 22, 111, 112, 121, 122, 211, 212, 221, 222 ..., obtain the nth item
// Reference: https://oeis.org/A007931
inline static
string f(long long n) {
    assert(n >= 0);
    deque<char> temp = convertToBaseTwo(n);
    if (n > 0) {
        temp.pop_front();
        for (auto &i : temp) {
            if (i == '0') {
                i = '1';
            } else {
                i = '2';
            }
        }
    }
    return string(temp.begin(), temp.end());
}

int main() {
    for (long long i = 0; i <= 20; ++i) {
        cout << f(i) << endl;
    }
    return 0;
}
