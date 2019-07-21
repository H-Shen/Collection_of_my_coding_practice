// https://www.nowcoder.com/practice/1b79865e2f534db0adba84dca10d6bae

#include <iostream>
#include <algorithm>

using namespace std;

inline
bool isPalindrome(const string &s) {
    string s_copy = s;
    reverse(s_copy.begin(), s_copy.end());
    return (s_copy == s);
}

int main() {

    for (int i = 1; i < 256; ++i) {
        if (isPalindrome(to_string(i * i))) {
            cout << i << endl;
        }
    }
    return 0;
}