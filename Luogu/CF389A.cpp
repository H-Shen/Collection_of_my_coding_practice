#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
    }
}

// Greatest Common Divisor (without recursion)
ll gcd(ll a, ll b) {

    // Case 1:
    if (a < 0) {
        return gcd(-a, b);
    }

    // Case 2:
    if (b < 0) {
        return gcd(a, -b);
    }

    // Case 3:
    if (a == 0 || b == 0) {
        return 0;
    }

    // Case 4:
    long long t;
    while (b > 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;
}

// Greatest Common Divisor of integers in an array
ll gcdOfAnArray(const vector<ll> &A) {

    // Case 1:
    if (A.empty()) {
        throw out_of_range("");
    }

    // Case 2:
    if (A.size() == 1) {
        return abs(A.front());
    }

    // Case 3:
    return accumulate(cbegin(A), cend(A), A.front(), ::gcd);
}

int main() {

    ll n;
    IO::read(n);
    vector<ll> A(n);
    for (auto &i : A) IO::read(i);
    IO::writeln(gcdOfAnArray(A) * n);

    return 0;
}
