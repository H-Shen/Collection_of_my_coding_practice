// https://open.kattis.com/problems/alicedigital
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
constexpr int MAXN = 100005;

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
        putchar(x % 10 + 48);
    }
    template <typename T>
    inline void writeln(T x) {
        write(x);
        putchar_unlocked('\n');
    }
}

array<int, MAXN> A;
array<int, MAXN> Sum;

int range_sum(int l, int r) {
    if (l == r) {
        return A.at(l);
    }
    return Sum.at(r) - Sum.at(l) + A.at(l);
}

int main() {

    int t, n, m;
    IO::read(t);
    while (t--) {
        IO::read(n, m);
        // reset A
        for (int i = 1; i <= n; ++i) {  // index from 1
            IO::read(A.at(i));
        }
        // reset Sum
        Sum.at(1) = A.at(1);
        for (int i = 2; i <= n; ++i) {
            Sum.at(i) = Sum.at(i - 1) + A.at(i);
        }
        int max_weight = numeric_limits<int>::min();
        vector<int> positions_of_m;
        for (int i = 1; i <= n; ++i) {
            if (A.at(i) == m) {
                positions_of_m.emplace_back(i);
            }
        }
        int sum_left, sum_right, l, r, current_min;
        for (size_t i = 0; i != positions_of_m.size(); ++i) {
            // check left
            r = positions_of_m.at(i);
            l = positions_of_m.at(i);
            sum_left = range_sum(l, r);
            current_min = A.at(l);
            --l;
            while (true) {
                if (l < 1 || A.at(l) == m) {
                    break;
                }
                current_min = min(current_min, A.at(l));
                if (current_min != m) {
                    break;
                }
                sum_left = range_sum(l, r);
                --l;
            }
            // check right
            l = positions_of_m.at(i);
            r = positions_of_m.at(i);
            sum_right = range_sum(l, r);
            current_min = A.at(r);
            ++r;
            while (true) {
                if (r > n || A.at(r) == m) {
                    break;
                }
                current_min = min(current_min, A.at(r));
                if (current_min != m) {
                    break;
                }
                sum_right = range_sum(l, r);
                ++r;
            }
            max_weight = max(max_weight, sum_right + sum_left - m);
        }
        IO::writeln(max_weight);
    }

    return 0;
}
