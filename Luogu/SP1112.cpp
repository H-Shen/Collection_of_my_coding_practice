#include <unordered_map>
#include <chrono>

using namespace std;
using ll = long long;

namespace IO {
    template<typename T>
    inline
    void read(T &t) {
        int n = 0;
        int c = getchar();
        t = 0;
        while (!isdigit(c)) n |= c == '-', c = getchar();
        while (isdigit(c)) t = t * 10 + c - 48, c = getchar();
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
        if (x < 0) x = -x, putchar('-');
        if (x > 9) write(x / 10);
        putchar(x % 10 + 48);
    }

    template<typename T>
    inline void writeln(T x) {
        write(x);
        putchar('\n');
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
    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};

constexpr int MAXN = 10000;

int main() {

    int x = 0, y = 0;
    unordered_map<pair<int, int>, int, custom_hash> A;
    int counter = 0;
    while (x <= MAXN || y <= MAXN) {
        A[make_pair(x, y)] = counter;
        ++x;
        ++y;
        ++counter;
        A[make_pair(x, y)] = counter;
        ++x;
        --y;
        ++counter;
        A[make_pair(x, y)] = counter;
        ++x;
        ++y;
        ++counter;
        A[make_pair(x, y)] = counter;
        --x;
        ++y;
        ++counter;
    }
    int n;
    IO::read(n);
    while (n--) {
        IO::read(x, y);
        if (A.find(make_pair(x, y)) == A.end()) {
            fputs("No Number\n", stdout);
        } else {
            IO::writeln(A[make_pair(x, y)]);
        }
    }

    return 0;
}
