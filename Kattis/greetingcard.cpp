// https://open.kattis.com/problems/greetingcard
//
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;
using ll = long long;

constexpr ll MAX = 2147483648;
constexpr int STEPS = 4;
inline const ll di[] = {0, 1118, 1680, 2018};
inline const ll dj[] = {2018, 1680, 1118, 0};

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    // For a pair of integers
    size_t operator()(pair<uint64_t, uint64_t> x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.first + FIXED_RANDOM) ^
               (splitmix64(x.second + FIXED_RANDOM) >> 1);
    }
};
gp_hash_table<pair<ll, ll>, null_type, custom_hash> hash_set_of_points, hash_set_of_lines;

inline
void insert_a_line(pair<ll, ll> a, pair<ll, ll> b) {
    if (a == b) {
        return;
    }
    ll hash_of_a = MAX * a.first + a.second;
    ll hash_of_b = MAX * b.first + b.second;
    if (hash_of_a > hash_of_b) {    // do this to avoid duplicated lines in the hash set
        swap(hash_of_a, hash_of_b);
    }
    hash_set_of_lines.insert(make_pair(hash_of_a, hash_of_b));
}

int main(int argc, char *argv[]) {

    int n;
    IO::read(n);
    vector<pair<ll, ll> > A(n);
    for (auto &i : A) {
        IO::read(i.first, i.second);
        hash_set_of_points.insert(i);
    }
    pair<ll, ll> temp_pair;
    for (const auto &i : A) {
        for (int step = 0; step < STEPS; ++step) {
            // Case 1:
            temp_pair.first = i.first - di[step];
            temp_pair.second = i.second - dj[step];
            if (hash_set_of_points.find(temp_pair) != hash_set_of_points.end()) {
                insert_a_line(i, temp_pair);
            }
            // Case 2:
            temp_pair.first = i.first - di[step];
            temp_pair.second = i.second + dj[step];
            if (hash_set_of_points.find(temp_pair) != hash_set_of_points.end()) {
                insert_a_line(i, temp_pair);
            }
            // Case 3:
            temp_pair.first = i.first + di[step];
            temp_pair.second = i.second - dj[step];
            if (hash_set_of_points.find(temp_pair) != hash_set_of_points.end()) {
                insert_a_line(i, temp_pair);
            }
            // Case 4:
            temp_pair.first = i.first + di[step];
            temp_pair.second = i.second + dj[step];
            if (hash_set_of_points.find(temp_pair) != hash_set_of_points.end()) {
                insert_a_line(i, temp_pair);
            }
        }
    }
    IO::writeln(hash_set_of_lines.size());

    return 0;
}
