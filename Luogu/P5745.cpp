#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
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

vector<ll> A;
vector<ll> prefixSum;
// 1 <= i <= A.size()
ll range_sum(int left, int right) {
    if (left == right) {
        return A.at(left - 1);
    }
    if (left == 1) {
        return prefixSum.at(right - 1);
    }
    return prefixSum.at(right - 1) - prefixSum.at(left - 2);
}

int main() {

    int n;
    ll m;
    IO::read(n, m);
    A.resize(n);
    prefixSum.resize(n);
    for (auto &i : A) {
        IO::read(i);
    }
    partial_sum(A.begin(), A.end(), prefixSum.begin());
    vector<tuple<int, int, ll> > temp_vec;
    int left = 1;
    int right = 1;
    while (right <= n) {
        ll temp = range_sum(left, right);
        if (temp <= m) {
            temp_vec.emplace_back(make_tuple(left, right, temp));
            ++right;
        } else {
            ++left;
        }
    }
    if (left > right) {
        return 0;
    }
    
    ll max_range_sum = -1;
    for (const auto &[k, v, w] : temp_vec) {
        max_range_sum = max(w, max_range_sum);
    }
    for (const auto &[k, v, w] : temp_vec) {
        if (w == max_range_sum) {
            IO::write(k);
            putchar_unlocked(' ');
            IO::write(v);
            putchar_unlocked(' ');
            IO::writeln(w);
            break;
        }
    }

    return 0;
}