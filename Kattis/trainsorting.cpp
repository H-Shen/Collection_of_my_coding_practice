// https://open.kattis.com/problems/trainsorting
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using pii = pair<int, int>;

int lengthOfLIS(const deque<pii> &A) {
    if (A.empty()) {
        return 0;
    }
    vector<pii> dp = {{numeric_limits<int>::min(), numeric_limits<int>::min()}};
    for (const auto &i : A) {
        auto iter = lower_bound(dp.begin(), dp.end(), i);
        if (iter == dp.end()) {
            dp.emplace_back(i);
        } else {
            dp.at(iter - dp.begin()) = i;
        }
    }
    return (int)dp.size() - 1;
}

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

int main() {

    int n;
    IO::read(n);
    deque<int> A(n);
    for (auto &i : A) IO::read(i);
    int result = 0;
    while (!A.empty()) {
        int front = A.front();
        A.pop_front();
        deque<pii> deque1, deque2;
        for (const auto &i : A) {
            if (i > front) {
                deque1.emplace_back(i, (int)deque1.size());
            }
        }
        for (const auto &i : A) {
            if (i < front) {
                deque2.emplace_back(-i, -(int)deque2.size());
            }
        }
        result = max(result, lengthOfLIS(deque1) + lengthOfLIS(deque2) + 1);
    }
    IO::writeln(result);

    return 0;
}
