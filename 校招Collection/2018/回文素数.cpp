// https://www.nowcoder.com/practice/4802faa9afb54e458b93ed372e180f5c

#include <bits/stdc++.h>

using namespace std;

inline
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    bool result = true;
    int mid = static_cast<int>(sqrt(static_cast<double>(n))) + 1;
    for (int i = 2; i <= mid; ++i) {
        if (n % i == 0) {
            result = false;
            break;
        }
    }
    return result;
}

inline
bool isPalindrome(const string &s) {
    size_t i = 0;
    size_t j = s.size() - 1;
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
    int l, r;
    int counter = 0;
    cin >> l >> r;
    for (int i = l; i <= r; ++i) {
        if (isPrime(i) && isPalindrome(to_string(i))) {
            ++counter;
        }
    }
    cout << counter << endl;

    return 0;
}