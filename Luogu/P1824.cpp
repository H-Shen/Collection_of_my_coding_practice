#include <bits/stdc++.h>

using namespace std;
using ll = long long;

namespace IO {
    template <typename T>
    inline
    void read(T& t) {
        int n = 0; int c = getchar_unlocked(); t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template <typename T, typename... Args>
    inline
    void read(T& t, Args&... args) {
        read(t); read(args...);
    }
    template <typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

inline
bool check(const vector<ll> &A, const int &dist, const int &c) {
    int counter = 1;
    ll sum = 0;
    for (size_t i = 1; i != A.size(); ++i) {
        sum += A.at(i) - A.at(i - 1);
        if (sum >= dist) {
            sum = 0;
            ++counter;
        }
    }
    return counter >= c;
}

int main() {

    int n, c;
    IO::read(n, c);
    vector<ll> A(n);
    for (auto &i : A) IO::read(i);
    sort(A.begin(), A.end());
    ll right = A.back() - A.front();
    ll left = numeric_limits<ll>::max();
    for (int i = 1; i < n; ++i) {
        left = min(left, A.at(i) - A.at(i - 1));
    }
    ll mid;
    while (true) {
        if (left > right) {
            break;
        }
        mid = (left + right) / 2;
        if (check(A, mid, c)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    IO::writeln(right);

    return 0;
}
