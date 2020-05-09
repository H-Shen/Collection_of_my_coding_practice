#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

namespace IO {
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

struct Interval {
    int start_time;
    int end_time;
};

int main() {

    int n;
    IO::read(n);
    vector<Interval> A(n);
    for (auto &i : A) {
        IO::read(i.start_time, i.end_time);
    }
    sort(A.begin(), A.end(), [](const Interval &lhs, const Interval &rhs){
        if (lhs.end_time == rhs.end_time) {
            return (lhs.start_time < rhs.start_time);
        }
        return (lhs.end_time < rhs.end_time);
    });
    int counter = 0;
    int current_end_time = -1;
    for (const auto &i : A) {
        if (i.start_time >= current_end_time) {
            ++counter;
            current_end_time = i.end_time;
        }
    }
    IO::writeln(counter);

    return 0;
}
