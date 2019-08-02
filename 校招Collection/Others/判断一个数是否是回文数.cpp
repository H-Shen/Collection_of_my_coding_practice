// https://www.nowcoder.com/practice/edf5475ef713445f9a040cc37a98a4b7

#include <bits/stdc++.h>

using namespace std;

inline
bool isPalindrome(long long A) {
    if (A < 0) {
        return isPalindrome(-A);
    }
    if (A % 10 == 0 && A != 0) {
        return false;
    }
    decltype(A) A_rev{0};
    while (A > A_rev) {
        A_rev = A_rev * 10 + A % 10;
        A /= 10;
    }
    return (A == A_rev || A == A_rev / 10);
}


int main() {

    long long n;
    cin >> n;
    if (isPalindrome(n)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    cout << endl;

    return 0;
}