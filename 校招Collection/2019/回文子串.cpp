// https://www.nowcoder.com/practice/003482c395bd41c68082f6adc545a600

#include <iostream>
#include <string>

using namespace std;

inline
bool isPalindrome(const string &s, size_t i, size_t j) {
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

int main() {

    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    int counter = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        for (size_t j = i; j < s.size(); ++j) {
            // from s[i] to s[j]
            if (isPalindrome(s, i, j)) {
                ++counter;
            }
        }
    }
    cout << counter << endl;
    return 0;
}