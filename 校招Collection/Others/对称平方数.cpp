// https://www.nowcoder.com/practice/1b79865e2f534db0adba84dca10d6bae

#include <iostream>
#include <algorithm>

using namespace std;


inline
bool isPalindrome(const string &A) {
    if (!A.empty()) {
        size_t len = A.size();
        size_t half = (len - 1) / 2;
        for (size_t i = 0; i <= half; ++i) {
            if (A.at(i) != A.at(len - i - 1)) {
                return false;
            }
        }
    }
    return true;
}

int main() {

    for (int i = 1; i < 256; ++i) {
        if (isPalindrome(to_string(i * i))) {
            cout << i << endl;
        }
    }
    return 0;
}
