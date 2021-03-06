// https://open.kattis.com/problems/fibonaccicycles
//
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

std::integer_sequence<int,
        3, 2, 4, 3, 2, 6, 4, 3, 3, 2, 4, 5, 6, 5, 4, 7, 3, 2, 6, 6,
        8, 3, 10, 4, 5, 5, 4, 4, 8, 3, 2, 2, 7, 13, 10, 9, 6, 5,
        11, 7, 6, 3, 6, 5, 3, 5, 10, 8, 4, 8, 3, 2, 15, 8, 5, 4,
        12, 10, 16, 13, 4, 5, 8, 7, 6, 16, 7, 7, 13, 2, 10, 6, 17,
        5, 6, 2, 4, 18, 7, 5, 3, 26, 4, 8, 3, 2, 6, 9, 9, 6, 5, 4,
        14, 7, 10, 2, 3, 6, 21, 13, 8, 11, 7, 9, 7, 5, 11, 25, 8,
        9, 5, 17, 4, 3, 10, 3, 10, 9, 13, 4, 13, 7, 4, 2, 9, 8, 20,
        19, 7, 6, 6, 6, 16, 7, 5, 14, 7, 4, 13, 3, 2, 8, 10, 2, 3,
        3, 15, 16, 8, 22, 2, 9, 6, 4, 24, 31, 18, 8, 7, 9, 13, 14,
        3, 18, 3, 14, 22, 4, 8, 2, 13, 24, 4, 30, 6, 24, 9, 9, 13,
        5, 6, 13, 5, 9, 4, 3, 12, 9, 5, 17, 8, 37, 2, 42, 21, 2, 6,
        8, 24, 16, 13, 8, 6, 18, 25, 22, 7, 12, 9, 6, 7, 21, 15,
        24, 11, 6, 25, 24, 6, 6, 18, 16, 22, 5, 17, 5, 4, 19, 3, 2,
        4, 11, 3, 14, 10, 29, 9, 2, 13, 3, 4, 5, 13, 9, 3, 4, 8,
        13, 12, 11, 22, 18, 4, 8, 4, 9, 15, 8, 7, 4, 4, 41, 6, 34,
        6, 10, 16, 3, 7, 13, 16, 25, 14, 19, 22, 19, 16, 2, 13, 11,
        14, 2, 12, 10, 15, 21, 10, 6, 7, 25, 33, 15, 3, 18, 19, 7,
        16, 21, 24, 5, 18, 13, 2, 13, 9, 19, 6, 25, 4, 35, 13, 50,
        31, 9, 12, 13, 13, 2, 7, 5, 9, 16, 5, 20, 31, 26, 3, 14,
        18, 18, 13, 33, 14, 17, 22, 20, 4, 18, 6, 12, 2, 8, 13, 15,
        24, 7, 4, 14, 30, 3, 8, 3, 16, 24, 7, 9, 22, 13, 13, 8, 6,
        14, 6, 6, 13, 11, 5, 5, 3, 17, 4, 7, 3, 2, 17, 12, 9, 3, 5,
        53, 10, 2, 20, 9, 32, 17, 37, 5, 21, 10, 21, 41, 7, 18, 6,
        18, 4, 6, 24, 33, 16, 8, 13, 13, 12, 13, 34, 54, 18, 18,
        25, 20, 22, 13, 7, 18, 12, 16, 6, 19, 6, 11, 23, 8, 21, 5,
        11, 22, 27, 6, 11, 15, 6, 12, 25, 7, 24, 64, 28, 9, 6, 9,
        18, 11, 16, 16, 22, 10, 24, 18, 15, 20, 4, 5, 2, 5, 19, 34,
        19, 20, 6, 42, 4, 4, 11, 18, 13, 8, 14, 9, 10, 11, 12, 7,
        6, 13, 2, 32, 13, 33, 16, 7, 4, 14, 5, 6, 11, 14, 9, 4, 3,
        10, 4, 7, 8, 14, 13, 10, 12, 33, 11, 24, 22, 13, 18, 18, 4,
        21, 8, 30, 25, 34, 9, 40, 15, 10, 8, 13, 7, 10, 4, 17, 25,
        57, 37, 2, 6, 12, 34, 16, 6, 15, 10, 7, 4, 22, 3, 17, 13,
        3, 17, 5, 14, 27, 25, 25, 67, 12, 9, 4, 22, 29, 19, 9, 16,
        29, 2, 7, 5, 30, 7, 33, 12, 19, 42, 9, 28, 3, 10, 19, 5,
        17, 21, 7, 8, 14, 6, 49, 10, 32, 37, 21, 40, 21, 33, 55,
        15, 7, 25, 101, 19, 46, 7, 9, 16, 6, 21, 41, 24, 7, 5, 22,
        18, 4, 2, 3, 2, 8, 13, 9, 34, 8, 15, 18, 18, 12, 25, 29, 4,
        5, 43, 21, 13, 22, 50, 10, 31, 19, 9, 44, 12, 16, 13, 6,
        13, 13, 10, 22, 13, 6, 15, 42, 5, 11, 16, 13, 5, 18, 20, 6,
        31, 4, 26, 54, 23, 24, 14, 28, 16, 53, 18, 8, 35, 30, 33,
        15, 64, 30, 22, 9, 22, 28, 20, 57, 4, 3, 18, 25, 41, 4, 12,
        47, 2, 54, 3, 29, 9, 8, 15, 43, 13, 18, 7, 12, 4, 11, 28,
        13, 30, 3, 3, 9, 2, 3, 39, 13, 16, 16, 4, 29, 29, 8, 9, 11,
        22, 9, 12, 6, 13, 49, 8, 55, 42, 17, 4, 11, 25, 21, 24, 3,
        13, 3, 51, 9, 22, 23, 27, 23, 19, 14, 40, 33, 2, 53, 7, 39,
        12, 9, 24, 45, 17, 81, 12, 14, 5, 69, 3, 18, 5, 93, 51, 53,
        10, 9, 24, 14, 13, 15, 38, 9, 49, 7, 9, 9, 4, 8, 47, 10,
        18, 32, 10, 3, 15, 30, 52, 34, 7, 39, 18, 38, 6, 15, 18,
        12, 4, 3, 6, 5, 40, 10, 43, 31, 16, 25, 13, 26, 13, 29, 13,
        9, 12, 13, 3, 3, 34, 3, 54, 33, 16, 14, 18, 14, 40, 21, 4,
        88, 22, 41, 13, 25, 7, 9, 10, 73, 12, 13, 16, 21, 25, 6,
        19, 11, 6, 4, 11, 34, 13, 13, 8, 21, 22, 10, 5, 50, 11, 6,
        12, 12, 10, 21, 6, 2, 5, 20, 13, 6, 6, 28, 18, 19, 23, 12,
        14, 57, 6, 5, 64, 33, 28, 41, 9, 4, 25, 25, 54, 8, 60, 55,
        20, 43, 30, 6, 16, 31, 20, 7, 10, 22, 24, 25, 18, 13, 19,
        34, 12, 14, 31, 12, 21, 32, 2, 31, 34, 13, 19, 29, 34, 36,
        5, 19, 16, 20, 6, 27, 42, 39, 14, 20, 4, 25, 9, 17, 18, 39,
        13, 2, 8, 37, 9, 22, 45, 5, 16, 46, 21, 5, 12, 34, 15, 13,
        9, 8, 13, 17, 18, 12, 32, 54, 13, 14, 33, 15, 16, 14, 7,
        41, 18, 34, 45, 12, 5, 14, 6, 21, 28, 10, 49, 5, 37, 24, 4,
        15, 3, 2, 10, 14, 4, 21, 7, 25, 8, 33, 10, 3, 13, 78, 12,
        15, 24> p;

template<typename T, T... elements>
constexpr T get(integer_sequence<T, elements...>, size_t i) {
    constexpr T temp_array[] = {elements...};
    return temp_array[i];
}

int n, t;

int main() {
    IO::read(t);
    while (t--) {
        IO::read(n);
        IO::writeln(get(p, n - 2));
    }
    return 0;
}
