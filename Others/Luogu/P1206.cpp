#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 300;

inline static
string convert(int n, int base) {
    if (base == 10) {
        return to_string(n);
    }
    string result;
    int temp;
    while (n > 0) {
        temp = n % base;
        if (temp > 9) {
            result.push_back(temp - 10 + 'A');
        } else {
            result.push_back(temp + '0');
        }
        n /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

inline static
bool is_palindrome(const string &s) {
    string s_rev(s);
    reverse(s_rev.begin(), s_rev.end());
    return s_rev == s;
}

int main() {

    int base;
    string a, b;
    scanf("%d", &base);
    for (int i = 1; i <= MAXN; ++i) {
        b = convert(i * i, base);
        if (is_palindrome(b)) {
            a = convert(i, base);
            printf("%s %s\n", a.c_str(), b.c_str());
        }
    }

    return 0;
}
