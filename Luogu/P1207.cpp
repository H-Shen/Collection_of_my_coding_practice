#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

inline static
bool is_palindrome_decimal(int A) {
    if (A < 0) {
        return false;
    }
    if (A % 10 == 0 && A != 0) {
        return false;
    }
    int A_rev{0};
    while (A > A_rev) {
        A_rev = A_rev * 10 + A % 10;
        A /= 10;
    }
    return (A == A_rev || A == A_rev / 10);
}

inline static
bool f(const string &A) {
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

inline static
bool g(int n, const int &base) {
    string temp;
    while (n > 0) {
        temp.push_back(n % base + '0');
        n /= base;
    }
    return f(temp);
}

inline static
bool is_palindrome(int n) {
    int counter = 0;
    if (is_palindrome_decimal(n)) {
        ++counter;
    }
    for (int i = 2; i <= 9; ++i) {
        if (g(n, i)) {
            ++counter;
            if (counter >= 2) {
                return true;
            }
        }
    }
    return false;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, s;
    cin >> n >> s;
    ++s;
    int counter = 0;
    while (counter < n) {
        if (is_palindrome(s)) {
            ++counter;
            cout << s << '\n';
        }
        ++s;
    }

    return 0;
}
