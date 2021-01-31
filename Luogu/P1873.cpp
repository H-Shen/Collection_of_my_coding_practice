#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    bool can_read(T &t) {
        int n = 0;
        int ch = getchar_unlocked();
        while (!isdigit(ch)) {
            if (ch == EOF) return false;
            n |= ch == '-';
            ch = getchar_unlocked();
        }
        t = 0;
        while (isdigit(ch)) {
            t = t * 10 + ch - 48;
            ch = getchar_unlocked();
        }
        if (n) t = -t;
        return true;
    }
    template<typename T, typename... Args>
    inline
    bool can_read(T &t, Args &... args) {
        return can_read(t) && can_read(args...);
    }
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar_unlocked();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar_unlocked();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar_unlocked();
        if (n) t = -t;
    }
    template<typename T, typename... Args>
    inline
    void read(T &t, Args &... args) {
        read(t);
        read(args...);
    }
    template<typename T>
    inline void write(T x) {
        if (x < 0) x = -x, putchar_unlocked('-');
        if (x > 9) write(x / 10);
        putchar_unlocked(x % 10 + 48);
    }
    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

int n;
ll m;
vector<ll> A, prefixSum;

ll range_sum(int l, int r) {
    if (l == r) {
        return A[l];
    }
    if (l == 0) {
        return prefixSum[r];
    }
    return prefixSum[r] - prefixSum[l - 1];
}

bool f(ll h) {
    if (h > A.back()) {
        return false;
    }
    int l_index = lower_bound(A.begin(), A.end(), h) - A.begin();
    int r_index = n - 1;
    return range_sum(l_index, r_index) - (r_index - l_index + 1) * h >= m;
}

int main() {

    IO::read(n, m);
    A.resize(n);
    for (auto &i : A) {
        IO::read(i);
    }
    sort(A.begin(), A.end());
    prefixSum.resize(n);
    partial_sum(A.begin(), A.end(), prefixSum.begin());

    // binary_search
    ll lower_bound_value = 0;
    ll upper_bound_value = A.back();
    while (lower_bound_value <= upper_bound_value) {
        ll mid = (lower_bound_value + upper_bound_value) / 2;
        if (f(mid)) {
            lower_bound_value = mid + 1;
        } else {
            upper_bound_value = mid - 1;
        }
    }
    IO::writeln(upper_bound_value);
    return 0;
}