#include <bits/extc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

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

    int n, l, r;
    IO::read(n);
    vector<int> A(n);
    for (auto &i : A) IO::read(i);
    IO::read(l, r);
    vector<int> B;
    int counter = 0;
    int result = 0;
    int large_elements = 0;
    // handle > r
    for (const auto &i : A) {
        if (i <= r) {
            B.emplace_back(i);
        } else {
            counter += i - r;
            ++large_elements;
        }
    }
    bool exitLoop = false;
    for (auto &i : B) {
        while (i < l) {
            if (counter > 0) {
                --counter;
                ++i;
                ++result;
            } else {
                exitLoop = true;
                break;
            }
        }
        if (exitLoop) break;
    }
    exitLoop = false;
    for (auto &i : B) {
        while (i < r) {
            if (counter > 0) {
                --counter;
                ++i;
                ++result;
            } else {
                exitLoop = true;
                break;
            }
        }
        if (exitLoop) break;
    }
    if (counter > 0) {
        IO::writeln(-1);
        return 0;
    }

    vector<int> temp(large_elements, r);
    vector<int>().swap(A);
    copy(B.begin(), B.end(), back_inserter(A));
    copy(temp.begin(), temp.end(), back_inserter(A));
    counter = 0;
    vector<int>().swap(B);
    // handle < l
    for (const auto &i : A) {
        if (i >= l) {
            B.emplace_back(i);
        } else {
            counter += l - i;
        }
    }
    exitLoop = false;
    for (auto &i : B) {
        while (i > r) {
            if (counter > 0) {
                --counter;
                --i;
                ++result;
            } else {
                exitLoop = true;
                break;
            }
        }
        if (exitLoop) break;
    }
    exitLoop = false;
    for (auto &i : B) {
        while (i > l) {
            if (counter > 0) {
                --counter;
                --i;
                ++result;
            } else {
                exitLoop = true;
                break;
            }
        }
        if (exitLoop) break;
    }
    if (counter > 0) {
        IO::writeln(-1);
        return 0;
    }
    IO::writeln(result);

    return 0;
}