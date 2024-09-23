// https://www.nowcoder.com/practice/0177394fb25b42b48657bc2b1c6f9fcc

#include <bits/stdc++.h>

using namespace std;
constexpr int MAXN = 205;

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

unordered_map<int, unordered_set<int, custom_hash>, custom_hash> book2ids;
vector<unordered_set<int, custom_hash> > id2friends(MAXN);

int main() {

    int n, m, bookId;
    IO::read(n, m);
    for (int i = 1; i <= n; ++i) {
        IO::read(bookId);
        book2ids[bookId].insert(i);
    }

    for (const auto &i : book2ids) {
        vector<int> temp_vec(i.second.begin(), i.second.end());
        if (temp_vec.size() > 1) {
            int length = static_cast<int>(temp_vec.size());
            for (int j = 0; j < length - 1; ++j) {
                for (int k = j + 1; k < length; ++k) {
                    id2friends.at(temp_vec.at(j)).insert(temp_vec.at(k));
                    id2friends.at(temp_vec.at(k)).insert(temp_vec.at(j));
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (id2friends[i].empty()) {
            puts("BeiJu");
        } else {
            IO::writeln(id2friends[i].size());
        }
    }
    return 0;
}
