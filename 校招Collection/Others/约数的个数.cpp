// https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6

#include <bits/stdc++.h>

using namespace std;

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<int, int, custom_hash> save;

int main() {

    int n, val, sum, temp;
    IO::read(n);
    while (n--) {
        IO::read(val);
        if (save.find(val) != save.end()) {
            IO::writeln(save[val]);
        } else {
            sum = 1;
            for (int i = 2; i * i <= val; ++i) {
                temp = 0;
                while (val % i == 0) {
                    ++temp;
                    val /= i;
                }
                if (temp > 0) {
                    ++temp;
                    sum *= temp;
                }
            }
            if (val > 1) {
                sum *= 2;
            }
            save[val] = sum;
            IO::writeln(sum);
        }
    }
    
    return 0;
}
