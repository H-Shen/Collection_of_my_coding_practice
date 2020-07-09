#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

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
    vector<int> A(n);
    for (auto &i : A) IO::read(i);
    int max_gap = 0;
    if (A.size() > 1) {
        int start_index = 0;
        int end_index = 0;
        for (int i = 1; i < n; ++i) {
            if (A.at(i) > A.at(i - 1)) {
                ++end_index;
            } else {
                if (start_index != end_index) {
                    max_gap = max(max_gap, A.at(end_index) - A.at(start_index));
                }
                start_index = i;
                end_index = i;
            }
        }
        if (start_index != end_index) {
            max_gap = max(max_gap, A.at(end_index) - A.at(start_index));
        }
    }
    IO::writeln(max_gap);

    return 0;
}
