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
gp_hash_table<int, int, custom_hash> c2w;
set<int> flowers;

int main() {

    int op, w, c, min_c, max_c;
    while (true) {
        IO::read(op);
        switch (op) {
            case 1:
                IO::read(w, c);
                if (c2w.find(c) == c2w.end()) {
                    c2w[c] = w;
                    flowers.insert(c);
                }
                break;
            case 2:
                if (!flowers.empty()) {
                    max_c = *(--flowers.end());
                    flowers.erase(max_c);
                    c2w.erase(max_c);
                }
                break;
            case 3:
                if (!flowers.empty()) {
                    min_c = *flowers.begin();
                    flowers.erase(min_c);
                    c2w.erase(min_c);
                }
                break;
            default:
                ll total_w = 0;
                ll total_c = 0;
                for (const auto &[c_, w_] : c2w) {
                    total_w += w_;
                    total_c += c_;
                }
                IO::write(total_w);
                putchar_unlocked(' ');
                IO::writeln(total_c);
                return 0;
        }
    }

    return 0;
}